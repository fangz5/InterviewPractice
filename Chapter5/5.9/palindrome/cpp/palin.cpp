#include <iostream>
#include <cmath>

bool isPalin(int x){
  if (x<0) return false;
  if (x==0) return true;

  int denom = pow(10,static_cast<int>(log10(x))) ;
  while (x>9) {
    int leftDigit = x/denom;
    int rightDigit = x%10;
    using namespace std;
    cout<<leftDigit<<":"<<rightDigit<<endl;
    if (leftDigit != rightDigit) return false;
    x %= denom;
    x /= 10;
    cout<<"x:"<<x<<endl;
    denom /= 100;   
  }
  return true;
}

int main(){
  using namespace std;
  while (1) {
    int x;
    cin>>x;
    if (x==-1) return 0;
    if (isPalin(x)){ 
      cout<<"true"<<endl;
    }else{
      cout<<"false"<<endl;
    }    
  }
}
