#include "tree.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

Tree::Tree()
{
    root = nullptr;
}

Tree::~Tree()
{
    deleteTree(root);
}

void Tree::deleteTree(TreeNode *node)
{
    if (node)
    {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

void Tree::visualizeTreeHelper(string prefix, TreeNode *node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──");

        // print the value of the node
        if (node->color == "red")
        {
            std::cout << "\033[31m" << node->info << "\033[0m" << " " << node->color << std::endl;
        }
        else
        {
            std::cout << node->info << " " << node->color << std::endl;
        }

        // enter the next tree level - left and right branch
        visualizeTreeHelper(prefix + (isLeft ? "│   " : "    "), node->left, true);
        visualizeTreeHelper(prefix + (isLeft ? "│   " : "    "), node->right,
                            false);
    };
}

void Tree::VisualizeTree() { visualizeTreeHelper("", root, false); }

void Tree::LeftRotate(TreeNode *node)
{
    TreeNode *nodeRight = node->right;
    node->right = nodeRight->left;

    if (nodeRight->left != NULL)
    {
        nodeRight->left->parent = node;
    }

    nodeRight->parent = node->parent;

    if (node->parent == NULL)
    {
        root = nodeRight;
    }
    else if (node == node->parent->left)
    {
        node->parent->left = nodeRight;
    }
    else
    {
        node->parent->right = nodeRight;
    }

    nodeRight->left = node;
    node->parent = nodeRight;
}

void Tree::RightRotate(TreeNode *node)
{
    TreeNode *nodeLeft = node->left;
    node->left = nodeLeft->right;

    if (nodeLeft->right != NULL)
    {
        nodeLeft->right->parent = node;
    }

    nodeLeft->parent = node->parent;

    if (node->parent == NULL)
    {
        root = nodeLeft;
    }
    else if (node == node->parent->right)
    {
        node->parent->right = nodeLeft;
    }
    else
    {
        node->parent->left = nodeLeft;
    }

    nodeLeft->right = node;
    node->parent = nodeLeft;
}

void Tree::insert(int info)
{
    // Create new node
    TreeNode *newNode = new TreeNode();
    newNode->info = info;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->color = "red";

    // If tree is empty, make this the root
    if (root == nullptr)
    {
        root = newNode;
        newNode->color = "black";
        return;
    }

    // Find insertion point
    TreeNode *current = root;
    TreeNode *parent = nullptr;
    while (current != nullptr)
    {
        parent = current;
        if (info < current->info)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    // Link the new node
    newNode->parent = parent;
    if (info < parent->info)
    {
        parent->left = newNode;
    }
    else
    {
        parent->right = newNode;
    }

    // Rebalance the tree
    while (newNode != root && parent->color == "red")
    {
        TreeNode *grandparent = parent->parent;

        if (parent == grandparent->left)
        {
            TreeNode *uncle = grandparent->right;

            if (uncle != nullptr && uncle->color == "red")
            {
                parent->color = "black";
                uncle->color = "black";
                grandparent->color = "red";
                newNode = grandparent;
                parent = newNode->parent;
            }
            else
            {
                if (newNode == parent->right)
                {
                    LeftRotate(parent);

                    // Manual swap
                    TreeNode *temp = newNode;
                    newNode = parent;
                    parent = temp;
                }

                parent->color = "black";
                grandparent->color = "red";
                RightRotate(grandparent);
            }
        }
        else
        {
            TreeNode *uncle = grandparent->left;

            if (uncle != nullptr && uncle->color == "red")
            {
                parent->color = "black";
                uncle->color = "black";
                grandparent->color = "red";
                newNode = grandparent;
                parent = newNode->parent;
            }
            else
            {
                if (newNode == parent->left)
                {
                    RightRotate(parent);

                    TreeNode *temp = newNode;
                    newNode = parent;
                    parent = temp;
                }

                parent->color = "black";
                grandparent->color = "red";
                LeftRotate(grandparent);
            }
        }

        if (parent == nullptr)
        {
            break;
        }
    }

    // Ensure root is always black
    root->color = "black";
}

void Tree::remove(int value)
{
    // Find the node to remove
    TreeNode *z = root;
    while (z != nullptr)
    {
        if (value == z->info)
        {
            break;
        }
        else if (value < z->info)
        {
            z = z->left;
        }
        else
        {
            z = z->right;
        }
    }

    // Node not found
    if (z == nullptr)
    {
        return;
    }

    TreeNode *y = z;
    TreeNode *x = nullptr;
    string yOriginalColor = y->color;

    if (z->left == nullptr)
    {
        x = z->right;
        if (z->parent == nullptr)
        {
            root = x;
        }
        else if (z == z->parent->left)
        {
            z->parent->left = x;
        }
        else
        {
            z->parent->right = x;
        }
        if (x)
            x->parent = z->parent;
    }
    else if (z->right == nullptr)
    {
        x = z->left;
        if (z->parent == nullptr)
        {
            root = x;
        }
        else if (z == z->parent->left)
        {
            z->parent->left = x;
        }
        else
        {
            z->parent->right = x;
        }
        if (x)
            x->parent = z->parent;
    }
    else
    {
        y = z->right;
        while (y->left != nullptr)
            y = y->left;

        yOriginalColor = y->color;
        x = y->right;

        if (y->parent == z)
        {
            if (x)
                x->parent = y;
        }
        else
        {
            if (y->parent)
            {
                if (y == y->parent->left)
                    y->parent->left = x;
                else
                    y->parent->right = x;
            }
            if (x)
                x->parent = y->parent;

            y->right = z->right;
            if (y->right)
                y->right->parent = y;
        }

        if (z->parent == nullptr)
        {
            root = y;
        }
        else
        {
            if (z == z->parent->left)
            {
                z->parent->left = y;
            }
            else
            {
                z->parent->right = y;
            }
        }

        y->left = z->left;
        y->color = z->color;
        if (y->left)
            y->left->parent = y;
    }

    delete z;

    // Rebalance if needed
    if (yOriginalColor == "black" && x != nullptr)
    {
        while (x != root && (x == nullptr || x->color == "black"))
        {
            if (x == x->parent->left)
            {
                TreeNode *w = x->parent->right;

                if (w->color == "red")
                {
                    w->color = "black";
                    x->parent->color = "red";
                    LeftRotate(x->parent);
                    w = x->parent->right;
                }

                if ((w->left == nullptr || w->left->color == "black") &&
                    (w->right == nullptr || w->right->color == "black"))
                {
                    w->color = "red";
                    x = x->parent;
                }
                else
                {
                    if (w->right == nullptr || w->right->color == "black")
                    {
                        if (w->left != nullptr)
                            w->left->color = "black";
                        w->color = "red";
                        RightRotate(w);
                        w = x->parent->right;
                    }

                    w->color = x->parent->color;
                    x->parent->color = "black";
                    if (w->right != nullptr)
                        w->right->color = "black";
                    LeftRotate(x->parent);
                    break;
                }
            }
            else
            {
                TreeNode *w = x->parent->left;

                if (w->color == "red")
                {
                    w->color = "black";
                    x->parent->color = "red";
                    RightRotate(x->parent);
                    w = x->parent->left;
                }

                if ((w->right == nullptr || w->right->color == "black") &&
                    (w->left == nullptr || w->left->color == "black"))
                {
                    w->color = "red";
                    x = x->parent;
                }
                else
                {
                    if (w->left == nullptr || w->left->color == "black")
                    {
                        if (w->right != nullptr)
                            w->right->color = "black";
                        w->color = "red";
                        LeftRotate(w);
                        w = x->parent->left;
                    }

                    w->color = x->parent->color;
                    x->parent->color = "black";
                    if (w->left != nullptr)
                    {
                        w->left->color = "black";
                    }
                    RightRotate(x->parent);
                    break;
                }
            }
        }

        if (x != nullptr)
        {
            x->color = "black";
        }
    }
}

void Tree::search(int value)
{
    TreeNode *current = root;
    while (current != nullptr)
    {
        if (value == current->info)
        {
            cout << current->info << " exists with color: " << current->color << endl;
            return;
        }
        else if (value < current->info)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    cout << value << " doesn't exist";
}
