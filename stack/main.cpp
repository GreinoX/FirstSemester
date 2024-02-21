#include <iostream>
#include <vector>

using namespace std;

struct Node {
    char _val;
    struct Node *_previous = nullptr;

    Node(char val, Node *previous) {
        _val = val;
        _previous = previous;
    }

    ~Node() {
        _val;
        _previous = nullptr;
    }
};

struct Linked_list {
    Node *_top = nullptr;

    void add_item(char value) {
        Node * new_node = new Node(value, _top);
        _top = new_node;
    }

    char get_item() {
        if (_top == nullptr) return -1;
        return _top -> _val;
    }

    void delete_item() {
        if (_top == nullptr) {
            return;
        } else {
            Node *tmp = _top;
            _top = _top->_previous;
            delete tmp;
        }
    }

    Linked_list() {}
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string data;
    cin >> data;
    Linked_list scoop_stack;
    bool scoop_not_closed = false;
    for(int i = 0; i < n; ++i){
        if(data[i] == '(' || data[i] == '{' || data[i] == '['){
            scoop_stack.add_item(data[i]);
        }
        if(data[i] == ')'){
            if(scoop_stack.get_item() == -1) scoop_not_closed = true;
            else{
                if(scoop_stack.get_item() == '('){
                    scoop_stack.delete_item();
                }else scoop_not_closed = true;
            }
        }

        if(data[i] == '}'){
            if(scoop_stack.get_item() == -1) scoop_not_closed = true;
            else{
                if(scoop_stack.get_item() == '{'){
                    scoop_stack.delete_item();
                }else scoop_not_closed = true;
            }
        }
        if(data[i] == ']'){
            if(scoop_stack.get_item() == -1) scoop_not_closed = true;
            else{
                if(scoop_stack.get_item() == '['){
                    scoop_stack.delete_item();
                }else scoop_not_closed = true;
            }
        }
    }

    if(scoop_stack.get_item() != -1) scoop_not_closed = true;

    if(scoop_not_closed) cout << "NO";
    else cout << "YES";
}

//#include <iostream>
//#include <vector>
//using namespace std;
//
//bool binary_search(string word, string word_to_achieve, vector<int> need_to_erase, int count_to_erase){
//    for(int i = 0; i < count_to_erase; ++i){
//        word.erase((need_to_erase[i] % word.length()), 1);
//    }
//    if(word == word_to_achieve) return true;
//    else return false;
//}
//
//int main(){
//    string word;
//    cin >> word;
//    string word_result;
//    cin >> word_result;
//    vector<int> need_erase;
//    int to_erase;
//    while(cin >> to_erase){
//        need_erase.push_back(to_erase);
//    }
//    int l = 0;
//    int r = word.length();
//    int m;
//    while(r - l > 0){
//        m = (r + l) / 2;
//        bool result = binary_search(word, word_result, need_erase, m);
//        if(result){
//            r = m;
//        }else{
//            l = m;
//        }
//    }
//    cout << m;
//}