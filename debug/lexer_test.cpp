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
  for (int i=0; teststr[i]-'\0'; std::cout<<test(teststr[i++]).str<<'\t');
  for (int i=0; teststr[i]-'\0'; std::cout<<test(teststr[i++]).str<<'\t');
  for (int i=0; teststr[i]-'\0'; printf("%d\t",test(teststr[i++]).token_exp));
  for (int i=0; teststr[i]-'\0'; printf("%d\t",test(teststr[i++]).token_exp));
  //printf("%ld\n",(long int)test(' '));
  //  test();
  
  
}
