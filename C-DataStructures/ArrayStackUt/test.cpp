#include "pch.h"

class ArrayStackTest : public ::testing::Test
{
protected:
    ArrayStack* m_as{ nullptr };

    void SetUp() override
    {
        assert(arrayStackInit(&m_as));
    }

    void TearDown() override
    {
        arrayStackFree(m_as);
    }
};

TEST_F(ArrayStackTest, arrayStack_init_alreadyInitialized_expectFalse)
{
    EXPECT_FALSE(arrayStackInit(&m_as));
}

TEST(ArrayStackInitTest, arrayStack_init_nomimal_expectTrue)
{
    ArrayStack* as{ nullptr };

    EXPECT_TRUE(arrayStackInit(&as));

    ASSERT_TRUE(arrayStackFree(as));
}

TEST(ArrayStackPushTest, arrayStack_push_notInit_expectFalse)
{
    ArrayStack* as{ nullptr };

    EXPECT_FALSE(arrayStackPush(as, 1));
}

TEST_F(ArrayStackTest, arrayStack_push_stackOverflowSimple_expectFalse)
{
    m_as->m_size = C_MAX_STACK_SIZE + 1;

    EXPECT_FALSE(arrayStackPush(m_as, 1));

    m_as->m_size = 0;
}

TEST_F(ArrayStackTest, arrayStack_push_stackOverflowLoop_expectFalse)
{
    for (uint32_t i{ 0 }; i < C_MAX_STACK_SIZE - 1; i++)
    {
        ASSERT_TRUE(arrayStackPush(m_as, i));
    }

    EXPECT_FALSE(arrayStackPush(m_as, 1));
}

TEST_F(ArrayStackTest, arrayStack_push_arrayElementNull_expectFalse)
{
    free(m_as->m_array[m_as->m_size]);
    m_as->m_array[m_as->m_size] = NULL;

    EXPECT_FALSE(arrayStackPush(m_as, 1));
}

TEST_F(ArrayStackTest, arrayStack_push_nominal_expectTrue)
{
    constexpr int32_t testValue{ 1 };

    ASSERT_TRUE(arrayStackPush(m_as, testValue));

    const auto res = m_as->m_array[m_as->m_size];

    ASSERT_EQ(*res, testValue);
}

TEST_F(ArrayStackTest, arrayStack_pop_notInit_expectFalse)
{
    EXPECT_FALSE(arrayStackPop(nullptr));
}

TEST_F(ArrayStackTest, arrayStack_pop_arrayNotInit_expectFalse)
{
    const auto n = new ArrayStack;

    n->m_array = nullptr;

    EXPECT_FALSE(arrayStackPop(n));

    delete n;
}

TEST_F(ArrayStackTest, arrayStack_pop_stackEmpty_expectFalse)
{
    EXPECT_FALSE(arrayStackPop(m_as));
}

TEST_F(ArrayStackTest, arrayStack_pop_nominal_expectFalse)
{
    ASSERT_TRUE(arrayStackPush(m_as, 1));

    EXPECT_TRUE(arrayStackPop(m_as));
}

TEST_F(ArrayStackTest, arrayStack_top_notInit_expectFalse)
{
    EXPECT_FALSE(arrayStackTop(nullptr, nullptr));
}

TEST_F(ArrayStackTest, arrayStack_top_arrayNotInit_expectFalse)
{
    const auto n = new ArrayStack;

    n->m_array = nullptr;

    EXPECT_FALSE(arrayStackTop(n, nullptr));

    delete n;
}

TEST_F(ArrayStackTest, arrayStack_top_stackEmpty_expectFalse)
{
    EXPECT_FALSE(arrayStackTop(m_as, nullptr));
}

TEST_F(ArrayStackTest, arrayStack_top_valueNull, expectFalse)
{
    ASSERT_TRUE(arrayStackPush(m_as, 1));

    EXPECT_FALSE(arrayStackTop(m_as, nullptr));
}

TEST_F(ArrayStackTest, arrayStack_top_nominal_expectTrue)
{
    constexpr int32_t expectValue{ 1 };
    int32_t testValue{ 0 };

    ASSERT_TRUE(arrayStackPush(m_as, expectValue));

    EXPECT_TRUE(arrayStackTop(m_as, &testValue));

    ASSERT_EQ(expectValue, testValue);
}

TEST_F(ArrayStackTest, arrayStack_size_failCases_expectFalse)
{
    const auto n = new ArrayStack;
    n->m_array = nullptr;

    EXPECT_FALSE(arrayStackSize(nullptr, nullptr));

    EXPECT_FALSE(arrayStackSize(n, nullptr));

    EXPECT_FALSE(arrayStackSize(m_as, nullptr));

    delete n;
}

TEST_F(ArrayStackTest, arrayStack_size_nominal_expectTrue)
{
    int32_t valueOutput{ 0 };
    uint32_t sizeOutput{ 0 };
    uint32_t expectedSize{ 0 };

    for (uint32_t i{ 0 }; i < C_MAX_STACK_SIZE - 1; i++)
    {
        expectedSize++;
        ASSERT_TRUE(arrayStackPush(m_as, i));
        ASSERT_TRUE(arrayStackTop(m_as, &valueOutput));
        ASSERT_EQ(i, valueOutput);

        ASSERT_TRUE(arrayStackSize(m_as, &sizeOutput));
        ASSERT_EQ(expectedSize, sizeOutput);
    }

    for (uint32_t i{ expectedSize }; i > 0; i--)
    {
        expectedSize--;
        ASSERT_TRUE(arrayStackPop(m_as));
        ASSERT_TRUE(arrayStackSize(m_as, &sizeOutput));
        ASSERT_EQ(expectedSize, sizeOutput);
    }
}
