#include <vector>
#include <iostream>

using namespace std;

void inc(vector<int> &numVector){
  int digit = 0;
  while (1){
    switch(numVector[digit]){
    case 9:
      numVector[digit] = 0;
      if (digit < numVector.size() - 1) {
	digit++;
	break;
      } else {
	numVector.push_back(1);
	return;
      }
    default:
      numVector[digit]++;
      return;
    }
  }
}

int main(){
  vector<int> number;
  number.push_back(0);
  for (int i = 0; i < 10000; i++) {
    inc(number);

    for (int j = number.size() - 1; j >= 0; j--){
      cout<<number[j];
    }
    cout<<endl;

  }
}
