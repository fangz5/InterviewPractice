#include <iostream>
#include <bitset>

using namespace std;

short parity(long long x) {
  x ^= x>>32;
  x ^= x>>16;
  x ^= x>>8;
  x ^= x>>4;
  x ^= x>>2;
  x ^= x>>1;
  return x & 0x1;
}

int main() {
  long long x = 0xF0F00011;
  cout<<bitset<64>(x)<<" has parity "<<parity(x)<<endl;
}
