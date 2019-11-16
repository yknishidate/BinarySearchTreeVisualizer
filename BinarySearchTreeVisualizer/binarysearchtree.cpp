#include "binarysearchtree.h"

BinarySearchTree::BinarySearchTree(const QList<int> n){
    nums = n;
    root = new Node(nums[0]);
    for(int i=1; i<nums.size(); i++)
        root->insert(new Node(nums[i]));
}

int BinarySearchTree::height(){
    return root->calcHeight();
}

bool BinarySearchTree::isAVL(){
//    bool isAVL = true;
//    root->checkAVL(isAVL);
//    return isAVL;
    return root->isAVL();
}

void BinarySearchTree::print()
{
//    printVector(nums);
    root->print();
}

bool BinarySearchTree::operator==(const BinarySearchTree &tree){
//    bool isEqual = true;
//    root->checkEqual(tree.root, isEqual);
//    return isEqual;
    return root->isEqual(tree.root);
}

bool BinarySearchTree::operator!=(const BinarySearchTree &tree){
    return !(*this == tree);
}

bool BinarySearchTree::exists(const QList<BinarySearchTree *> uniqueTrees){
    for(int i=0; i < uniqueTrees.size(); i++)
        if(*uniqueTrees[i] == *this) return true;
    return false;
}
