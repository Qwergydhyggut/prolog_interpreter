#ifndef __SYNATAX_TREE_INCLUDE__
#define __SYNATAX_TREE_INCLUDE__
#include <vector>
#include "token.h"


namespace synatax_tree_class
{
  struct synatax_tree
  {
    synatax_tree(int addr=0):addr(addr){};
    token_class::token *car=new token_class::token();
    std::vector<token_class::token*> args;
    int addr;
  };
  
  
};

#endif
