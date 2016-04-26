#include <iostream>
#include <string>

//In this code, format checking is ignored.

using namespace std;

bool StringToInt(const string& strNum, int &intNum){
  //  cout<<"Input: strNum = "<<strNum<<endl;
  int sign = 1;
  intNum = 0;
  if (strNum[0] == '-') sign = -1;
  for (int i = sign == 1?0:1; i<strNum.size(); i++) {
    intNum = intNum * 10 + (int)(strNum[i]-'0');
  //  cout<<"i:"<<i<<"\t intNum:"<<intNum<<"strNum[i]"<<strNum[i]<<endl;
  }
  intNum *= sign;

  return true;
}

bool IntToString(int intNum, string& strNum){
  strNum.clear();
  int sign = 1;
  if (intNum < 0) {
    sign = -1;
    intNum = -intNum;
  }
  do {
    int lastDigit = intNum%10;
    intNum = intNum/10;
    strNum = (char)('0'+lastDigit)+strNum;
  } while (intNum > 0);
  if (sign == -1) strNum = '-'+strNum;
  
  return true;
}

int main(){
  for (int i=-1000; i<1000; i+=125) {
    string myString;
    int myInt;
    IntToString(i,myString);
    StringToInt(myString,myInt);
    cout<<"i:"<<i<<"\t myString:"<<myString<<"\t myInt:"<<myInt<<endl;
  }
}
