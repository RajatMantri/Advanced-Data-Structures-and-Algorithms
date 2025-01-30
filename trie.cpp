//A hard problem using Trie
//Link to the problem: https://leetcode.com/problems/count-prefix-and-suffix-pairs-ii/description/

class TrieNode{
public:
    unordered_map<int,TrieNode*> child;
    int count;

    TrieNode(){
        count=0;
    }
};
class Solution {
public: 
    TrieNode* root;
    Solution(){
        root=new TrieNode();
    }
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long ans=0;
        for(auto&s:words){
            int n=s.length();
            TrieNode* curr=root;
            for(int i=0;i<n;i++){
                int hash=128*s[i]+s[n-1-i];
                if(curr->child[hash]==NULL) curr->child[hash]=new TrieNode();
                curr=curr->child[hash];
                ans+=curr->count;
            }
            curr->count++;
        }
        return ans;
    }
};