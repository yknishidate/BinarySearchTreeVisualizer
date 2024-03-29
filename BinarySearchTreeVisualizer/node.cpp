#include "node.h"

Node::Node(int num){
    this->num = num;
    this->left = this->right = nullptr;
    position = QVector2D(0, 0);
}

Node::~Node()
{
    qDebug() << "Node deleted";
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
    if(exists(node))  return false;

    if(node->num < this->num){
        if(this->left == nullptr) this->left = node;
        else                      this->left->insert(node);
    }
    else{
        if(this->right == nullptr) this->right = node;
        else                       this->right->insert(node);
    }
    return true;
}

void Node::print(){
    qDebug()    <<  this->num << " -> ( "
                << (this->left==nullptr  ? "_" : QString::number(this->left->num))  << ", "
                << (this->right==nullptr ? "_" : QString::number(this->right->num)) << " )";
    if(this->left != nullptr)   this->left->print();
    if(this->right != nullptr)  this->right->print();
}

int Node::calcHeight(){
    return qMax(left ==nullptr ? 0 : 1 + left->calcHeight(),
                right==nullptr ? 0 : 1 + right->calcHeight());
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
    int dif = abs(  (left ==nullptr ? 0 : 1 + left->calcHeight())
                   -(right==nullptr ? 0 : 1 + right->calcHeight()) );
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

Node *Node::getMaxParent()
{
    if(this->right==nullptr || this->right->right==nullptr) return this;
    return this->right->getMaxParent();
}

bool Node::isLeaf()
{
    return this->left==nullptr && this->right==nullptr;
}

bool Node::hasOneChild()
{
    return this->left==nullptr ^ this->right==nullptr;
}

