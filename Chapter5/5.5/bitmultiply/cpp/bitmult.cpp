#include <iostream>

using namespace std;

unsigned add(unsigned, unsigned);

unsigned multiply(unsigned x, unsigned y) {
  unsigned sum = 0;
  while (y != 0) {
    if ( (y&1) == 1 ) {
      sum = add(sum, x);
    }
    x <<= 1; y >>= 1;
  }
  return sum;
}

unsigned add(unsigned x, unsigned y) {
  unsigned sum = 0, nMask = 1, xBit = 0, yBit = 0;
  unsigned carry = 0;
  while ( (x != 0) || (y != 0) || (carry != 0) ) {
    xBit = x&nMask; yBit=y&nMask;
    sum |= xBit^yBit^carry;
    carry = (xBit&yBit)|(yBit&carry)|(carry&xBit);
    carry <<= 1;
    x &= ~nMask;
    y &= ~nMask;
    nMask <<= 1;
  }
  return sum;
}

int main() {
  unsigned x,y;
  cin>>x;
  cin>>y;
  cout<<"Product:"<<multiply(x,y)<<endl;
}
