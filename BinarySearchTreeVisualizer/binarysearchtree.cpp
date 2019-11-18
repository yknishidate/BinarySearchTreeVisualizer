#include "binarysearchtree.h"

BinarySearchTree::BinarySearchTree(const QList<int> n){
    nums = n;
    root = new Node(nums[0]);
    for(int i=1; i<nums.size(); i++)
        root->insert(new Node(nums[i]));
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
//    printVector(nums);
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
        return root->remove(target);
//    qDebug() << "RemoveCalled: ";
//    return remove(root, target, nullptr, true);
}

bool BinarySearchTree::remove(Node *node, Node *target, Node *parent, bool left)
{
    if(node==nullptr || target==nullptr) return false;

    if(node==target){
        if(node->isLeaf()){
            qDebug() << "RemoveLeaf: " << node->num;
            delete(node);
            node = nullptr;
//            delete(target);
            if(parent!=nullptr){
                if(left) parent->left = nullptr;
                else parent->right = nullptr;
            }
            return true;
        }
        qDebug() << "Others: " << node->num;
        return true;
    }

    if(node->left!=nullptr)
        return remove(node->left, target, node, true);
    if(node->right!=nullptr)
        return remove(node->right, target, node, false);
}
