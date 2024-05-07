vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<vector<int>>v;
        if(root==NULL) return {};
        vector<int>temp;
        queue<Node*>pq;
        pq.push(root);
        pq.push(NULL);
        while(!pq.empty()){
            Node* f=pq.front();
            pq.pop();
            if(f==NULL){
                v.push_back(temp);
                temp.clear();
                if(!pq.empty()){
                    pq.push(NULL);
                }
            }
            else{
                temp.push_back(f->data);
                if(f->left){
                    pq.push(f->left);
                }
                if(f->right){
                    pq.push(f->right);
                }
            }
        }
        temp.clear();
        for(int i=v.size()-1;i>=0;i--){
            for(int j=0;j<v[i].size();j++){
                temp.push_back(v[i][j]);
            }
        }
        
        return temp;
}
