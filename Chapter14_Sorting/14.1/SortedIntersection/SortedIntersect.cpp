#include <iostream>
#include <vector>

using namespace std;

void Intersect(const vector<int>& A, const vector<int>& B, vector<int>& result){
  //Init.
  result.clear();
  int index_A = 0, index_B = 0;

  while ( (index_A < A.size())&&(index_B < B.size()) ){
    if (A[index_A] < B[index_B]) {
      index_A++;
    }else if (A[index_A] > B[index_B]){
      index_B++;
    }else{
      if (result.empty()) {
	result.push_back(A[index_A]);
      }else if (A[index_A] > result[result.size()-1]) {
	result.push_back(A[index_A]);
      }
      index_A++;
      index_B++;
    }
  }
}

int main(){
  vector<int> A = {1,1,3,5,5,8,9,9,9,10}, B = {2,3,5,7,9,10};
  vector<int> C;
  Intersect(A,B,C);
  for (int i = 0; i < C.size(); i++){
    cout<<C[i]<<" ";
  }
  cout<<endl;
}
