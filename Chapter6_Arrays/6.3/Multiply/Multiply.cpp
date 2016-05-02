#include <vector>
#include <iostream>

using namespace std;

vector<int> multiply(const vector<int>& a, const vector<int>& b){
  vector<int> result(a.size() + b.size(), 0);
  for (int i = 0; i < a.size(); i++){
    for (int j = 0; j < b.size(); j++){
      result[i+j] += a[i] * b[j];
      result[i+j+1] += result[i+j] / 10;
      result[i+j] %= 10;
    }
  }

  //remove leading 0, if exists.
  if (!result.back()) result.pop_back();

  return result;
}

int main(){
  vector<int> a = {0, 0, 5, 9}, b = {1, 0, 5, 8};
  vector<int> c = multiply(a,b);
  for (int i = c.size() - 1; i >= 0; i--){
    cout<<c[i];
  } 
  cout<<endl;
}
