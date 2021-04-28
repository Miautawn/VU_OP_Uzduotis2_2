#include "../Extensions/utility_functions.cpp"
#include <gtest/gtest.h>

//Digit Detection Tests
///////////////////////
TEST(DigitDetection, isDigit_5)
{
    EXPECT_EQ(true, is_digit("5"));
}

TEST(DigitDetection, isDigit_a)
{
    EXPECT_EQ(false, is_digit("a"));
}

//Mean & Median Tests
/////////////////////
std::vector<int> test_vector = {2, 1, 3};
TEST(MeanCalculation, mean)
{
    EXPECT_EQ(2, calculate_mean(test_vector.size(), test_vector));
}

TEST(MeanCalculation, median)
{
    EXPECT_EQ(2, calculate_median(test_vector.size(), test_vector));
}

int main(int argc, char **argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}