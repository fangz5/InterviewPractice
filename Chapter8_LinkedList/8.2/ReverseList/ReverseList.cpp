#include <cstdint>
#include <iostream>

struct Node{
  int16_t data;
  Node* next = NULL;
};

Node* ReverseOrder(Node* ptrOldList){
  Node* ptrNewList = NULL;
  while (ptrOldList){
    auto ptrCurrent = ptrOldList;
    ptrOldList = ptrOldList->next;
    ptrCurrent->next = ptrNewList;
    ptrNewList = ptrCurrent;
  }
  return ptrNewList;
}

int main(){
  Node a,b,c,d;
  a.data = 1, b.data = 3, c.data = 7, d.data =5;
  a.next = &b, b.next =&c, c.next = &d;
  auto ptrResult = ReverseOrder(&a);
  while (ptrResult){
    std::cout<<ptrResult->data<<std::endl;
    ptrResult = ptrResult->next;
  }
}
