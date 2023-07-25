#include <iostream>
using namespace std;

struct BSTNode {
  long long int element;
  long long int height;
  long long int left_child;
  long long int right_child;
  struct BSTNode *left;
  struct BSTNode *right;
};

struct BSTNode *create_bstnode(long long int e) {
  struct BSTNode *node = (struct BSTNode *)malloc(sizeof(struct BSTNode));
  node->element = e;
  node->left = node->right = NULL;
  node->height = 1;
  node->left_child = node->right_child = 0;

  return node;
}

long long int h(struct BSTNode *bst){
  if (bst == NULL){
    return 0;
  }
  else{
    return bst->height;
  }
}

long long int getBalance(struct BSTNode *bst){
  if (bst == NULL){
    return 0;
  }
  return h(bst->left) - h(bst->right);
}

struct BSTNode *rightRotate(struct BSTNode *bst){
  struct BSTNode *l = bst->left;
  struct BSTNode *lr = l->right;
 
  l->right = bst;
  bst->left = lr;
 
  bst->height = max(h(bst->left), h(bst->right)) + 1;
  l->height = max(h(l->left), h(l->right)) + 1;

  bst->left_child = l->right_child;
  l->right_child = (bst->right_child + bst->left_child) + 1;

  return l;
}

struct BSTNode *leftRotate(struct BSTNode *bst){
  struct BSTNode *r = bst->right;
  struct BSTNode *rl = r->left;
 
  r->left = bst;
  bst->right = rl;
 
  bst->height = max(h(bst->left), h(bst->right)) + 1;
  r->height = max(h(r->left), h(r->right)) + 1;

  bst->right_child = r->left_child;
  r->left_child = (bst->left_child + bst->right_child) + 1;

  return r;
}

struct BSTNode *insert(struct BSTNode *bst, long long int e) {
  if (bst == NULL) {
    return create_bstnode(e);
  }

  if (e < bst->element) {
    bst->left = insert(bst->left, e);
  }

  else if(e > bst->element){
    bst->right = insert(bst->right, e);
  }
  
  else{
    return bst;
  }

  bst->height = max(h(bst->left), h(bst->right)) + 1;
  if (bst->right != NULL){
    bst->right_child = (bst->right->right_child) + (bst->right->left_child) + 1;
  }

  if (bst->left != NULL){
    bst->left_child = (bst->left->right_child) + (bst->left->left_child) + 1;
  }

  long long int balance = getBalance(bst);
  
  if (balance > 1 && e < bst->left->element){ // left rotation
    return rightRotate(bst);
  }

  if (balance < -1 && e > bst->right->element){ // right rotation
    return leftRotate(bst); 
  }

  if (balance > 1 && e > bst->left->element){ // left right rotation
    bst->left = leftRotate(bst->left);
    return rightRotate(bst);
  }
 
  if (balance < -1 && e < bst->right->element){ // right left rotation
    bst->right = rightRotate(bst->right);
    return leftRotate(bst);
  }

  return bst;
}

bool exist(struct BSTNode *bst, long long int e){
  if(bst == NULL){
    return false;
  }

  if(bst->element == e){
    return true;
  }
  else if(bst->element < e){
    return exist(bst->right,e);
  }
  else{
    return exist(bst->left,e);
  }
}

long long int index(struct BSTNode *bst, long long int val){
  if(bst->element == val){
    return bst->left_child + 1;
  }

  else if(bst->element < val){
    return (bst->left_child) + 1 + index(bst->right, val);
  }

  else{
    return index(bst->left, val);
  }
}

int main() {
  long long int queries, op, val;
  cin >> queries;
  struct BSTNode *root = NULL;
  for (long long int i = 0; i < queries; i++) {
    cin >> op >> val;
    if (op == 1) { // insert
      root = insert(root, val);
    } 
    else if (op == 2) { // find index

      if (exist(root, val) == false){
        cout << "Data tidak ada" << "\n";
      }

      else{
        cout << index(root, val) << "\n";
      }
    }
  }
}