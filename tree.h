#include <string>
#include <vector>
using namespace std;

struct TreeNode {
  int info;
  TreeNode *parent;
  TreeNode *left;
  TreeNode *right;
  string color;
};

class Tree {
public:
  Tree();
  void VisualizeTree();
  void LeftRotate(TreeNode* node);
  void RightRotate(TreeNode* node);
  void insert(int data);
  void setRoot(TreeNode* node);

private:
  TreeNode *root;
};
