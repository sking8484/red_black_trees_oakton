#include "tree.h"
#include <iostream>
using namespace std;
#include <string>
#include <vector>

void InitializeTree(TreeNode *root) {
  root->color = "black";
  root->info = 50;

  TreeNode *leftRoot;
  leftRoot = new TreeNode();
  leftRoot->color = "red";
  leftRoot->info = 25;

  TreeNode *leftLeftRoot;
  leftLeftRoot = new TreeNode();
  leftLeftRoot->color = "black";
  leftLeftRoot->info = 10;

  leftRoot->left = leftLeftRoot;

  TreeNode *leftLeftRightRoot;
  leftLeftRightRoot = new TreeNode();
  leftLeftRightRoot->color = "red";
  leftLeftRightRoot->info = 15;

  leftLeftRoot->right = leftLeftRightRoot;

  TreeNode *leftRightRoot;
  leftRightRoot = new TreeNode();
  leftRightRoot->color = "black";
  leftRightRoot->info = 30;

  leftRoot->right = leftRightRoot;

  root->left = leftRoot;

  TreeNode *rightRoot;
  rightRoot = new TreeNode();
  rightRoot->color = "black";
  rightRoot->info = 60;

  TreeNode *rightLeftRoot;
  rightLeftRoot = new TreeNode();
  rightLeftRoot->color = "red";
  rightLeftRoot->info = 55;

  TreeNode *rightRightRoot;
  rightRightRoot = new TreeNode();
  rightRightRoot->color = "red";
  rightRightRoot->info = 65;

  rightRoot->left = rightLeftRoot;
  rightRoot->right = rightRightRoot;
  root->right = rightRoot;
}

Tree::Tree() {
  TreeNode *treeRoot;
  treeRoot = new TreeNode();
  InitializeTree(treeRoot);

  root = treeRoot;
}

void visualizeTreeHelper(string prefix, TreeNode *node, bool isLeft) {
  if (node != nullptr) {
    std::cout << prefix;

    std::cout << (isLeft ? "├──" : "└──");

    // print the value of the node
    if (node->color == "red") {
        std::cout << "\033[31m" << node->info << "\033[0m" << node->color << std::endl;
    } else {
        std::cout << node->info << " " << node->color <<  std::endl;
    }

    // enter the next tree level - left and right branch
    visualizeTreeHelper(prefix + (isLeft ? "│   " : "    "), node->left, true);
    visualizeTreeHelper(prefix + (isLeft ? "│   " : "    "), node->right,
                        false);
  };
}

void Tree::VisualizeTree() { visualizeTreeHelper("", root, false); }

void Tree::LeftRotate(TreeNode* node) {
    TreeNode* nodeRight = node->right;
    node->right = nodeRight->left;
    
    if (nodeRight->left != NULL) {
        nodeRight->left->parent = node;
    }
    
    nodeRight->parent = node->parent;
    
    if(node->parent == NULL) {
        root = nodeRight;
    } else if (node == node->parent->left) {
        node->parent->left = nodeRight;
    } else {
        node->parent->right = nodeRight;
    }
    
    nodeRight->left = node;
    node->parent = nodeRight;
}

void Tree::RightRotate(TreeNode* node) {
    TreeNode* nodeLeft = node->left;
    node->left = nodeLeft->right;
    
    if (nodeLeft->right != NULL) {
        nodeLeft->right->parent = node;
    }
    
    nodeLeft->parent = node->parent;
    
    if (node->parent == NULL) {
        root = nodeLeft;
    } else if (node == node->parent->right) {
        node->parent->right = nodeLeft;
    } else {
        node->parent->left = nodeLeft;
    }
    
    nodeLeft->right = node;
    node->parent = nodeLeft;
}

void Tree::insert(int info) {
    
    TreeNode* newNode = new TreeNode(info);
    newNode->left = NULL;
    newNode->right = NULL;
        
}
