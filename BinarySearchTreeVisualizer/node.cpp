#include "node.h"

Node::Node(int num){
    this->num = num;
    this->left = this->right = this->parent = nullptr;
    position = QVector2D(0, 0);
}

bool Node::operator==(const Node &node){
    bool t = (num == node.num), l, r;
    if(left!=nullptr && node.left!=nullptr)
        l = (left->num == node.left->num);
    else
        l = (left==nullptr && node.left==nullptr);
    if(right!=nullptr && node.right!=nullptr)
        r = (right->num == node.right->num);
    else
        r = (right==nullptr && node.right==nullptr);

    return t && l && r;

//    if(left==nullptr && node.left==nullptr)
//        l = true;
//    else if(left!=nullptr && node.left!=nullptr)
//        l = (left->num == node.left->num);
//    else
//        l = false;

//    if(right==nullptr && node.right==nullptr)
//        r = true;
//    else if(right!=nullptr && node.right!=nullptr)
//        r = (right->num == node.right->num);
//    else
//        r = false;

//    return (t && l) && r;
}
bool Node::operator!=(const Node &node){return !(*this==node);}

void Node::insert(Node *node){
    if(node->num < this->num){
        if(this->left == nullptr){
            this->left = node;
            node->parent = this;
        }else
            this->left->insert(node);
    }
    else{
        if(this->right == nullptr){
            this->right = node;
            node->parent = this;
        }else
            this->right->insert(node);
    }
}

void Node::print(){
    qDebug()    <<  this->num << " -> ( "
                << (this->left==nullptr  ? "_" : QString::number(this->left->num))  << ", "
                << (this->right==nullptr ? "_" : QString::number(this->right->num)) << " )";
    if(this->left != nullptr)   this->left->print();
    if(this->right != nullptr)  this->right->print();
}

int Node::calcHeight(){
    // 葉のときに"0"になるように"-1"
    return 1 + std::max(left==nullptr ? -1 : left->calcHeight(),
                        right==nullptr? -1 : right->calcHeight());
}

void Node::checkEqual(Node *node, bool &isEqual){
    isEqual = isEqual && (*this == *node);
    if(this->left!=nullptr && node->left!=nullptr)
        left->checkEqual(node->left, isEqual);
    if((this->left==nullptr) ^ (node->left==nullptr)) isEqual = false;

    if(this->right!= nullptr && node->right!= nullptr)
        right->checkEqual(node->right, isEqual);
    if((this->left==nullptr) ^ (node->left==nullptr)) isEqual = false;
}

void Node::checkAVL(bool &isAVL){
    // 参照渡しでbool値を直接書き換え
    // 子が無ければ"0", 子を調べたら"+1"
    int dif = abs(  (left ==nullptr ? 0 : 1+left->calcHeight())
                    - (right==nullptr ? 0 : 1+right->calcHeight()) );
    isAVL = (dif <= 1) && isAVL;
    if(this->left != nullptr)   left->checkAVL(isAVL);
    if(this->right != nullptr)  right->checkAVL(isAVL);
}
