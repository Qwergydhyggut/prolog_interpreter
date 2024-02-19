#include <cstdio>
#include <iostream>
#include "lexer.h"
#include <gtest/gtest.h>


TEST(read, test)
{
  lexer_mod::lexer_read test;
  char teststr[]={"lllll  lllllll aaa aaa lllll aaa"};
  // printf("%ld\n",(long int)test('a'));
  // printf("%ld\n",(long int)test('a'));
  for (int i=0; teststr[i]-'\0'; std::cout<<test(teststr[i++]).str<<'\t');
  // printf("%d\n",testing::GTEST_FLAG(list_tests).size());
  
  
  
}    
