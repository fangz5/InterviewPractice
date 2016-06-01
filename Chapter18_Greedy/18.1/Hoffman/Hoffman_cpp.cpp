#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

struct Node{
  double freq;
  char ch;
  Node *left, *right;
};

struct Cmp{
  bool operator()(const Node* left, const Node* right) const{
    return left->freq > right->freq;
  }
};

Node* BuildTree(){
  //Read source file into 26 leaf-nodes.
  ifstream in("source.txt");
  if (!in) {
    cerr<<"source.txt cannot be opened."<<endl;
    throw -1;
  }
  priority_queue<Node*, vector<Node*>, Cmp> pq;
  char letter;
  double freq;
  while (!in.eof()){
    in>>letter>>freq;
    pq.push(new Node{freq, letter, nullptr, nullptr});
  }
  in.close();

  //Build Tree.
  while (pq.size() > 1) {
    Node* left = pq.top();
    pq.pop();
    Node* right = pq.top();
    pq.pop();
    pq.push(new Node{left->freq + right->freq, '*', left, right});
    //    cout<<pq.top()->freq<<endl;
  }
  return pq.top();
}

void GenerateCodes(const Node* root, const string& path){
  if (root->ch != '*') {
    cout<<root->ch<<":"<<path<<endl;
  } else {
    GenerateCodes(root->left, path+"0");
    GenerateCodes(root->right, path+"1");
  }
}

int main(){
  //Build Hoffman Tree
  Node *root = BuildTree();

  //Generate Hoffman Codes
  GenerateCodes(root,"");

  return 0;
}
