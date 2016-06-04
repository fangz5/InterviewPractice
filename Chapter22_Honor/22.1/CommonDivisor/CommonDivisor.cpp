#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>

using namespace std;

int32_t CommonDivisor(int32_t a, int32_t b){
  if (a==b) return a;
  else {
    if (a > b) swap(a,b);
    int32_t c = a;
    while (b - c > a){
      c += c;      
    }
    if (b - c <= 0) c /= 2;
    return CommonDivisor(a, b-c);
  }
}

int32_t main(){
  int32_t a,b;
  cin>>a;
  cin>>b;
  cout<<"Max common divisor of "<<a<<" and "<<b<<" is "<<CommonDivisor(a,b)<<endl;
}
