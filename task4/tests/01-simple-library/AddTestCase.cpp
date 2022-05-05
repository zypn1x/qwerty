#include "AddTestCase.h"
#include "Functions.h"

TEST(A, B) {

  for(int i = 0; i < 3; ++i) {
    for( int j = 0; j < 3; ++j) {
      ASSERT_EQ(Add(i, j), i + j);
    }
  }
  ASSERT_THROW(IsLeap(-5), std::invalid_argument);
  ASSERT_EQ(IsLeap(1600), true);
  ASSERT_EQ(IsLeap(1300), false);
  ASSERT_EQ(IsLeap(1616), true);
  ASSERT_EQ(IsLeap(8), true);
  ASSERT_THROW(IsLeap(-8),std::invalid_argument);
  ASSERT_EQ(IsLeap(6), false);
  ASSERT_EQ(GetMonthDays(1604,  2), 29);
  ASSERT_EQ(GetMonthDays(1605,  2), 28);
  ASSERT_EQ(GetMonthDays(1700,  2), 28);
  ASSERT_THROW(GetMonthDays(-1700 ,  2),std::invalid_argument);
  ASSERT_THROW(GetMonthDays(1700 ,  13),std::invalid_argument);
  ASSERT_THROW(GetMonthDays(1700 ,  0),std::invalid_argument);
  ASSERT_EQ(GetMonthDays(4 ,  1), 31);
  ASSERT_EQ(GetMonthDays(4 ,  3), 31);
  ASSERT_EQ(GetMonthDays(4 ,  4), 30);
}
