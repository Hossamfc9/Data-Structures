/**
 * an array based implementation of trie
*/

#include<stdio.h>

using namespace std;

#define ALPHABET 26

typedef struct TrieNode {
    TrieNode* children[ALPHABET];

    bool isWord;
}TrieNode;

TrieNode* NewNode(void) {
    TrieNode* pNode;
    
    for(int i = 0; i < ALPHABET; ++i) {
        pNode->children[i] = NULL;
    }

    pNode->isWord = false;
    
    return pNode;
}

void insert(TrieNode* Trie, char* word, int N) {
    TrieNode* temp = Trie;

    for(int i = 0; i < N; ++i) {
        int character = word[i] - 'a';
        if(!(temp->children[character])) {
            temp->children[character] = NewNode();
        }

        temp = temp->children[character];
    }

    temp->isWord = true;
    return;
}

bool search(TrieNode* Trie, char* word, int N) {
    TrieNode* temp = Trie;

    for(int i = 0; i < N; ++i) {
        int character = word[i] - 'a';
        if(!(temp->children[character])) {
            return false;
        }
        temp = temp->children[character];
    }

    return true;
}

int main() {
    
}