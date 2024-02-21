#include <cstdio>
#include <iostream>
#include "lexer.h"


int main(int arg,char **args)
{
  std::cout<<"lll"<<arg<<args[1]<<std::endl;
  lexer_mod::lexer_read test([](char c,char c1){return !(c1-' ');},0);
  char teststr[]={"lllll  lllllll aaa aaa lllll aaa"};
  // printf("%ld\n",(long int)test('a'));
  // printf("%ld\n",(long int)test('a'));
  for (int i=0; teststr[i+1]-'\0'; std::cout<<test(teststr[i],teststr[i+1]).str<<'\t',i++);
  for (int i=0; teststr[i+1]-'\0'; std::cout<<test(teststr[i],teststr[i+1]).str<<'\t',i++);
  for (int i=0; teststr[i+1]-'\0'; printf("%d\t",test(teststr[i],teststr[i+1]).token_exp),i++);
  for (int i=0; teststr[i+1]-'\0'; printf("%d\t",test(teststr[i],teststr[i+1]).token_exp),i++);
  //printf("%ld\n",(long int)test(' '));
  //  test();
  
  
}
