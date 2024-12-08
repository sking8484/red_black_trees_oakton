#include <string>
using namespace std;

struct TreeNode
{
  int info;
  TreeNode *parent;
  TreeNode *left;
  TreeNode *right;
  string color;
};

class Tree
{
public:
  Tree();
  ~Tree();
  void VisualizeTree();
  void LeftRotate(TreeNode *node);
  void RightRotate(TreeNode *node);
  void insert(int data);
  void remove(int value);
  void search(int value);

private:
  TreeNode *root;
  void deleteTree(TreeNode *node);
  void visualizeTreeHelper(string prefix, TreeNode *node, bool isLeft);
};
