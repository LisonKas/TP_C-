#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <list>
#include <numeric>
#include "node.hpp"

void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node) {
    pretty_print_left_right(node, "", true);
}

int main(){

    Node* newNode {create_node(10)};

    pretty_print_left_right(*newNode);
    std::cout << newNode->is_leaf() << std::endl;

    newNode->insert(34);
    newNode->insert(5);
    newNode->insert(44);
    newNode->insert(20);
    newNode->insert(50);
    pretty_print_left_right(*newNode);
    std::cout << newNode->height() << std::endl;
    // newNode->right->delete_childs();
    // pretty_print_left_right(*newNode);
    newNode->display_infixe();

    return 0;
}