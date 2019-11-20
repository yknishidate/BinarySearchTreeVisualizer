#include "binarysearchtree.h"

BinarySearchTree::BinarySearchTree(const QList<int> n){
    nums = n;
    root = new Node(nums[0]);
    for(int i=1; i<nums.size(); i++)
        root->insert(new Node(nums[i]));
}

BinarySearchTree::~BinarySearchTree()
{
    qDebug() << "BST deleted";
    deleteAllNodes(root);
}

void BinarySearchTree::deleteAllNodes(Node *node)
{
    if(node->left != nullptr)deleteAllNodes(node->left);
    if(node->right != nullptr)deleteAllNodes(node->right);
    delete(node);
}

int BinarySearchTree::height(){
    if(root==nullptr) return 0;
    return root->calcHeight();
}

bool BinarySearchTree::isAVL(){
    return root->isAVL();
}

void BinarySearchTree::print()
{
    root->print();
}

bool BinarySearchTree::operator==(const BinarySearchTree &tree){
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

bool BinarySearchTree::remove(Node *target)
{
    // Root
    if(root == target){
        return false;
//        if(root->isLeaf()){
//            return false;
//        }
//        else if(root->hasOneChild()){
//            root = (root->left!=nullptr) ? root->left
//                                         : root->right;
//            return true;
//        }
//        else{
//            Node *maxParent = root->left->getMaxParent();
//            Node *max = root->left->getMax();

//            qDebug() << "MaxNode:" << max->num;
//            qDebug() << "MaxPare:" << maxParent->num;
//            max->left  = root->left;
//            max->right = root->right;
//            // Remove Max
//            if(maxParent->right!=nullptr)
//                maxParent->right = nullptr;
//            // Replace with Max
//            root = max;
//            delete(target);
//            target = nullptr;
//            return true;
//        }
    }

    return root->remove(target);
}
