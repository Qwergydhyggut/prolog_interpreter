#include "lexer_test.hpp"
#include "synatax_test.hpp"
#include "analysis/analysis_test.hpp"
// #include <cstdio>
// #include <iostream>
// #include "lexer.h"
// #include <gtest/gtest.h>


// TEST(read, test)
// {
//   lexer_mod::lexer_read test;
//   char teststr[]={"lllll  lllllll aaa aaa lllll aaa"};
//   // printf("%ld\n",(long int)test('a'));
//   // printf("%ld\n",(long int)test('a'));
//   for (int i=0; teststr[i]-'\0'; std::cout<<test(teststr[i++]).str<<'\t');
  
  
  
// }    

int main(int arg,char **args)
{
  testing::InitGoogleTest(&arg,args);
  return RUN_ALL_TESTS();
  
  
}  
// class MyClass {  // 定义一个简单的类 MyClass
// public:
//     int add(int a, int b) {  // 类的成员函数，实现简单的加法操作
//         return a + b;
//     }
// };

// TEST(MyClassTest, AddTest) {  // 定义一个测试用例，测试 MyClass 类中 add 函数的功能
//     MyClass myObj;  // 创建 MyClass 类的对象
//     EXPECT_EQ(myObj.add(1, 2), 3);  // 使用 Google Test 提供的断言验证 add 函数的返回值
// }

// int main(int argc, char **argv) {  // 主函数
//     ::testing::InitGoogleTest(&argc, argv);  // 初始化 Google Test 框架
//     return RUN_ALL_TESTS();  // 运行所有测试用例并返回结果
// }
// int main(int arg,char **args)
// {
//   std::cout<<"lll"<<arg<<args[1]<<std::endl;
//   lexer_mod::lexer_read test;
//   char teststr[]={"lllll  lllllll aaa aaa lllll aaa"};
//   // printf("%ld\n",(long int)test('a'));
//   // printf("%ld\n",(long int)test('a'));
//   for (int i=0; teststr[i]-'\0'; std::cout<<test(teststr[i++]).str<<'\t');
//   for (int i=0; teststr[i]-'\0'; std::cout<<test(teststr[i++]).str<<'\t');
//   for (int i=0; teststr[i]-'\0'; printf("%d\t",test(teststr[i++]).token_exp));
//   for (int i=0; teststr[i]-'\0'; printf("%d\t",test(teststr[i++]).token_exp));
//   //printf("%ld\n",(long int)test(' '));
//   //  test();
  
  
// }
