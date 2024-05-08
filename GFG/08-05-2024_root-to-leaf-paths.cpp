class Solution {
  private:
    vector<int>u;
    void helpme(Node* root,vector<vector<int>>&v){
        if(root==nullptr) return;
        if(root->left == nullptr and root->right==nullptr){
            u.push_back(root->data);
            v.push_back(u);
            u.pop_back();
            return;
        }
        u.push_back(root->data);
        helpme(root->left,v);
        u.pop_back();
        u.push_back(root->data);
        helpme(root->right,v);
        u.pop_back();
    }
  public:
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>>v;
        helpme(root,v);
        return v;
    }
};
