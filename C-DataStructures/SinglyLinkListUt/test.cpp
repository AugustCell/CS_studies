#include "pch.h"

class SinglyLinkedListTest : public ::testing::Test
{
protected:
    SinglyLinkedList* m_sll = nullptr;

    void SetUp() override
    {
        m_sll = new SinglyLinkedList();
    }

    void TearDown() override
    {
        freeNode(m_sll->m_head);
        delete m_sll;
    }
};

TEST_F(SinglyLinkedListTest, sll_initialize_notNull_expectFalse)
{
    EXPECT_FALSE(sllInit(&m_sll));
}


TEST(SinglyLinkedListInitTest, sll_nominal_expectTrue)
{
    SinglyLinkedList* sll = nullptr;

    EXPECT_TRUE(sllInit(&sll));

    free(sll);
}

TEST_F(SinglyLinkedListTest, sll_getFront_sllNull_expectFalse)
{
    EXPECT_FALSE(sllGetFront(nullptr, nullptr));
}

TEST_F(SinglyLinkedListTest, sll_getFront_sllHeadNull_expectFalse)
{
    EXPECT_FALSE(sllGetFront(m_sll, nullptr));
}

TEST_F(SinglyLinkedListTest, sll_getFront_sllNodeValueNull_expectFalse)
{
    ASSERT_TRUE(sllInsert(m_sll, 1));

    EXPECT_FALSE(sllGetFront(m_sll, nullptr));
}

TEST_F(SinglyLinkedListTest, sll_getFront_nominal_expectTrue)
{
    constexpr uint32_t expectedValue{ 1 };
    uint32_t inputTestValue{ 0 };

    ASSERT_TRUE(sllInsert(m_sll, expectedValue));

    EXPECT_TRUE(sllGetFront(m_sll, &inputTestValue));

    EXPECT_EQ(expectedValue, inputTestValue);
}

TEST_F(SinglyLinkedListTest, sll_getBack_sllNull_expectFalse)
{
    EXPECT_FALSE(sllGetBack(nullptr, nullptr));
}

TEST_F(SinglyLinkedListTest, sll_getBack_sllHeadNull_expectFalse)
{
    EXPECT_FALSE(sllGetBack(m_sll, nullptr));
}

TEST_F(SinglyLinkedListTest, sll_getBack_sllNodeValueNull_expectFalse)
{
    ASSERT_TRUE(sllInsert(m_sll, 1));

    EXPECT_FALSE(sllGetBack(m_sll, nullptr));
}

TEST_F(SinglyLinkedListTest, sll_getBack_nominal_expectTrue)
{
    constexpr uint32_t testValue1{ 1 };
    constexpr uint32_t testValue2{ 2 };
    uint32_t inputTestValue{ 0 };

    ASSERT_TRUE(sllInsert(m_sll, testValue1));
    ASSERT_TRUE(sllInsert(m_sll, testValue2));

    EXPECT_TRUE(sllGetBack(m_sll, &inputTestValue));

    EXPECT_EQ(testValue2, inputTestValue);
}

TEST_F(SinglyLinkedListTest, sll_checkEmpty_sllNull_expectFalse)
{
    EXPECT_FALSE(sllCheckEmpty(nullptr, nullptr));
}

TEST_F(SinglyLinkedListTest, sll_checkEmpty_isEmptyNull_expectFalse)
{
    EXPECT_FALSE(sllCheckEmpty(m_sll, nullptr));
}

TEST_F(SinglyLinkedListTest, sll_checkEmpty_nominal_expectTrue)
{
    bool isEmpty{ false };

    EXPECT_TRUE(sllCheckEmpty(m_sll, &isEmpty));

    ASSERT_TRUE(isEmpty);
}

TEST_F(SinglyLinkedListTest, sll_getSize_sllNull_expectFalse)
{
    EXPECT_FALSE(sllGetSize(nullptr, nullptr));
}

TEST_F(SinglyLinkedListTest, sll_getSize_sizeNull_expectFalse)
{
    EXPECT_FALSE(sllGetSize(m_sll, nullptr));
}

TEST_F(SinglyLinkedListTest, sll_getSize_nominal_expectTrue)
{
    constexpr uint32_t maxSize{ 5 };
    uint32_t testSize{ 0 };

    for (uint32_t i{ 0 }; i < maxSize; i++)
    {
        ASSERT_TRUE(sllInsert(m_sll, 1));
    }

    ASSERT_TRUE(sllGetSize(m_sll, &testSize));

    EXPECT_EQ(maxSize, testSize);
}

TEST_F(SinglyLinkedListTest, sll_addToFront_sllNull_expectFalse)
{
    EXPECT_FALSE(sllAddToFront(nullptr, 0));
}

TEST_F(SinglyLinkedListTest, sll_addToFront_sllEmpty_add_expectTrue)
{
    constexpr uint32_t testValue{ 2 };
    uint32_t resultValue{ 0 };

    EXPECT_TRUE(sllAddToFront(m_sll, testValue));

    ASSERT_TRUE(sllGetFront(m_sll, &resultValue));

    EXPECT_EQ(testValue, resultValue);
}

TEST_F(SinglyLinkedListTest, sll_addToFront_sllNonEmpty_add_expectTrue)
{
    constexpr uint32_t testValue1{ 2 };
    constexpr uint32_t testValue2{ 4 };
    uint32_t resultValue{ 0 };

    EXPECT_TRUE(sllAddToFront(m_sll, testValue1));
    EXPECT_TRUE(sllAddToFront(m_sll, testValue2));

    ASSERT_TRUE(sllGetFront(m_sll, &resultValue));

    EXPECT_EQ(testValue2, resultValue);
}

TEST_F(SinglyLinkedListTest, sll_addToFront_getSize_nominal_expectTrue)
{
    constexpr uint32_t maxSize{ 5 };
    uint32_t testSize{ 0 };

    for (uint32_t i{ 0 }; i < maxSize; i++)
    {
        ASSERT_TRUE(sllAddToFront(m_sll, 1));
    }

    ASSERT_TRUE(sllGetSize(m_sll, &testSize));

    EXPECT_EQ(maxSize, testSize);
}

TEST_F(SinglyLinkedListTest, sll_addToBack_sllNull_expectFalse)
{
    EXPECT_FALSE(sllAddToBack(nullptr, 0));
}

TEST_F(SinglyLinkedListTest, sll_addToBack_sllEmpty_add_expectTrue)
{
    constexpr uint32_t testValue{ 2 };
    uint32_t resultValue{ 0 };

    EXPECT_TRUE(sllAddToBack(m_sll, testValue));

    ASSERT_TRUE(sllGetBack(m_sll, &resultValue));

    EXPECT_EQ(testValue, resultValue);
}

TEST_F(SinglyLinkedListTest, sll_addToBack_sllNonEmpty_add_expectTrue)
{
    constexpr uint32_t testValue1{ 2 };
    constexpr uint32_t testValue2{ 4 };
    uint32_t resultValue{ 0 };

    EXPECT_TRUE(sllAddToBack(m_sll, testValue1));
    EXPECT_TRUE(sllAddToBack(m_sll, testValue2));

    ASSERT_TRUE(sllGetBack(m_sll, &resultValue));

    EXPECT_EQ(testValue2, resultValue);
}

TEST_F(SinglyLinkedListTest, sll_addToBack_getSize_nominal_expectTrue)
{
    constexpr uint32_t maxSize{ 5 };
    uint32_t testSize{ 0 };

    for (uint32_t i{ 0 }; i < maxSize; i++)
    {
        ASSERT_TRUE(sllAddToBack(m_sll, 1));
    }

    ASSERT_TRUE(sllGetSize(m_sll, &testSize));

    EXPECT_EQ(maxSize, testSize);
}

TEST_F(SinglyLinkedListTest, sll_popFront_sllNull_expectFalse)
{
    EXPECT_FALSE(sllPopFront(nullptr));
}

TEST_F(SinglyLinkedListTest, sll_popFront_nominal_singleNode_expectTrue)
{
    constexpr uint32_t testValue{ 2 };
    bool isEmpty{ false };

    ASSERT_TRUE(sllInsert(m_sll, testValue));

    EXPECT_TRUE(sllPopFront(m_sll));

    ASSERT_TRUE(sllCheckEmpty(m_sll, &isEmpty));

    ASSERT_TRUE(isEmpty);
}

TEST_F(SinglyLinkedListTest, sll_popFront_nominal_multipleNodes_expectTrue)
{
    constexpr uint32_t testValue1{ 2 };
    constexpr uint32_t testValue2{ 4 };
    bool isEmpty{ false };

    ASSERT_TRUE(sllInsert(m_sll, testValue1));
    ASSERT_TRUE(sllInsert(m_sll, testValue2));

    EXPECT_TRUE(sllPopFront(m_sll));

    ASSERT_TRUE(sllCheckEmpty(m_sll, &isEmpty));

    ASSERT_FALSE(isEmpty);

    isEmpty = false;

    EXPECT_TRUE(sllPopFront(m_sll));

    ASSERT_TRUE(sllCheckEmpty(m_sll, &isEmpty));
}


TEST_F(SinglyLinkedListTest, sll_popBack_sllNull_expectFalse)
{
    EXPECT_FALSE(sllPopBack(nullptr));
}

TEST_F(SinglyLinkedListTest, sll_popBack_nominal_singleNode_expectTrue)
{
    constexpr uint32_t testValue{ 2 };
    bool isEmpty{ false };

    ASSERT_TRUE(sllInsert(m_sll, testValue));

    EXPECT_TRUE(sllPopBack(m_sll));

    ASSERT_TRUE(sllCheckEmpty(m_sll, &isEmpty));

    ASSERT_TRUE(isEmpty);
}

TEST_F(SinglyLinkedListTest, sll_popBack_nominal_multipleNodes_expectTrue)
{
    constexpr uint32_t testValue1{ 2 };
    constexpr uint32_t testValue2{ 4 };
    bool isEmpty{ false };

    ASSERT_TRUE(sllInsert(m_sll, testValue1));
    ASSERT_TRUE(sllInsert(m_sll, testValue2));

    EXPECT_TRUE(sllPopBack(m_sll));

    ASSERT_TRUE(sllCheckEmpty(m_sll, &isEmpty));

    ASSERT_FALSE(isEmpty);

    isEmpty = false;

    EXPECT_TRUE(sllPopBack(m_sll));

    ASSERT_TRUE(sllCheckEmpty(m_sll, &isEmpty));
}

TEST_F(SinglyLinkedListTest, sll_reverse_sllNull_expectFalse)
{
    EXPECT_FALSE(sllReverse(nullptr));
}

TEST_F(SinglyLinkedListTest, sll_reverse_sllHeadNull_expectFalse)
{
    EXPECT_FALSE(sllReverse(m_sll));
}

TEST_F(SinglyLinkedListTest, sll_reverse_sllSingleNode_expectFalse)
{
    ASSERT_TRUE(sllInsert(m_sll, 1));

    EXPECT_FALSE(sllReverse(m_sll));
}

TEST_F(SinglyLinkedListTest, sll_reverse_nominal_expectTrue)
{
    std::vector<uint32_t> testElements{ 1, 2, 3, 4, 5 };
    const std::vector<uint32_t> expectedElements{ 5, 4, 3, 2, 1 };
    uint32_t resultValue{ 0 };
    bool isEmpty{ false };

    for (const uint32_t& e : testElements)
    {
        ASSERT_TRUE(sllInsert(m_sll, e));
    }

    EXPECT_TRUE(sllReverse(m_sll));

    for (const uint32_t& e : expectedElements)
    {
        ASSERT_TRUE(sllGetFront(m_sll, &resultValue));
        ASSERT_EQ(e, resultValue);
        resultValue = 0;

        ASSERT_TRUE(sllPopFront(m_sll));
    }

    ASSERT_TRUE(sllCheckEmpty(m_sll, &isEmpty));
    ASSERT_TRUE(isEmpty);
}

TEST_F(SinglyLinkedListTest, sll_merge_lhsNull_expectFalse)
{
    EXPECT_FALSE(sllMerge(nullptr, nullptr));
}

TEST_F(SinglyLinkedListTest, sll_merge_rhsNull_expectFalse)
{
    EXPECT_FALSE(sllMerge(m_sll, nullptr));
}

TEST_F(SinglyLinkedListTest, sll_merge_lhsHeadNull_expectFalse)
{
    EXPECT_FALSE(sllMerge(m_sll, m_sll));
}

TEST_F(SinglyLinkedListTest, sll_merge_rhsHeadNull_expectFalse)
{
    const auto rhsSll = new SinglyLinkedList();

    ASSERT_TRUE(sllInsert(m_sll, 1));

    EXPECT_FALSE(sllMerge(m_sll, rhsSll));

    delete rhsSll;
}

TEST_F(SinglyLinkedListTest, sll_merge_nominal_expectTrue)
{
    auto rhsSll = new SinglyLinkedList();
    uint32_t resultValue{ 0 };
    bool isEmpty{ false };

    ASSERT_TRUE(sllInsert(m_sll, 1));
    ASSERT_TRUE(sllInsert(m_sll, 3));
    ASSERT_TRUE(sllInsert(m_sll, 5));
    ASSERT_TRUE(sllInsert(m_sll, 7));

    ASSERT_TRUE(sllInsert(rhsSll, 2));
    ASSERT_TRUE(sllInsert(rhsSll, 4));
    ASSERT_TRUE(sllInsert(rhsSll, 6));
    ASSERT_TRUE(sllInsert(rhsSll, 8));

    EXPECT_TRUE(sllMerge(m_sll, rhsSll));

    for (uint32_t i{ 1 }; i <= 8; i++)
    {
        ASSERT_TRUE(sllGetFront(m_sll, &resultValue));
        ASSERT_EQ(i, resultValue);
        resultValue = 0;

        ASSERT_TRUE(sllPopFront(m_sll));
    }

    delete rhsSll;
}
