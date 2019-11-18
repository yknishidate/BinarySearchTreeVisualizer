#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "node.h"

class BinarySearchTree {
public:
    Node *root;
    QList<int> nums;
    BinarySearchTree(const QList<int> n);
    Node* getRoot(){return root;}
    int height();
    bool isAVL();
    bool operator==(const BinarySearchTree &tree);
    bool operator!=(const BinarySearchTree &tree);
    bool exists(const QList<BinarySearchTree*> uniqueTrees);
    bool remove(Node *target);
    bool remove(Node *node, Node *target, Node *parent, bool left);

    // for Debug
    void print();
};

#endif // BINARYSEARCHTREE_H
