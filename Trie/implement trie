/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
*/

// struct Node{
//     Node *child[26];
//     bool flag=false;

//     bool containkey(char ch){
//        return (child[ch-'a']!=nullptr);
//     }
//     void put(char ch,Node*node){
//         child[ch-'a']=node;
//     }
//     Node *get(char ch){
//         return child[ch-'a'];
//     }
//     void setend(){
//         flag=true;
//     }
//     bool isend(){
//         return flag;
//     }


// };
class Node{
    public:
    Node* child[26];
    bool flag;

    bool containkey(char ch){
       return child[ch-'a'] != nullptr;
    }
    void put(char ch,Node* node){
        child[ch-'a'] = node;
    }
    Node* get(char ch){
        return child[ch-'a'];
    }
    void isEnd(){
        flag=true;
    }
     bool isterminal(){
        return flag;
     }

};
class Trie {
    Node*root;
public:
   
    Trie() {
     root = new Node();
        
    };
    
    void insert(string word) {
        Node* node= root;
        for(int i=0;i<word.size();i++){
            if(!node->containkey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->isEnd();
        
    }
    
    bool search(string word) {
        // Node *node=root;
        // for(int i=0;i<word.length();i++){
        //     if(!node->containkey(word[i])){
        //          return false;
        //     }
        //     node=node->get(word[i]);
        // }
        // return node->isend();
        
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containkey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return node->isterminal();
    }
    
    bool startsWith(string prefix) {
        // Node *node=root;
        // for(int i=0;i<prefix.length();i++){
        //     if(!node->containkey(prefix[i])){
        //          return false;
        //     }
        //     node=node->get(prefix[i]);
        // }
        // return true;
        Node*node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containkey(prefix[i])){
                return false;
            }
            node=node->get(prefix[i]);
        }
        return true;
        
    }
};