#include <iostream>
#include <stack>

using namespace std;

/*
Use max_count_ (stacks of integer pairs) to store the history of Max.
Each integer pair represent a history period, while the first integer
represents Max value on that period, and the second integer represents
length of the period.  
*/

class Stack{
private:
  stack<int> elements_;
  stack<pair<int,int> > max_count_;
public:
  void pop(){
    if (empty()) {
      throw length_error("pop(): empty stack");
    } else {
      elements_.pop();
      if (max_count_.top().second > 1) {
        max_count_.top().second -= 1;
      } else {
        max_count_.pop();
      }
    }       
  }
  void push(const int& num){
    elements_.push(num);
//    cout<<"ok"<<endl;
    if (max_count_.empty()) {
      //Init.
      max_count_.push(make_pair(num,1));
      cout<<"init"<<endl;
    }else {
      //Same history period(same Max).
      if (num <= getMax()){
	max_count_.top().second += 1;
      }else {
      //New history period(new Max).
	max_count_.push(make_pair(num,1));
      }
    }
  }
  bool empty(){
    return elements_.empty();
  }
  int getMax(){
    if (empty()) {
      throw length_error("getMax(): empty stack");
    }else {
      return max_count_.top().first;
    }
  }
};

int main(){
  Stack myStack;
  stack<pair<int,int> > testStack;
  for (int i=0; i<10; i++){
    testStack.push(make_pair(i,i));
  }
  for (int i=0; i<10; i++){
    myStack.push(i%7);
  }
  while (!myStack.empty()){
    cout<<"Top:"<<myStack.getMax()<<endl;
    myStack.pop();
  }
  return 0;
}
