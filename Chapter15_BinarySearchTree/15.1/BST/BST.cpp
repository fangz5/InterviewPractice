#include <vector>
#include <cstdint>
#include <iostream>

using namespace std;

/*
There are 3 ways to implement this (see README.TXT).
We use tree traversal here.
*/

template<typename T>
struct Node{
	T data;
	Node *left = nullptr, *right = nullptr;
};

void TraverseSave(const Node<int32_t>* root, std::vector<int32_t>& v){
	if (!root) return;
	else {
		TraverseSave(root->left, v);
		v.push_back(root->data);
		TraverseSave(root->right, v);
	}
}

bool IsBST(const Node<int32_t>* root){
	std::vector<int32_t> v;
	TraverseSave(root,v);
	for (int32_t i = 0; i < v.size() - 1; i++){
		if (v[i] > v[i+1]) return false;
	}
	return true;
}

int main(){
	Node<int32_t> a,b,c,d,e,f;
	a.data = 1, b.data = 2, c.data = 3, d.data = 4, e.data = 3, f.data = 5;
	b.left = &a, b.right = &c, d.left = &b, d.right = &f, f.left = &e;
	cout<<IsBST(&d)<<endl;
}