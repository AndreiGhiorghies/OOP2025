#include "pch.h"
#include "sort.cpp"

class SortTest : public testing::Test {
protected:
    Sort<int> s1, s2;
    Sort<double> s3;
    virtual void SetUp() {
        s1.SetValues({ 5, 3, 7, 3, 2 });
        s2.SetValues({ 28, 65, 23, 87, 12, 98 });
        s3.SetValues({ 0, 7.4, 3.3, 6, 7.3, 1, 9.5 });
        s1.QuickSort();
        s2.QuickSort();
        s3.QuickSort();
    }
};
TEST_F(SortTest, testSortInt) {
    ASSERT_STREQ("2, 3, 3, 5, 7", s1.Print().c_str());
    ASSERT_STREQ("12, 23, 28, 65, 87, 98", s2.Print().c_str());
}

TEST_F(SortTest, testSortDouble) {
    ASSERT_STREQ("0.000000, 1.000000, 3.300000, 6.000000, 7.300000, 7.400000, 9.500000", s3.Print().c_str());
}