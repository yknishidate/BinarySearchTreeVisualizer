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
    // Target is Root
    if(root == target){
        qDebug() << "Target is Root";
        if(target->isLeaf()){
            qDebug() << "You cannot delete last node";
            return false;
        }
        else if(root->hasOneChild()){
            qDebug() << "Root has 1 Child";
            QVector2D rootPos = root->position;
            if(root->left != nullptr)
                root = root->left;
            else
                root = root->right;

            root->position = rootPos;
            delete(target);
            return true;
        }
        else{
            qDebug() << "Root has 2 children";
            QVector2D rootPos = root->position;

            Node *maxParent = target->left->getMaxParent();
            Node *max = target->left->getMax();
            Node *tmpL = target->left;
            Node *tmpR = target->right;
            if(max == maxParent){
                max->right = tmpR;
                root = max;

                root->position = rootPos;
                delete(target);
                return true;
            }
            // Remove Max
            maxParent->right = max->left;
            // Setup Children
            max->right = tmpR;
            max->left = tmpL;
            // Replace with Max
            root = max;

            root->position = rootPos;
            delete(target);
            return true;
        }
    }

    return remove(root, target, nullptr, true);
}

bool BinarySearchTree::remove(Node *node, Node *target, Node *parent, bool isLeft)
{
    if(node == target){
        // Target is Leaf
        if(target->isLeaf()){
            qDebug() << "Target is Leaf";
            if(parent != nullptr){
                if(isLeft) parent->left = nullptr;
                else       parent->right = nullptr;
            }
            delete(target);
            return true;
        }
        // Target has 1 child
        else if(target->hasOneChild()){
            qDebug() << "Target has 1 child";
            if(parent != nullptr){
                // Target is Parent's Left
                if(isLeft) {
                    if(target->left != nullptr) // "/"
                        parent->left = target->left;
                    else                        // "<"
                        parent->left = target->right;
                }
                // Target is Parent's Right
                else {
                    if(target->left != nullptr) // ">"
                        parent->right = target->left;
                    else                        // "\"
                        parent->right = target->right;
                }
            }
            delete(target);
            return true;
        }
        // Target has 2 children
        else{
            qDebug() << "Target has 2 children";
            Node *maxParent = target->left->getMaxParent();
            Node *max = target->left->getMax();
            Node *maxLeft = max->left;
            Node *tmpL = target->left;
            Node *tmpR = target->right;
            if(max == maxParent){
                max->right = tmpR;
                if(isLeft){
                    parent->left = max;
                }
                else{
                    parent->right = max;
                }
                delete(target);
                return true;
            }
            // Remove Max
            maxParent->right = max->left;
            // Setup Children
            max->left = tmpL;
            max->right = tmpR;
            // Replace with Max
            if(isLeft) parent->left = max;
            else       parent->right = max;
            delete(target);
            return true;
        }
    }
    if(node->left != nullptr)
        remove(node->left, target, node, true);
    if(node->right != nullptr)
        remove(node->right, target, node, false);
    return true;
}
