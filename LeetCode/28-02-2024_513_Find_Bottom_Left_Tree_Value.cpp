class Solution {
    //Here We are trying to traverse binary tree as level order traversal
    //Store last level last node into the ans variable 
public:
    int findBottomLeftValue(TreeNode* root) {
        if(root==nullptr) return 0;
        vector<int>v;
        queue<TreeNode*>q; // bfs traversal
        q.push(root);
        int ans = -1; // Use for store left bottom node value
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode* front = q.front();
                q.pop();
                if(front->left!=nullptr) q.push(front->left);
                if(front->right!=nullptr) q.push(front->right);
                v.push_back(front->val);
            }
            ans=v[0];
            v.clear();
        }
        return ans;
    }
};
