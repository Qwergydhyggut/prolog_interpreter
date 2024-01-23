#include <cstdio>
#include <iostream>
#include "lexer.h"


int main(int arg,char **args)
{
  std::cout<<"lll"<<arg<<args[1]<<std::endl;
  lexer_mod::lexer_read test;
  char teststr[]={"lllll  lllllll aaa aaa lllll aaa"};
  // printf("%ld\n",(long int)test('a'));
  // printf("%ld\n",(long int)test('a'));
  for (int i=0; teststr[i]-'\0'; printf("%ld  ",(long int)test(teststr[i++])));
  printf("%ld\n",(long int)test(' '));
  //  test();
  
  
}
