#include <asm-generic/errno.h>
#include <iostream>
#include "debug.h"
#include "analysis.h"
#include "token.h"
#include <vector>
#include <string>
#include <map>

using namespace analysis_mod;


csz_stack::cz csz_stack::exp=csz_stack::cz();
std::vector<csz_stack::cz> csz_stack::do_st={};
std::map<std::string,csz_stack::sql_shuju> csz_stack::sql={};
void analysis_read::do_the_that(token_class::bnf_token bt)
{
  static int asser;
  std::string str;
  token_class::token tok1;
  token_class::token *tok;//,*tok1;
  std::vector<token_class::token*> vet;
  
  switch(bt.stat)
  {
  case token_class::bnf_token::Assert:
    asser=!asser;
    break;
  case token_class::bnf_token::ID:
    csz_stack::exp.type=type_e::Atom;
    csz_stack::exp.tok=bt.is_ter;
    csz_stack::do_st.push_back(csz_stack::exp);
    break;

  // case token_class::bnf_token::Lkh:
  //   csz_stack::exp.type=type_e::Lkh;
  //   csz_stack::do_st.push_back(csz_stack::exp);
  //   break;
    
  // case token_class::bnf_token::Rkh:
    
  // case token_class::bnf_token::Ter:
    
    
  case token_class::bnf_token::OP:
    vet.clear();
    debug;
    tok=bt.is_ter;
    debug;

    if(tok->true_type-token_class::token::D_t)
    {
      debug;
      for(int i=0;i<tok->args;i++)
	vet.push_back(csz_stack::do_st[csz_stack::do_st.size()-1].tok),
	  csz_stack::do_st.pop_back();

      str="SELECT * ";

      debug;
      // if(csz_stack::sql.size()>0) str+=csz_stack::sql[tok->str].list[0];
      // if(csz_stack::sql.size()>1)
      // 	for(int i=1;i<csz_stack::sql[tok->str].list.size();i++)
      // 	  str+=","+csz_stack::sql[tok->str].list[i];
      str+=" FROM "+csz_stack::sql[tok->str].table;
      for(int i=0,j=0;vet.size()>i;i++){debug;printf("%d\n",vet[i]->true_type);debug;
	if(vet[i]->true_type-token_class::token::Addr)
	{
	  debug;
	  if(!j)
	  {
	    j^=1;
	    str+=" WHERE "+csz_stack::sql[tok->str].list[i]+"="+vet[i]->str;
	      
	  }
	  else
	  {
	    str+=" AND "+csz_stack::sql[tok->str].list[i]+"="+vet[i]->str;
	    
	  }
	    
	}debug;}
      debug;
      
      for(int i=0;vet.size()>i;i++)
      {
	debug;
	if(!(vet[i]->true_type-token_class::token::Addr))
	{
	  str+=" JOIN "+vet[i]->str+" AS "+"t"+std::to_string(i)+" ON "+"t"+std::to_string(i)+"."+csz_stack::sql[tok->str].list[i]+"="+csz_stack::sql[tok->str].table+"."+csz_stack::sql[tok->str].list[i];
	    
	}
	
	  
      }
      // if(csz_stack::sql.size()>0) str+=" WHERE "+;
      // for(int i=1;i<csz_stack::sql[tok->str].list.size();i++)
      // 	str+=","+csz_stack::sql[tok->str].list[i];

      // str+=" WHERE "+csz_stack::sql;
      std::cout<<str<<std::endl;

      // tok=new token_class::token();
      // tok1=
      csz_stack::exp.type=type_e::Addr;
      csz_stack::exp.str="("+str+")";
      csz_stack::exp.tok=new token_class::token(token_class::token::Addr);
      csz_stack::exp.tok->str="("+str+")";
      csz_stack::exp.tok->true_type=token_class::token::Addr;
      csz_stack::do_st.push_back(csz_stack::exp);
      break;

    }
    else
    {
      for(int i=0;i<tok->args;i++)
	vet.push_back(csz_stack::do_st[csz_stack::do_st.size()-1].tok),
	  csz_stack::do_st.pop_back();
      
      str="SELECT * ";
      str+="FROM (SELECT colum_name FROM "+vet[0]->str+") AS t1 ";
      str+="JOIN (SELECT colum_name FROM "+vet[1]->str+") AS t2 ";
      str+="ON t1.column_name = t2.column_name";
      std::cout<<str<<std::endl;

      // tok=new token_class::token();
      // tok1=
      csz_stack::exp.type=type_e::Addr;
      csz_stack::exp.str="("+str+")";
      csz_stack::exp.tok=new token_class::token(token_class::token::Addr);
      csz_stack::exp.tok->str="("+str+")";
      csz_stack::exp.tok->true_type=token_class::token::Addr;
      csz_stack::do_st.push_back(csz_stack::exp);
      break;
      
    }

  case token_class::bnf_token::Ter:
    csz_stack::do_st.clear();
    break;
      
  }

  
}
