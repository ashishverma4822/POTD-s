class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
     // Add your code here
     if (root == nullptr)
        return true;
        
     if (root->left == nullptr && root->right == nullptr)
        return true;
        
     int sum = 0;
     if (root->left != nullptr)
        sum += root->left->data;
     if (root->right != nullptr)
        sum += root->right->data;

     return (root->data == sum && isSumProperty(root->left) && isSumProperty(root->right));
    }
};
