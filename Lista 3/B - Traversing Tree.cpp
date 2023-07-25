#include <iostream>
using namespace std;

struct BSTNode {
  int element;
  struct BSTNode *left;
  struct BSTNode *right;
};

struct BSTNode *create_bstnode(int e) {
  struct BSTNode *node = (struct BSTNode *)malloc(sizeof(struct BSTNode));
  node->element = e;
  node->left = node->right = NULL;

  return node;
}

struct BSTNode *insert(struct BSTNode *bst, int e) {
  if (bst == NULL) {
    return create_bstnode(e);
  }

  if (e < bst->element) {
    bst->left = insert(bst->left, e);
  }

  else {
    bst->right = insert(bst->right, e);
  }

  return bst;
}

void pre(struct BSTNode *root) {
  if (root != NULL) {
    cout << " " << root->element;
    pre(root->left);
    pre(root->right);
  }
}

void in(struct BSTNode *root) {
  if (root != NULL) {
    in(root->left);
    cout << " " << root->element;
    in(root->right);
  }
}

void post(struct BSTNode *root) {
  if (root != NULL) {
    post(root->left);
    post(root->right);
    cout << " " << root->element;
  }
}

int main() {
  int n, valor;
  bool FIns = false;
  struct BSTNode *root = NULL;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> valor;

    if (FIns == false) {
      root = insert(root, valor);
      FIns = true;
    }

    else {
      insert(root, valor);
    }
  }

  cout << "Pre order :";
  pre(root);
  cout << "\n";

  cout << "In order  :";
  in(root);
  cout << "\n";

  cout << "Post order:";
  post(root);

  return 0;
}