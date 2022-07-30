struct Node{
    Node* link[2];
    
    bool contain(int bit){
        if(link[bit]==NULL)return false;
        return true;
    }
    void put(int bit,Node* node){
        link[bit]=node;
    }
    Node* get(int bit){
        return link[bit];
    }
    
};

class Trie{
    private:
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i & 1);
            if(!node->contain(bit)){
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
    }
    
    int XOR(int num){
        Node* node =root;
        int maxi=0;
        for(int i=31;i>=0;i--){
            int bit = num>>i & 1;
            if(node->contain(1-bit)){
                maxi = 1<<i | maxi; 
                node = node->get(1-bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return maxi;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto& it:nums){
            trie.insert(it);
        }
        int ans=0;
        for(auto& it:nums){
            ans = max(ans,trie.XOR(it));
        }
        return ans;
    }
};