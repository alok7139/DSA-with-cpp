/*
Ninja has to implement a data structure ”TRIE” from scratch. Ninja has to complete some functions.

1) Trie(): Ninja has to initialize the object of this “TRIE” data structure.

2) insert(“WORD”): Ninja has to insert the string “WORD”  into this “TRIE” data structure.

3) countWordsEqualTo(“WORD”): Ninja has to return how many times this “WORD” is present in this “TRIE”.

4) countWordsStartingWith(“PREFIX”): Ninjas have to return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.

5) erase(“WORD”): Ninja has to delete one occurrence of the string “WORD” from the “TRIE”.
Note:

1. If erase(“WORD”) function is called then it is guaranteed that the “WORD” is present in the “TRIE”.

2. If you are going to use variables with dynamic memory allocation then you need to release the memory associated with them at the end of your solution.
Can you help Ninja implement the "TRIE" data structure?

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= “T” <= 50
1 <= “N” <= 10000
 “WORD” = {a to z}
1 <= | “WORD” | <= 1000

Where “T” is the number of test cases, “N” denotes how many times the functions(as discussed above) we call, “WORD” denotes the string on which we have to perform all the operations as we discussed above, and | “WORD” | denotes the length of the string “WORD”.
*/

#include <bits/stdc++.h> 
class Node{
    public:
    Node* child[26];
    int countprefix=0;
    int cntendwith=0;

    bool iscontain(char ch){
        return child[ch-'a']!=nullptr;
    }
    void put(char ch,Node*node){
        child[ch-'a']=node;
    }
    Node*get(char ch){
        return child[ch-'a'];
    }
    void increaseprefix(){
        countprefix++;
    }
    void increseendwith(){
        cntendwith++;
    }
    void reduxeprefix(){
        countprefix--;
    }
    void getdelete(){
        cntendwith--;
    }

};
class Trie{
  Node* root;

    public:

    Trie(){
        // Write your code here.
        root= new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node*node=root;
        int n=word.size();
        for(int i=0;i<n;i++){
            if(!node->iscontain(word[i])){
                node->put(word[i] , new Node());
            }
            node=node->get(word[i]);
            node->increaseprefix();
        }
        node->increseendwith();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node*node= root;
        int n=word.size();
        for(int i=0;i<word.size();i++){
            if(node->iscontain(word[i])){
                node=node->get(word[i]);
            }
            else{
                return 0;
            }
            
        }
        return node->cntendwith;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node*node= root;
        int n=word.size();
        for(int i=0;i<word.size();i++){
            if(!node->iscontain(word[i])){
                return 0;;
            }
            else{
                 node=node->get(word[i]);
            }
           
        }
        return node->countprefix;
    }

    void erase(string &word){
        // Write your code here.
        int n=word.size();
        Node*node=root;
        for(int i=0;i<n;i++){
            if(node->iscontain(word[i])){
                node=node->get(word[i]);
                node->reduxeprefix();
                
            }
            else{
                return;
            }
        }
        node->getdelete();
    }
};
