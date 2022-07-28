struct Node{
    Node* link[26];
    bool flag=false; 
    bool contains(char& chr){
       if(link[chr-'a'] ==NULL ){
           return false;
       }
        return true;
    }
    void put(char& chr,Node* node){
        link[chr-'a'] = node;
    }
};
class Trie {
    private:
    Node* root;
  
    public:
        Trie() {
            root = new Node();
        }

        void insert(string word) {
            Node* node=root;
            for(int i=0;i<word.length();i++){
                if(!node->contains(word[i])){
                    node->put(word[i],new Node());
                }
                node = node->link[word[i]-'a'];
            }
            node->flag=true;
        }

        bool search(string word) {
            Node* node=root;
            for(int i=0;i<word.length();i++){
                if(node->link[word[i]-'a']==NULL){
                    return false;    
                }
                node = node->link[word[i]-'a'];
            }
            return node->flag;
        }

        bool startsWith(string prefix) {
            Node* node=root;
            for(int i =0;i<prefix.length();i++){
                if(node->link[prefix[i]-'a']==NULL){
                    return false;
                }
                node=node->link[prefix[i]-'a'];
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

