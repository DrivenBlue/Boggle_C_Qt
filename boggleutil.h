#ifndef BOGGLEUTIL_H
#define BOGGLEUTIL_H


#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <set>
#include <stdexcept> 

using namespace std; 

class Node{
    char currentNode;
    Node* leftNode;
    Node* middleNode;
    Node* rightNode;
    bool endWord;

    Node(char currentNode, bool endWord){

        currNode = currentNode;
        wordEnd = endWord;
        leftNode = NULL;
        middleNode = NULL;
        rightNode = NULL;
    }

};

class TernaryTree{

private:
    Node* root;

public:
    TernaryTrie(){
        root = NULL;
    }


    void insert(Node*& node, string word, int i){
        //creates a new node if root is null
        if(node == nullptr){
            node = new Node(word[i],false);
        }
    //checks if indexed letter is less than the current node
        if(word[i] < node->currNode){
            //recursively calls method
            insertHelper(node->leftNode,word,i);
        }
        //checks if indexed letter is greater than the current node
        else if(word[i] > node->currNode){
            //recursively calls method
            insertHelper(node->rightNode,word,i);
        }
        //checks if the indexed letter is the same as the current node
        else if(word[i] == node->currNode){
            if(i+1 == word.length()){
                //sets flag to be true
                node->endWord = true;
            }else{
                //recursively calls the method
                insertHelper(node->middleNode,word,i+1);
            }
        }

    }

    bool search(string word)  {
        //throws exception if string passed in is empty
        if(word.compare("")== 1)
        {
            throw;
        }
        //initializes variables
        Node* p = root;
        bool inTree;
        int i = 0;
        //iteratively searches trie for word
        while(i<word.length())
        {
            //checks to see if p is null\
            if(p == nullptr)
            {
                inTree = false;
                break;
            }
        //checks to see if index of word is less than currentNode
            else if(word[i] < p->currNode)
            {
                p = p->rightNode;
            }
            else
            {
                //checks to see if reached end of word
                if(i+1 == word.length() && p->endWord == true)
                {
                    inTree = true;
                    break;
                }
                else
                {
                    p= p->middleNode;
                    i++;
                }
            }
        }
    return inTree;

    }

    void add(string word){
        //throws exception if empty string is passed in
        if(word.compare("") == 1){
            throw;
        }
    int i = 0;
    insert(root, word, i);

    }

}

#endif // BOGGLEUTIL_H
