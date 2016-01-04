#include <iostream>
#include <bitset>

using namespace std;

int ClosestInteger(int x) {
  //Find the bits for last one and last zero.
  //Alternate these two bits.
  if ((x==0)||(~x==0)) {
    throw invalid_argument("Error: All bits are 0 or 1.");
  }
  int nMaskLast1 = x&~(x-1);  
  int nMaskLast0 = ~x&~(~x-1); 
  return x^nMaskLast1^nMaskLast0;
}

int main() {
  cout<<"Input an integer:";
  int x;
  cin>>x;
  cout<<"bf:"<<bitset<32>(x)<<endl;
  try {
    cout<<"af:"<<bitset<32>(ClosestInteger(x))<<endl;
  } catch (const exception& e){
    cout<<e.what()<<endl;
  }
  return 0;
}
