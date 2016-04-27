#include <iostream>

using namespace std;

template <typename T>
class BinaryTreeNode{
public:
  T data;
  BinaryTreeNode<T> *left, *right;
  BinaryTreeNode(){
    data = 0;
    left = NULL;
    right = NULL;
  }
};

int GetDepth(BinaryTreeNode<int>* root);

bool IsBalanced(BinaryTreeNode<int>* root){
  if (!root) return true;
  /*
    root is balanced <==> root->left is blanced && root->right is balanced && ||root->left| - |root->right|| <= 1
   */
  if (IsBalanced(root->left)&&IsBalanced(root->right)
      &&(abs(GetDepth(root->left)-GetDepth(root->right))<=1)) {
    return true;
  }else{
    return false;
  }
}

int GetDepth(BinaryTreeNode<int>* root){
  if (!root) {
    return 0;
  }else{
    //root+left_branch+right_branch
    return 1+max(GetDepth(root->left),GetDepth(root->right));
  }
}

int main(){
  BinaryTreeNode<int> a,b,c,d,e,f,A,B,C,D,E,F;
  a.left = &b, a.right = &c;
  b.left = &d, b.right = &e, d.left = &f;
  
  A.left = &B, A.right = &C;
  B.left = &D, B.right = &E, C.left = &F;

  cout<<IsBalanced(&a)<<endl;
  cout<<IsBalanced(&A)<<endl;

  return 0;
}
