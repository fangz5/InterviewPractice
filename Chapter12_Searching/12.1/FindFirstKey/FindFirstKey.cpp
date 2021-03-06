#include <iostream>
#include <vector>

using namespace std;

int FindFirstKey(const vector<int> &sortedArray, const int &key){
  int left = 0, right = sortedArray.size();
  int result = -1;
  while (left <= right) {
    int mid = left + (right - left)/2;
    if (sortedArray[mid] == key) {
      result = mid;
      right = mid - 1;
    } else if (sortedArray[mid] < key) {
      left = mid + 1;
    } else if (sortedArray[mid] > key) {
      right = mid - 1;
    }
  }
  return result;
} 

int main(){
  vector<int> a = {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
  cout<<FindFirstKey(a, 99)<<endl;

  return 0;
}
