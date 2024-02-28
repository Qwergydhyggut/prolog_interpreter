#include <cstdio>
#include <iostream>
#include "lexer.h"
#include "source_read.h"
#include <string>
#include "synatax/synatax_ptr.h"
#include "synatax.h"


int main(int arg,char **args)
{
  std::cout<<"lll"<<arg<<args[1]<<std::endl;
  // lexer_mod::lexer_read test([](char c,char c1){return !(c1-' ');},0);
  // char teststr[]={"lllll  lllllll aaa aaa lllll aaa"};
  // // printf("%ld\n",(long int)test('a'));
  // // printf("%ld\n",(long int)test('a'));
  // for (int i=0; teststr[i+1]-'\0'; std::cout<<test(teststr[i],teststr[i+1]).str<<'\t',i++);
  // for (int i=0; teststr[i+1]-'\0'; std::cout<<test(teststr[i],teststr[i+1]).str<<'\t',i++);
  // for (int i=0; teststr[i+1]-'\0'; printf("%d\t",test(teststr[i],teststr[i+1]).token_exp),i++);
  // for (int i=0; teststr[i+1]-'\0'; printf("%d\t",test(teststr[i],teststr[i+1]).token_exp),i++);
  //printf("%ld\n",(long int)test(' '));
  //  test();
  synatax_ptr_f *read_class=source_read_mod::source_select::select_mode("test.pl");
  synatax_mod::synatax_read compli(read_class);

  compli();
  
  
}
