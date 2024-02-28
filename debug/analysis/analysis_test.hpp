#include <gtest/gtest.h>
#include "analysis.h"


TEST(analysis, do_sql)
{
  static token_class::bnf_token S(token_class::bnf_token::S);
  static token_class::bnf_token ID(token_class::bnf_token::ID);
  static token_class::bnf_token OP(token_class::bnf_token::OP);
  static token_class::bnf_token OP1(token_class::bnf_token::OP);
  static token_class::bnf_token Ter(token_class::bnf_token::Ter);

  static analysis_mod::csz_stack::sql_shuju sqs;
  static analysis_mod::csz_stack::sql_shuju sqs1;

  debug;
  sqs.table="lll";
  sqs.list={"qqq","lll"};
  sqs1.table="qqq";
  sqs1.list={"lll"};
  ID.is_ter=new token_class::token;
  OP.is_ter=new token_class::token;
  OP1.is_ter=new token_class::token;
  ID.is_ter->str="10";
  OP.is_ter->str="lll";
  OP.is_ter->args=2;
  OP1.is_ter->str="qqq";
  OP1.is_ter->args=1;
  debug;
  // analysis_mod::csz_stack::sql.insert(std::make_pair("lll",sqs));
  // analysis_mod::csz_stack::sql.insert(std::make_pair("qqq",sqs1));
  debug;
  // analysis_mod::analysis_read::do_the_that(S);
  // analysis_mod::analysis_read::do_the_that(ID);
  // analysis_mod::analysis_read::do_the_that(ID);
  // analysis_mod::analysis_read::do_the_that(OP);
  // analysis_mod::analysis_read::do_the_that(OP1);
  // analysis_mod::analysis_read::do_the_that(Ter);
  debug;
  debug;

  
}
