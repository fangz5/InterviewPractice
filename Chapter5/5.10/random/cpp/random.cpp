#include <iostream>
#include <stdlib.h>
#include <cmath>

int oneBitRand(){
  return rand()%2;
}

int myRand(int a, int b){
  int range=b-a;
  int result=0;
  do {
    result = 0;
    for (int i=0; i<log(range)/log(2)+1; i++){
      result <<= 1;
      result += oneBitRand();      
    }
  } while (result > range);
  return result+a;
}

int main(){
  using namespace std;
  int a,b,loops;
  while (1) {
    cin>>a;cin>>b;cin>>loops;
    if (a==b) return 0;

    int * array = new int[b-a+1];
    memset(array,0,(b-a+1)*sizeof(int));
    for (int i=0; i<loops; i++) array[myRand(a,b)-a]++;
    for (int i=0; i<=b-a; i++) {
      cout<<i<<":"<<array[i]<<"|";
    }
    cout<<endl;
    delete(array);
  }
}
