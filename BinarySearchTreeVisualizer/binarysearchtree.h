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
    void print();
    bool operator==(const BinarySearchTree &tree);
    bool operator!=(const BinarySearchTree &tree);
    bool exists(const QList<BinarySearchTree*> uniqueTrees);
    bool remove(Node *node);
};

#endif // BINARYSEARCHTREE_H
