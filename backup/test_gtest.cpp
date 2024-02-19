#include <gtest/gtest.h>

namespace lll {
    class MyClass {
    private:
        int addllllllllllll(int a, int b) {
            return a + b;
        }

        FRIEND_TEST(MyClassTest, TestBody);
    };
    } // namespace lll
//namespace lll {   

//using namespace lll;
lll::TEST(MyClassTest, TestBody) {
  using namespace lll;
  MyClass myObj;
  EXPECT_EQ(myObj.addllllllllllll(2, 3), 5);
}
//}
