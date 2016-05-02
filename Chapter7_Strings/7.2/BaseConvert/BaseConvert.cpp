#include <string>
#include <vector>
#include <cmath>
#include <cassert>

#include <iostream>

using namespace std;

//Assume b1,b2 are in [2,10] for practice purpose.
//Assume strNum is non-negative.

string BaseConvert(const string& strNum, const int& b1, const int&b2){
  assert(b1 >= 2 && b1 <= 10 && b2 >= 2 && b2 <= 10);

  //output size: log_b2((size of input)^b1)
  vector<int> vecResult(ceil(strNum.size()*log(b1)/log(b2)),0);

  //conversion.
  for (int i = 0; i < strNum.size(); i++){
    int i_rev = strNum.size() - 1 -i; //True digit index.
    assert(strNum[i_rev] >= '0' && strNum[i_rev] < '0' + b1);
    //Get b1^strNum[i] and convert it to base b2.
    int digit = (strNum[i_rev] - '0')* pow(b1, i);
    int j = 0;
    while (digit) {
      vecResult[j] += digit%b2;
      vecResult[j+1] += vecResult[j]/b2;
      vecResult[j] %= b2;
      digit /= b2;
      j++;
    }
  }
  
  //return output.
  string result;
  for (int i =vecResult.size() - 1; i >= 0; i--){
    cout<<vecResult[i];
    result.push_back(vecResult[i]);
  }
  return result;
} 

int main(){
  string num("1000001");
  int b1 = 2, b2 = 10;
  cout<<BaseConvert(num, b1, b2)<<endl;
}
