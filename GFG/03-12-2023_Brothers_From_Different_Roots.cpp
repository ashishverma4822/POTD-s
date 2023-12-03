class Solution
{
private:
    void helpme1(Node* root1,Node* root2,int &cnt,int x){
        if(root1==nullptr) return;
        if(helpme2(root2,x-root1->data)) cnt++;
        helpme1(root1->left,root2,cnt,x);
        helpme1(root1->right,root2,cnt,x);
    }
    bool helpme2(Node* root,int x){
        if(root==nullptr) return false;
        if(root->data==x) return true;
        bool left=false,right=false;
        if(root->data>x) left=helpme2(root->left,x);
        else right=helpme2(root->right,x);
        return left or right;
    }
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        int cnt=0;
        helpme1(root1,root2,cnt,x);
        return cnt;
    }
};
