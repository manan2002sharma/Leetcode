/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*,Node*> mp;
    Node* dfs(Node* node){
        if(node==NULL) return NULL;
        Node* curr=new Node(node->val);
        mp[node]=curr;

        for(auto i: node->neighbors){
            if(mp.find(i)!=mp.end()){
                curr->neighbors.push_back(mp[i]);
            }else{
                curr->neighbors.push_back(dfs(i));
            }
        }
        return curr;

    }
    Node* cloneGraph(Node* node) {
        Node* ans=dfs(node);
        return ans;
    }
};