#include "node.h"

Node::Node(int num){
    this->num = num;
    this->left = this->right = nullptr;
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
}
bool Node::operator!=(const Node &node){return !(*this==node);}

bool Node::insert(Node *node){
    if(node==nullptr) return false;

    if(exists(node)){
        qDebug() << node->num << "is already exists.";
        return false;
    }

    if(node->num < this->num){
        if(this->left == nullptr){
            this->left = node;
        }else
            this->left->insert(node);
    }
    else{
        if(this->right == nullptr){
            this->right = node;
        }else
            this->right->insert(node);
    }
    return true;
}

bool Node::remove(Node *node)
{
    if(node==nullptr) return false;

    if(left!=nullptr && left==node){
        if(left->isLeaf()){
            qDebug() << "RemoveLeaf: " << left->num;
            delete(left);

            this->left = nullptr;
            this->leftEdge = nullptr;

            return true;
        }
        qDebug() << "Others: " << left->num;
        return false;
    }
    if(right!=nullptr && right==node){
        if(right->isLeaf()){
            qDebug() << "RemoveLeaf: " << right->num;
            delete(right);

            this->right = nullptr;
            this->rightEdge = nullptr;

            return true;
        }
        qDebug() << "Others: " << right->num;
        return false;
    }

    // Recursive
    if(left!=nullptr)
        left->remove(node);

    if(right!=nullptr)
        right->remove(node);

    return false;
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
    return 1 + qMax(left ==nullptr ? -1 : left->calcHeight(),
                    right==nullptr ? -1 : right->calcHeight());
}

bool Node::isEqual(Node *node)
{
    if(node==nullptr) return false;
    bool t=(*this == *node), l=true, r=true;

    // Left
    if(this->left!=nullptr && node->left!=nullptr)
        l = left->isEqual(node->left); // 再帰
    else
        l = ((this->left==nullptr) && (node->left==nullptr)); //両方とも左の子がないならtrue

    // Right
    if(this->right!=nullptr && node->right!=nullptr)
        r = right->isEqual(node->right);
    else
        r = ((this->right==nullptr) && (node->right==nullptr));  //両方とも右の子がないならtrue

    return t && l && r;
}

bool Node::isAVL()
{
    int dif = abs(  (left ==nullptr ? 0 : 1+left->calcHeight())
                   -(right==nullptr ? 0 : 1+right->calcHeight()) );
    bool t=(dif<=1), l=true, r=true;
    if(this->left != nullptr)   left->isAVL();
    if(this->right != nullptr)  right->isAVL();

    return t && l && r;
}

bool Node::exists(Node *node)
{
    if(node==nullptr) return false;
    bool t=(this->num == node->num), l=false, r=false;
    if(this->left != nullptr)   l = this->left->exists(node);
    if(this->right != nullptr)  r = this->right->exists(node);
    return t || l || r;
}

Node *Node::getMax()
{
    if(this->right==nullptr) return this;
    return this->right->getMax();
}

bool Node::isLeaf()
{
    return this->left==nullptr && this->right==nullptr;
}
