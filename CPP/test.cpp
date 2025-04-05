#include <gtest/gtest.h>

// Function to test
int add(int a, int b) {
    return a + b;
}

// Test case
TEST(AdditionTest, PositiveNumbers) {
    EXPECT_EQ(add(2, 3), 5);
    ASSERT_EQ(add(5, 7), 12);
}

TEST(AdditionTest, NegativeNumbers) {
    EXPECT_EQ(add(-2, -3), -5);
    ASSERT_EQ(add(-5, -7), -12);
}