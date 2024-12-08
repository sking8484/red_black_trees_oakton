#include <string>
using namespace std;

struct TreeNode {
  int info;             // Holds the value of the node.
  TreeNode *parent;     // Pointer to the parent node.
  TreeNode *left;       // Pointer to the left child.
  TreeNode *right;      // Pointer to the right child.
  string color;         // Color of the node (either "red" or "black").
};

class Tree {
public:
  // Constructor
  // Pre-condition: None.
  // Post-condition: Creates an empty tree with root initialized to nullptr.
  Tree();

  // Destructor
  // Pre-condition: None.
  // Post-condition: Deletes all nodes in the tree, freeing memory.
  ~Tree();

  // Visualizes the tree structure in the console.
  // Pre-condition: None.
  // Post-condition: Prints the tree's structure to the console, showing
  //                 nodes, their colors, and relationships.
  void VisualizeTree();

  // Performs a left rotation at the given node.
  // Pre-condition: The given node must have a non-null right child.
  // Post-condition: Performs a left rotation, updating parent-child
  //                 relationships and preserving tree properties.
  void LeftRotate(TreeNode* node);

  // Performs a right rotation at the given node.
  // Pre-condition: The given node must have a non-null left child.
  // Post-condition: Performs a right rotation, updating parent-child
  //                 relationships and preserving tree properties.
  void RightRotate(TreeNode* node);

  // Inserts a new value into the tree while maintaining Red-Black Tree properties.
  // Pre-condition: The tree may be empty or non-empty.
  // Post-condition: Inserts a new node with the specified value into the tree
  //                 and rebalances the tree to maintain Red-Black Tree properties.
  void insert(int data);

  // Removes a node with the specified value from the tree.
  // Pre-condition: The tree may contain or not contain the specified value.
  // Post-condition: Removes the node if it exists, rebalances the tree, and
  //                 maintains Red-Black Tree properties. If the value does
  //                 not exist, the tree remains unchanged.
  void remove(int value);

  // Searches for a node with the specified value in the tree.
  // Pre-condition: None.
  // Post-condition: Prints a message indicating whether the value exists in
  //                 the tree, along with its color if found.
  void search(int value);

private:
  TreeNode *root;

  // Recursively deletes all nodes in the tree.
  // Pre-condition: None.
  // Post-condition: Frees all memory associated with the tree nodes.
  void deleteTree(TreeNode* node);

  // Helper function for visualizing the tree structure.
  // Pre-condition: The tree may be empty or non-empty.
  // Post-condition: Recursively prints the tree's structure, with appropriate
  //                 formatting for left and right branches.
  void visualizeTreeHelper(string prefix, TreeNode *node, bool isLeft);
};
