#include <iostream>

unsigned power(unsigned x, unsigned y){
  unsigned result = 1;
  unsigned weight = x;
  while (y != 0) {
    if ( (y&1) == 1){
      result *= weight;      
    }
    y >>= 1;
    weight *= weight;
  }
  return result;
}

int main() {
  int x,y;
  std::cin>>x;std::cin>>y;
  std::cout<<"x^y:"<<power(x,y)<<std::endl;
  return 0;
}
