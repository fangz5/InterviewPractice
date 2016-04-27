#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct HeapNode {
  int vectorIndex;
  int tradeIndex;
  int tradeTime;
};

//Overload "<", which corresponds to default comparison method in priority_queue.
bool operator<(const HeapNode &left, const HeapNode &right){
  return left.tradeTime > right.tradeTime;
}

void MergedSort(const vector<vector<int> > vectors, vector<int> &result){
  //Init
  result.clear();
  //Build min_heap
  priority_queue<HeapNode, vector<HeapNode>, less<HeapNode> > min_heap;
  for (int i=0; i<vectors.size(); i++) {
    if (!vectors[i].empty()) {
      HeapNode newNode;
      newNode.vectorIndex = i;
      newNode.tradeIndex = 0;
      newNode.tradeTime = vectors[i].at(0);
      min_heap.push(newNode);
    }
  }  

  //Store result.
  while (!min_heap.empty()) {
    result.push_back(min_heap.top().tradeTime);
    HeapNode poppedNode = min_heap.top();
    min_heap.pop();
    if (poppedNode.tradeIndex < vectors[poppedNode.vectorIndex].size()-1) {
      //Insert next element in the removed vector to the min_heap.
      poppedNode.tradeIndex++;
      poppedNode.tradeTime = vectors[poppedNode.vectorIndex].at(poppedNode.tradeIndex);
      min_heap.push(poppedNode);
    }
  }

  return;
}

int main(){
  vector<int> a={1,4,7,10}, b={2,5,8}, c={3,6,9};
  vector<vector<int> > vectors={a,b,c};

  vector<int> result;
  MergedSort(vectors,result);

  for (int i=0;i<result.size();i++) {
    cout<<result[i];
  }
  cout<<endl;

  return 0;
}
