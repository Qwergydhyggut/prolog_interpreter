#include <cstdio>
#include <functional>
#include <iostream>
#include "lexer.h"
#include "lexer/token_num.h"
#include <gtest/gtest.h>
#include <vector>
#include "debug.h"
#include <algorithm>
#include "lexer/lexer_select.h"


std::function<bool(char,char)> test_gob_fun=[](char c,char c1){return !(c1-' ');};
TEST(read, test)
{
  lexer_mod::lexer_read test(test_gob_fun);
  char teststr[]={"lllll  lllllll aaa aaa lllll aaa"};
  // printf("%ld\n",(long int)test('a'));
  // printf("%ld\n",(long int)test('a'));
  for (int i=0; teststr[i]-'\0'; std::cout<<test(teststr[i],teststr[i+1]).str<<'\t',i++);
  for (int i=0; teststr[i]-'\0'; std::cout<<test(teststr[i],teststr[i+1]).token_exp<<'\t',i++);
  // printf("%d\n",testing::GTEST_FLAG(list_tests).size());
  
  
  
}

TEST(read, num)
{
  token_num_sp::token_num ll;
  EXPECT_EQ(1, ll());
  EXPECT_EQ(2, ll());
  ll(1);
  EXPECT_EQ(1, ll());
  ll(2);
  EXPECT_EQ(2, ll());
  EXPECT_EQ(3, ll());
  for (int i = 0; i < 20; i++)
  {
    EXPECT_EQ(i+4, ll());
    
    
  }

  ll(13);
  ll(15);
  ll(9);
  EXPECT_EQ(9, ll());
  EXPECT_EQ(13, ll());
  EXPECT_EQ(15, ll());
  
  
}

// TEST(MyClassTest, PrivateMethodTest)
namespace lexer_mod
{    
  TEST(read, lexer_list)
  {
    lexer_mod::lexer_read test(test_gob_fun);
    char teststr[]={"lllll  lllllll aaa aaa lllll aaa"};
  
    for (int i=0; teststr[i+1]-'\0'; test(teststr[i],teststr[i+1]),i++);
    test('a',' ');
    for (int i=0; teststr[i+1]-'\0'; test(teststr[i],teststr[i+1]),i++);
    test('a',' ');
    //test(' ');
    test.__debug_ret_lexer();
  
  
  }

  TEST(read, del_node)
  {
    lexer_mod::lexer_read test(test_gob_fun);
    char teststr[]={"lllll pppqa pppaa lllllll aaa aaa lllll aaa"};
  
    for (int i=0; teststr[i+1]-'\0'; test(teststr[i],teststr[i+1]),i++);
    for (int i=0; teststr[i+1]-'\0'; test(teststr[i],teststr[i+1]),i++);
    token_class::token tok=test('a',' ');
    test.__debug_ret_lexer();
    std::cout<<tok.str<<std::endl;
    test.del_token(tok);
    test.__debug_ret_lexer();
    for (int i=0; teststr[i+1]-'\0'; tok=test(teststr[i],teststr[i+1]),i++)
      if(tok.str=="pppqa")
	break;
    debug;
    std::cout<<tok.str<<std::endl;
    for (int i=0; teststr[i+1]-'\0'; test(teststr[i],teststr[i+1]),i++);
    test('a',' ');
    test.__debug_ret_lexer();
    test.del_token(tok);
    test.__debug_ret_lexer();
    // for (int i=0; teststr[i]-'\0'; test(teststr[i++]));
    // debug;
    // test('a',' ');
    // test('p');
    // test('p');
    // test('p');
    // test('q');
    // test('a');
    // tok=test(' ',' ');
    tok=test('p','p');
    tok=test('p','w');
    tok=test('w','t');
    token_class::token &tok1=test('t',' ');
    printf("%ld\n",tok1);
    debug;
    // test(' ',' ');
    std::cout<<tok1.str<<std::endl;
    test.__debug_ret_lexer();
    tok1.str[0]='r';
    debug;
    test.__debug_ret_lexer();
    std::cout<<tok1.str<<std::endl;
  
  
  
  }

  TEST(read, select)
  {
    lexer_mod::lexer_read test(select_token_class::select_token_fun_ptr,select_token_class::select_set_token_ptr);

    char teststr[]={"lll Xll+-x10a;oo .99.ll _ 10 1+1 "};
    for(int i=0;teststr[i+1]-'\0';i++)
    {
      auto &tok=test(teststr[i],teststr[i+1]);
      // tok.str[0]='n';
      std::cout<<tok.token_type<<'\t'<<tok.str<<std::endl;

    }

    test.__debug_ret_lexer();
    
  }


} 
  
// namespace lll {
//     class MyClass {
//     private:
//         int add(int a, int b) {
//             return a + b;
//         }

//         FRIEND_TEST(MyClassTest, PrivateMethodTest);
//     };
// }

// TEST(MyClassTest, PrivateMethodTest) {
//     lll::MyClass myObj;
//     EXPECT_EQ(myObj.add(2, 3), 5);
// }
// namespace lll {
//     class MyClass {
//     private:
//         FRIEND_TEST(MyClassTest, TestBody);
//         int add(int a, int b) {
//             return a + b;
//         }

//     };
// }

// TEST(MyClassTest, TestBody) {
//     lll::MyClass myObj;
//     using namespace lll;
//     EXPECT_EQ(myObj.add(2, 3), 5);
// }
