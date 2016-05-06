#include <cstdint>
#include <iostream>

using namespace std;

template<typename T>
struct Node{
  T data;
  Node* left = nullptr;
  Node* right = NULL;
};

bool AreMirrorImages(const Node<int32_t>* left,const Node<int32_t>* right){
  if (left == NULL && right == NULL) 
    return true;
  else if ( (left == NULL && right != NULL) || (left != NULL && right == NULL) ) 
    return false;
  else {
    return left->data == right->data && AreMirrorImages(left->left, right->right) &&AreMirrorImages(left->right, right->left);
  }
}

bool IsSymTree(const Node<int32_t>* root){
  return root == NULL || AreMirrorImages(root->left, root->right);
}

int main(){
  Node<int32_t> a,b,c,d,e,f;
  a.data = 0, a.left = &b, a.right = &c;
  b.data = 1, b.left = &d;
  c.data = 1, c.right = &e;
  d.data = 3, d.right = &f;
  e.data = 3;
  cout<<IsSymTree(&a)<<endl;
}
