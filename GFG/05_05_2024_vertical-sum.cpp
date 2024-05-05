class Solution{
  private:
    void helpme(Node* root, map<int,int>&mp ,int d){
        if(root==nullptr) return ;
        if(mp.find(d)!=mp.end()){
            mp[d]+=root->data;
        }
        else{
            mp[d]=root->data;
        }
        helpme(root->left,mp,d-1);
        helpme(root->right,mp,d+1);
    }
  public:
    vector <int> verticalSum(Node *root) {
        // add code here.
        map<int,int>mp;
        helpme(root,mp,0);
        vector<int>v;
        for(auto i:mp){
            v.push_back(i.second);
        }
        return v;
    }
};
