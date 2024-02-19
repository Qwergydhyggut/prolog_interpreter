#include "debug.h"
#include "lexer/token_num.h"
#include <iostream>
#include <iterator>


using namespace token_num_sp;
using namespace std;


token_num::token_num()
{
  debug;
  this->max=1;
 
  
}

token_num::~token_num()
{
  printf("exit\n");

  
}

int token_num::operator()()
{
  if(this->num_set.empty()) return max++;
  int ret=*this->num_set.begin();
  this->num_set.erase(ret);

  return ret;
}

void token_num::operator()(int num)
{
  this->num_set.insert(num);
  
  
}
