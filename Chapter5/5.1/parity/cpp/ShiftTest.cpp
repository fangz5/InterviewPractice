#include <iostream>
#include <bitset>

using namespace std;

int main() {
  int a = -16;
  cout << bitset<32>(a<<1)<<endl;
  cout << bitset<32>(a>>1)<<endl;
}
