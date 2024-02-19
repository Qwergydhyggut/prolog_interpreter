#ifndef __TOKEN_NUM__
#define __TOKEN_NUM__
#include <set>


namespace token_num_sp
{
  class token_num
  {
  private:
    std::set<int> num_set;
    int max;
  public:
    token_num();
    ~token_num();
    int operator()();
    void operator()(int num);

  };
  
};

#endif
