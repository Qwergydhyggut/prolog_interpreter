#include <cstdio>
#include <iostream>
#include "lexer.h"
#include "source_read.h"
#include <string>
#include "synatax/synatax_ptr.h"
#include "synatax.h"
#include "analysis.h"


int main(int arg,char **args)
{
  std::cout<<"lll"<<arg<<args[1]<<std::endl;
  FILE *fp;

  printf("%s %d\n",args[0],arg);

  if(arg<2)
  {
    printf("未输入文件名\n");
    exit(__LINE__);
      
  }
  for(int i=0;i<arg;i++)
  {
    std::string str=args[i];
    if(str=="a"||str=="./a")
      if(!(i+1-arg))
      {
	printf("未输入文件名\n");
	exit(__LINE__);
	  
      }
      else
      {
	synatax_ptr_f *read_class=source_read_mod::source_select::select_mode(args[i+1]);
	synatax_mod::synatax_read compli(read_class);
	str=args[i+1];
	str+=".sql";
	fp=fopen(str.c_str(),"w");

	compli();
	
  
      }	
    
  }  

  std::string str=analysis_mod::csz_stack::do_st[analysis_mod::csz_stack::do_st.size()-1].str;
  fputs(str.c_str(),fp);
  // std::cout<<analysis_mod::csz_stack::do_st[analysis_mod::csz_stack::do_st.size()-1].str<<std::endl;
  
  
}
