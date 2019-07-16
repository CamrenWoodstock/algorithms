#include <iostream>
#include "trie.hpp"

Trie::Trie() {
    root = nullptr;
    size = 0;
    height_upper_bound = 0;
}

Trie::~Trie() {
    clear(root);
}

Node* remove(const char* word, Node* n) {

}

void Trie::clear(Node* n) {
    if(!n) return;
    for (int i = 0; i < 26; i++) {
        clear(n);
    }
    delete n;
}


void Trie::print(std::ostream& oss, Node* n, char* letters, int level) {

}

void Trie::insert(const char* word, int val) {
    Node* top = new node;
    top = root;
    for (int i = 0; word[i]; i ++) {
           int index = children[word[i]-'a'];
           if (!top->children[index]) {
           
           }
        //create new node with that character
        }


}

  
int Trie::count() {
    int count = 0;


    return count; 

}

 
bool Trie::search(const char* word) {
    if (!word) return false;
    int len = 0;
    while (word[i]!='\0') {
        len++;
    }
    for (int i = 0; i < len; i++) {
        
    }
    else if ()

}

 
int Trie::get(const char* word) {

}

 
void Trie::remove(const char* word) {

}

 
void Trie::clear() {
    clear(root);
    root = nullptr;
}


void Trie::print(std::ostream& oss = std::cout) {

}