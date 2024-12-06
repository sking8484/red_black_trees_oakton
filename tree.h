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

private:
  TreeNode *root;
};
