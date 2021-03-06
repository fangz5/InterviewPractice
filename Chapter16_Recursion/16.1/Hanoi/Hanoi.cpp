#include <iostream>

using namespace std;

void MoveHanoi(const char& cPeg1, const int& top, const int& bottom, const char& cPeg2){
  char cPeg3;
  if (cPeg1 != 'A' && cPeg2 != 'A') cPeg3 = 'A';
  else if (cPeg1 != 'B' && cPeg2 != 'B') cPeg3 = 'B';
  else cPeg3 = 'C';

  if (top == bottom){
    cout<<"Move "<<top<<" from "<<cPeg1<<" to "<<cPeg2<<endl;
  }else{
    MoveHanoi(cPeg1, top, bottom - 1, cPeg3);
    MoveHanoi(cPeg1, bottom, bottom, cPeg2);
    MoveHanoi(cPeg3, top, bottom - 1, cPeg2);
  }
}

int main(){
  MoveHanoi('A', 1, 5, 'B');
}
