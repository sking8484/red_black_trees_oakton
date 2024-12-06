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
      std::cout << "\033[31m" << node->info << "\033[0m" << std::endl;
    } else {
      cout << node->info << std::endl;
    }

    // enter the next tree level - left and right branch
    visualizeTreeHelper(prefix + (isLeft ? "│   " : "    "), node->left, true);
    visualizeTreeHelper(prefix + (isLeft ? "│   " : "    "), node->right,
                        false);
  };
}

void Tree::VisualizeTree() { visualizeTreeHelper("", root, false); }
