#include <iostream>

using namespace std;

int reverse(int x){
  int sign = 1;
  if (x<0) sign=-1;
  int result = 0;
  while (x>0) {
    result *= 10;
    result += x%10;
    x /= 10;
  }
  return result*sign;
}

int main(){
  int x;
  cin>>x;
  cout<<"reverse:"<<reverse(x)<<endl;
}
