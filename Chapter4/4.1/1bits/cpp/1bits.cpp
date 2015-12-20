#include <iostream>
#include <bitset>

int numberOneBits(const int n) {
  int numOnes = 0;
  for (int i = 0; i < sizeof(int)*8; i++) {
    int m = 1 << i;
    if ((n & m) == m) {
      numOnes++;
    }
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
