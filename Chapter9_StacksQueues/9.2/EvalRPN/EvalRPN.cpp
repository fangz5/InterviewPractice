#include <sstream>
#include <stack>
#include <string>
#include <cstdint>

#include <iostream>

using namespace std;

int32_t EvalRPN(string RPN){
  istringstream istreamRPN(RPN);
  stack<int32_t> tempResults;
  string token;
  while (getline(istreamRPN, token, ',')){
    if (token == "+" || token == "-" || token == "x" || token == "/") {
      int y = tempResults.top();
      tempResults.pop();
      int x = tempResults.top();
      tempResults.pop();
      switch(token.front()){
      case '+':
	tempResults.emplace(x+y);
	break;
      case '-':
	tempResults.emplace(x-y);
	break;
      case 'x':
	tempResults.emplace(x*y);
	break;
      case '/':
	tempResults.emplace(x/y);
	break;
      default:;
	//Throw error.
      }
    }else{//Token is a number.
      tempResults.emplace(stoi(token));
    }
  }
  return tempResults.empty()?0:tempResults.top();
}

int main(){
  string RPN("1,1,+,2,x,3,1,-,x");
  cout<<EvalRPN(RPN)<<endl;
}
