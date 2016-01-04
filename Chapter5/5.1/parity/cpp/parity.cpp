#include <iostream>
#include <bitset>

using namespace std;

short parity(long x) {
  short result = 0;
  while (x != 0) {
    result ^= 1;
    x &= x - 1;
  }
  return result;
}

int main() {
  long x = 0xF0F0000F;
  cout<<bitset<64>(x)<<" has parity "<<parity(x)<<endl;
}
