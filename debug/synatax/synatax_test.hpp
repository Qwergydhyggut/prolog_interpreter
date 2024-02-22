#include <gtest/gtest.h>
#include "synatax.h"
#include "debug.h"
#include <map>
#include <utility>
#include <vector>
#include "token.h"
#include "synatax/meta_map.hpp"


// bool operator<(const token_class::token tok,const token_class::token tok1)
// {
//   return tok.token_exp<tok1.token_exp;
  
  
// }

// struct sbmap
// {
//   int zzz;
// }    ;

// bool operator<(const sbmap sb,const sbmap sb1)
// {return true;}
TEST(meta, cons)
{
  // meta_map_mod::cons<token_class::token, token_class::token> test;
  // token_class::token lll;
  meta_map_mod::cons<token_class::token,token_class::token> test;
  // meta_map_mod::testmdzz<token_class::token>::cons<token_class::token,token_class::token>;
  
  
}
  
TEST(synatax, test)
{
  // test_syna();
  synatax_mod::synatax_read test;
  // token_class::token t1,t2;
  // t1.str="lll";
  // t2.str="zzz";
  // std::vector<token_class::token> mdzz{t1,t2};
  // t1<t2;
  // std::map<token_class::token,int> qtm;
  // qtm[t1]=0;
  // std::map<sbmap, int> mdzzmap;
  // sbmap youbing;
  // mdzzmap[youbing]=0;
  // synatax_mod::synatax_read::synatax_dnf[t1]=mdzz;
  // std::map<int,int> kkk;
  // kkk[0]=1;
  // kkk[1]=2;
  debug;
  
}
