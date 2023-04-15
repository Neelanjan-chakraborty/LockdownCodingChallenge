/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
*/
class Trie {
    struct TrieNode{
      TrieNode *children[26];
      bool isEnd;
    };
    TrieNode *root;
    public:
    /** Initialize your data structure here. */
    TrieNode* getNode(){
      TrieNode *root=new TrieNode;
      for(int i=0;i<26;i++)
        root->children[i]=NULL;
      root->isEnd=false;
      return root;
    }
    Trie() {
      root=getNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
      TrieNode *crawl=root;
      for(int i=0;i<word.length();i++){
        if(crawl->children[word[i]-'a']==NULL)
          crawl->children[word[i]-'a']=getNode();
        crawl=crawl->children[word[i]-'a'];
      }
      crawl->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
      TrieNode* crawl=root;
      for(int i=0;i<word.length();i++){
        if(!crawl->children[word[i]-'a'])
          return false;
        crawl=crawl->children[word[i]-'a'];
      }
      return crawl->isEnd==true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
      TrieNode* crawl=root;
      for(int i=0;i<prefix.length();i++){
        if(!crawl->children[prefix[i]-'a'])
          return false;
        crawl=crawl->children[prefix[i]-'a'];
      }
      return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
