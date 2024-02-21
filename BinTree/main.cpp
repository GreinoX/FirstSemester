#include <iostream>

struct Node{
    int value {0};
    Node * parent {nullptr};
    Node * left_child {nullptr};
    Node * right_child {nullptr};

    Node(int val){
        value = val;
    }

    ~Node(){
        value = 0;
        parent = nullptr;
        left_child = nullptr;
        right_child = nullptr;
    }
};

struct BinTree{
    Node * root {nullptr};

    void insert(int value){
        Node * i = root;
        Node * was_in_tree = search_element(root, value);
        if(was_in_tree != nullptr) return;

        Node * new_node = new Node(value);
        if(i == nullptr){
            root = new_node;
            return;
        }
        while(i != nullptr){
            if(value < i->value){
                if(i->left_child == nullptr){
                    i->left_child = new_node;
                    new_node->parent = i;
                    return;
                }
                i = i->left_child;
            }else{
                if(i->right_child == nullptr){
                    i->right_child = new_node;
                    new_node->parent = i;
                    return;
                }
                i = i->right_child;
            }
        }
    }

    Node * max(Node * start_pointer){
        Node * i = start_pointer;
        while(i->right_child != nullptr){
            i = i->right_child;
        }
        return i;
    }

    Node * min(Node * start_pointer){
        Node * i = start_pointer;
        while(i->left_child != nullptr){
            i = i->left_child;
        }
        return i;
    }

//    Node * next_element(Node * start_pointer){
//        Node * i = start_pointer;
//        if(i->right_child != nullptr){
//            return min(i);
//        }
//        Node * parent_i = i->parent;
//        while(parent_i != nullptr && parent_i->right_child == i){
//            i = parent_i;
//            parent_i = parent_i->parent;
//        }
//        return parent_i;
//    }

    Node * next_element(int value){
        Node * i = root;
        Node * successor {nullptr};
        while(i != nullptr){
            if(value < i->value){
                successor = i;
                i = i->left_child;
            }else{
                i = i->right_child;
            }
        }
        return successor;
    }

//    Node * prev_element(Node * start_pointer){
//        Node * i = start_pointer;
//        if(i->left_child != nullptr) return max(i->left_child);
//        Node * parent_i = i->parent;
//        while(parent_i != nullptr && parent_i->left_child == i){
//            i = parent_i;
//            parent_i = parent_i->parent;
//        }
//        return parent_i;
//    }

    Node * prev_element(int value){
        Node * i = root;
        Node * successor {nullptr};
        while(i != nullptr){
            if(value > i->value){
                successor = i;
                i = i->right_child;
            }else{
                i = i->left_child;
            }
        }
        return successor;
    }

    Node * search_element(Node * current_node, int value){
        while(current_node != nullptr && current_node->value != value){
            if(value < current_node->value) current_node = current_node->left_child;
            else current_node = current_node->right_child;
        }
        return current_node;
    }

    bool exists(int value){
        Node * result_of_search = search_element(root, value);
        if(result_of_search == nullptr) return false;
        else return true;
    }

    void delete_element(Node * current, int value){
        Node * searchable_element = search_element(current, value);
        if(searchable_element == nullptr) return;

        if(searchable_element->right_child == nullptr && searchable_element->left_child == nullptr){
            if(searchable_element == root){
                root = nullptr;
                delete searchable_element;
            }else{
                if(searchable_element->parent->left_child == searchable_element) searchable_element->parent->left_child = nullptr;
                else searchable_element->parent->right_child = nullptr;
                delete searchable_element;
            }
        }else if((searchable_element->right_child && !searchable_element->left_child) || (!searchable_element->right_child && searchable_element->left_child)){
            if(searchable_element == root){
                root = (searchable_element->right_child == nullptr) ? searchable_element->left_child : searchable_element->right_child;
                delete searchable_element;
            }else if(searchable_element->right_child){
                if (searchable_element->parent->right_child == searchable_element) {
                    searchable_element->parent->right_child = searchable_element->right_child;
                    searchable_element->right_child->parent = searchable_element->parent;
                }else{
                    searchable_element->parent->left_child = searchable_element->right_child;
                    searchable_element->right_child->parent = searchable_element->parent;
                }
                delete searchable_element;
            }else{
                if(searchable_element->parent->right_child == searchable_element){
                    searchable_element->parent->right_child = searchable_element->left_child;
                    searchable_element->left_child->parent = searchable_element->parent;
                }else{
                    searchable_element->parent->left_child = searchable_element->left_child;
                    searchable_element->left_child->parent = searchable_element->parent;
                }
                delete searchable_element;
            }
        }else{
            Node * successor = min(searchable_element->right_child);
            searchable_element->value = successor->value;
            delete_element(searchable_element->right_child, successor->value);
        }
    }

//    void delete_element(int value){
//        Node * searchable_element = search_element(root, value);
//        if(searchable_element == nullptr) return;
//
//        Node * parent_of_search_elem = searchable_element->parent;
//
//        if(searchable_element->left_child == nullptr && searchable_element-> right_child == nullptr){
//            if(parent_of_search_elem->left_child == searchable_element) parent_of_search_elem->left_child = nullptr;
//            if(parent_of_search_elem->right_child == searchable_element) parent_of_search_elem->right_child = nullptr;
//            delete searchable_element;
//            return;
//        }else if(searchable_element->left_child == nullptr || searchable_element->right_child == nullptr){
//            if(searchable_element->left_child == nullptr){
//                if(parent_of_search_elem->left_child == searchable_element){
//                    parent_of_search_elem->left_child = searchable_element->right_child;
//                }else{
//                    parent_of_search_elem->right_child = searchable_element->right_child;
//                }
//                searchable_element->right_child->parent = parent_of_search_elem;
//                delete searchable_element;
//            }else{
//                if(parent_of_search_elem->left_child == searchable_element){
//                    parent_of_search_elem->left_child = searchable_element->left_child;
//                }else{
//                    parent_of_search_elem->right_child = searchable_element->left_child;
//                }
//                searchable_element->left_child->parent = parent_of_search_elem;
//                delete searchable_element;
//            }
//        }else{
//            Node * successor = next_element(searchable_element->value);
//            searchable_element->value = successor->value;
//            if(successor->parent->left_child == successor){
//                successor->parent->left_child = successor->right_child;
//                if(successor->right_child != nullptr){
//                    successor->right_child->parent = successor->parent;
//                }
//            }else{
//                successor->parent->right_child = successor->right_child;
//                if(successor->right_child != nullptr){
//                    successor->right_child->parent = successor->parent;
//                }
//            }
//            delete successor;
//            return;
//        }
//    }
};

int main() {
//    std::ios::sync_with_stdio(0);
//    std::cin.tie(0);
//    std::cout.tie(0);

    BinTree tree;
    std::string command;
    while(std::cin >> command){
        if(command == "insert"){
            int value;
            std::cin >> value;
            tree.insert(value);
        }else if(command == "exists"){
            int value;
            std::cin >> value;
            bool result_of_exists = tree.exists(value);
            if(result_of_exists) std::cout << "true" << '\n';
            else std::cout << "false" << '\n';
        }else if(command == "prev"){
            int value;
            std::cin >> value;
            Node * result_of_prev = tree.prev_element(value);
            if(result_of_prev == nullptr) std::cout << "none" << '\n';
            else std::cout << result_of_prev->value << '\n';
        }else if(command == "next"){
            int value;
            std::cin >> value;
            Node * result_of_next = tree.next_element(value);
            if(result_of_next == nullptr) std::cout << "none" << '\n';
            else std::cout << result_of_next->value << '\n';
        }else if(command == "delete"){
            int value;
            std::cin >> value;
            tree.delete_element(tree.root, value);
        }

    }
}
