#include <iostream>
#include <bitset>

int numberOneBits(int n) {
  using namespace std;
  int numOnes = 0;
  while (n != 0) {
    numOnes++;    
    int lastOneBit = n & ~(n-1);
    cout<<"********************************"<<endl;
    cout<<"n:"<<bitset<32>(n)<<endl;
    cout<<"m:"<<bitset<32>(~(n-1))<<endl;
    cout<<"b:"<<bitset<32>(lastOneBit)<<endl;
    n = n ^ lastOneBit;
  }
  return numOnes;
}

int main(){
  using namespace std;
  int n;
  cout<<"Input an integer value:"<<endl;
  cin>>n;
  cout<<n<<"("<<sizeof(int)<<" bytes)"<<" in binary form is "<<bitset<32>(n)<<endl;
  cout<<n<<" has "<<numberOneBits(n)<<" bits set to 1."<<endl;
}
