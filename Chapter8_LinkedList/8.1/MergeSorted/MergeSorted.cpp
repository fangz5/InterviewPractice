#include <iostream>

using namespace std;

class ListNode {
public:
  int data;
  ListNode* next;
public:
  ListNode(){next = NULL;};
};

ListNode* MergeLists(ListNode* l1, ListNode* l2) {
  ListNode* result=NULL;
  //Check if any list is NULL.
  if (!l1) {
    result = l2;
    return result;
  } else if (!l2) {
    result = l1;
    return result;
  }

  //Set ptr to resulting list.
  if (l1->data < l2->data) {
    result = l1;
    l1 = l1->next;
  } else {
    result = l2;
    l2 = l2->next;
  }

  ListNode* current = result;
  //Add nodes to resulting list.
  while (l1&&l2) {
    //    cout<<"l1:"<<l1->data<<"\t l2:"<<l2->data<<endl;
    if (l1->data < l2->data) {
      current->next = l1;
      l1 = l1->next;
    } else {
      current->next = l2;
      l2 = l2->next;
    }
    current = current->next;
  }
  if (!l1) {
    current->next = l2;
  } else {
    current->next = l1;
  }

  return result;
}

void PrintList(ListNode* ptr){
  while (ptr) {
    cout<<ptr->data;
    ptr = ptr->next;
  }
  cout<<endl;
}

int main(){
  ListNode a,b,c,d,e,f;
  a.data = 1;
  b.data = 2;
  c.data = 3;
  d.data = 4;
  e.data = 5;
  f.data = 6;
  
  a.next = &b;
  b.next = &f;
  c.next = &d;
  d.next = &e;

  PrintList(&a);
  PrintList(&c);

  ListNode* result = MergeLists(&a,&c);
  //  cout<<"ok"<<endl;
  PrintList(result);
}
