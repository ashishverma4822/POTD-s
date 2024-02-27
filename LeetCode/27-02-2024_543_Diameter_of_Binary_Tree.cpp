class Solution {
private:
    int bhaiBatao(TreeNode* root,int & max_len){
        if(root==nullptr) return 0; // if node==nullptr means height is zero;
        int left = bhaiBatao(root->left,max_len); // call for the left side of tree
        int right = bhaiBatao(root->right,max_len); // call for the right side of tree
        max_len = max(max_len,left + right); // its check maximum daimeter
        // diameter = max of left side + max of right side height having a path
        return max(left,right)+1; // it's return the height of th tree;
    }-+
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int max_len = INT_MIN; // Use to store the maximum diameter 
        bhaiBatao(root,max_len); // recursive function which finds the height
        return max_len;
    }
};
