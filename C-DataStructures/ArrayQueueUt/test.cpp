#include "pch.h"

class ArrayQueueTest : public ::testing::Test
{
protected:
    ArrayQueue* m_aq{ nullptr };

    void SetUp() override
    {
        assert(arrayQueueInit(&m_aq));
    }

    void TearDown() override
    {
        arrayQueueFree(m_aq);
    }
};

TEST_F(ArrayQueueTest, arrayQueue_init_alreadyInitialized_expectFalse)
{
    EXPECT_FALSE(arrayQueueInit(&m_aq));
}

TEST(ArrayQueueInitTest, arrayQueue_init_nomimal_expectTrue)
{
    ArrayQueue* as{ nullptr };

    EXPECT_TRUE(arrayQueueInit(&as));

    ASSERT_TRUE(arrayQueueFree(as));
}

TEST(ArrayQueuePushTest, arrayQueue_push_notInit_expectFalse)
{
    ArrayQueue* as{ nullptr };

    EXPECT_FALSE(arrayQueuePush(as, 1));
}

TEST_F(ArrayQueueTest, arrayQueue_push_queueOverflowSimple_expectFalse)
{
    m_aq->m_size = C_MAX_QUEUE_SIZE + 1;

    EXPECT_FALSE(arrayQueuePush(m_aq, 1));

    m_aq->m_size = 0;
}

TEST_F(ArrayQueueTest, arrayQueue_push_stackOverflowLoop_expectFalse)
{
    for (uint32_t i{ 0 }; i < C_MAX_QUEUE_SIZE - 1; i++)
    {
        ASSERT_TRUE(arrayQueuePush(m_aq, i));
    }

    EXPECT_FALSE(arrayQueuePush(m_aq, 1));
}

TEST_F(ArrayQueueTest, arrayQueue_push_arrayElementNull_expectFalse)
{
    free(m_aq->m_array[m_aq->m_size]);
    m_aq->m_array[m_aq->m_size] = NULL;

    EXPECT_FALSE(arrayQueuePush(m_aq, 1));
}

TEST_F(ArrayQueueTest, arrayQueue_push_nominal_expectTrue)
{
    constexpr int32_t testValue{ 1 };

    ASSERT_TRUE(arrayQueuePush(m_aq, testValue));

    const auto res = m_aq->m_array[m_aq->m_size];

    ASSERT_EQ(*res, testValue);
}

TEST_F(ArrayQueueTest, arrayQueue_pop_notInit_expectFalse)
{
    EXPECT_FALSE(arrayQueuePop(nullptr));
}

TEST_F(ArrayQueueTest, arrayQueue_pop_arrayNotInit_expectFalse)
{
    const auto n = new ArrayQueue;

    n->m_array = nullptr;

    EXPECT_FALSE(arrayQueuePop(n));

    delete n;
}

TEST_F(ArrayQueueTest, arrayQueue_pop_stackEmpty_expectFalse)
{
    EXPECT_FALSE(arrayQueuePop(m_aq));
}

TEST_F(ArrayQueueTest, arrayQueue_pop_nominal_expectFalse)
{
    ASSERT_TRUE(arrayQueuePush(m_aq, 1));

    EXPECT_TRUE(arrayQueuePop(m_aq));
}

TEST_F(ArrayQueueTest, arrayQueue_front_notInit_expectFalse)
{
    EXPECT_FALSE(arrayQueueFront(nullptr, nullptr));
}

TEST_F(ArrayQueueTest, arrayQueue_front_arrayNotInit_expectFalse)
{
    const auto n = new ArrayQueue;

    n->m_array = nullptr;

    EXPECT_FALSE(arrayQueueFront(n, nullptr));

    delete n;
}

TEST_F(ArrayQueueTest, arrayQueue_front_stackEmpty_expectFalse)
{
    EXPECT_FALSE(arrayQueueFront(m_aq, nullptr));
}

TEST_F(ArrayQueueTest, arrayQueue_front_valueNull, expectFalse)
{
    ASSERT_TRUE(arrayQueuePush(m_aq, 1));

    EXPECT_FALSE(arrayQueueFront(m_aq, nullptr));
}

TEST_F(ArrayQueueTest, arrayQueue_front_nominal_expectTrue)
{
    constexpr int32_t expectValue{ 1 };
    int32_t testValue{ 0 };

    ASSERT_TRUE(arrayQueuePush(m_aq, expectValue));

    EXPECT_TRUE(arrayQueueFront(m_aq, &testValue));

    ASSERT_EQ(expectValue, testValue);
}

TEST_F(ArrayQueueTest, arrayQueue_size_failCases_expectFalse)
{
    const auto n = new ArrayQueue;
    n->m_array = nullptr;

    EXPECT_FALSE(arrayQueueSize(nullptr, nullptr));

    EXPECT_FALSE(arrayQueueSize(n, nullptr));

    EXPECT_FALSE(arrayQueueSize(m_aq, nullptr));

    delete n;
}

TEST_F(ArrayQueueTest, arrayQueue_size_nominal_expectTrue)
{
    int32_t valueOutput{ 0 };
    uint32_t sizeOutput{ 0 };
    uint32_t expectedSize{ 0 };

    for (uint32_t i{ 0 }; i < C_MAX_QUEUE_SIZE - 1; i++)
    {
        expectedSize++;
        ASSERT_TRUE(arrayQueuePush(m_aq, i));
        ASSERT_TRUE(arrayQueueFront(m_aq, &valueOutput));
        ASSERT_EQ(i, valueOutput);

        ASSERT_TRUE(arrayQueueSize(m_aq, &sizeOutput));
        ASSERT_EQ(expectedSize, sizeOutput);
    }

    for (uint32_t i{ expectedSize }; i > 0; i--)
    {
        expectedSize--;
        ASSERT_TRUE(arrayQueuePop(m_aq));
        ASSERT_TRUE(arrayQueueSize(m_aq, &sizeOutput));
        ASSERT_EQ(expectedSize, sizeOutput);
    }
}
