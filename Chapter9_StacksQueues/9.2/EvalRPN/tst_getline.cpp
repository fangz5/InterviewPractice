#include <sstream>
#include <iostream>

int main(){
  std::istringstream input("Today is not Thursday.");
  std::string token;
  while (std::getline(input,token,' ')){
    std::cout<<token<<std::endl;
    std::cout<<input.str()<<std::endl;
  }
}
