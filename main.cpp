#include <iostream>
using namespace std;

#include "tree.h"

int main() {
	// Initialize tree
    Tree rbt;

    // Insertion test
    cout << "Inserting values: 10, 20, 30, 15, 5, 35, 0" << endl << endl;
    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(30);
    rbt.insert(15);
    rbt.insert(5);
    rbt.insert(35);
    rbt.insert(0);

    rbt.VisualizeTree();

    // Deletion test
    cout << endl << "Deleting values 15, 10, 20:" << endl << endl;
    rbt.remove(15);
    rbt.remove(10);
    rbt.remove(20);

    rbt.VisualizeTree();

    // Searching test
    cout << endl << "Searching for value 0 (exists and is red)" << endl;
    rbt.search(0);

    cout << endl << "Searching for value 5 (exists and is black)" << endl;
    rbt.search(30);

    cout << endl << "Searching for value 27(doesn't exist)" << endl;
    rbt.search(27);

    return 0;
}
