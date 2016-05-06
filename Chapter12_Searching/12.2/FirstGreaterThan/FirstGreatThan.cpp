#include <vector>
#include <cstdint>
#include <iostream>

using namespace std;

int32_t FirstGreaterThan(const vector<int32_t>& sortedArray, const int32_t& key){
  if (sortedArray[0] > key) return 0;
  else if (sortedArray.back() <= key) return -1;
  int32_t begin = 0, end = sortedArray.size() - 1;
  while (begin < end - 1) {
    int mid = begin + (end - begin)/2;
    if (sortedArray[mid] > key){
      end = mid;
    }else{
      begin = mid;
    }
  }
  return end;
}

int main(){
  vector<int32_t> A = {1,3,5,7,9,10,20};
  cout<<FirstGreaterThan(A, -20)<<endl;
}
