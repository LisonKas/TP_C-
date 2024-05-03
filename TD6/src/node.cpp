#include <iostream>
#include <vector>
#include "node.hpp"

//Question 1
Node* create_node(int value){
    Node* noeud = new Node;
    noeud -> value = value;
    noeud ->left = nullptr;
    noeud -> right = nullptr;
    return noeud;
}

//Question 2
bool Node::is_leaf() const{
    return this->left == nullptr && this->right == nullptr;
}

//Question 3
void Node::insert(int value){
    if(this->is_leaf()){
        if(value>this->value){
            this->right = create_node(value);
        }
        else {
            this->left = create_node(value);
        }
    }
    else if(this->left == nullptr && this->right!=nullptr){
        if(value>this->value){
            this->right->insert(value);
        }
        else {
            this->left = create_node(value);
        }
    }
    else if(this->left != nullptr && this->right==nullptr){
        if(value>this->value){
            this->right = create_node(value);
        }
        else {
            this->left->insert(value);
        }
    }
    else{
        if(value>this->value){
            this->right->insert(value);
        }
        else {
            this->left->insert(value);
        }
    }
}

//Question 4
int Node::height() const{
    if(this->is_leaf()){
        return 1;
    }
    else {
        int height_right {0}, height_left {0};        
        if(this->right){
            height_right += this->right->height();
        }
        else if(this->left){
            height_left += this->left->height();
        }
        if(height_right > height_left){
            return 1+height_right;
        }
        else {
            return 1+height_left;
        }
    }
}

//Question 5
void Node::delete_childs(){
    if(this->right && this->left){  //S'il a deux enfants
        if(this->right->is_leaf() && this->left->is_leaf()){  //si les deux enfants sont des feuilles
            delete this->right;
            this->right = nullptr;
            delete this->left;
            this->left = nullptr;
        }
        else if(this->right->is_leaf() && !this->left->is_leaf()){ //Si l'enfant de droite est une feuille mais pas l'enfant de gauche
            delete this->right;
            this->right = nullptr;
            this->left = this->left->left;
        }
        else if(!this->right->is_leaf() && this->left->is_leaf()){
            delete this->left;
            this->left = nullptr;
            this->right = this->right->right;
        }
        else {
            this->left = this->left->left;
            this->right = this->right->right;
        }
    }
    else if(this->right && !this->left){
        if(this->right->is_leaf()){
            delete this->right;
            this->right = nullptr;
        }
        else {
            this->right = this->right->right;
        }
    }
    else if(!this->right && this->left){
        if(this->left->is_leaf()){
            delete this->left;
            this->left = nullptr;
        }
        else {
            this->left = this->left->left;
        }
    }
}

//Question 6
void Node::display_infixe() const{
    if(this->left){
        this->left->display_infixe();
    }
    std::cout << " " << this->value << "," << std::endl;
    if(this->right){
        this->right->display_infixe();
    }
}

//Question 7
std::vector<Node const*> Node::prefixe() const{

}