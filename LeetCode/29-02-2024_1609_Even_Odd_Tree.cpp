class Solution {
private:
    // This function is used to verify the point 2 in the question
    bool verify_odd(vector<int>v){
        for(int i=1;i<v.size();i++){
            if(v[i]%2==0) return false;
            if(v[i-1]>=v[i]) return false;
        }
        if(v[v.size()-1]%2==0) return false;
        return true;
    }

    // Thi function is used to verify the point 3 in the question
    bool verify_even(vector<int>v){
        for(int i=1;i<v.size();i++){
            if(v[i]%2!=0) return false;
            if(v[i-1]<=v[i]) return false;
        }
        if(v[v.size()-1]%2!=0) return false;
        return true;
    }
public:
    // Normal bfs level order traversal
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>v;
        q.push(root);
        int level=0; // for the level count through which we checke the conddition
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* front = q.front();
                v.push_back(front->val);
                q.pop();
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            if(level%2==0 and !verify_odd(v)) return false; // condition 2
            if(level%2 and !verify_even(v)) return false;  // condition 3
            level++;
            v.clear();
        }
        return true;
    }
};
