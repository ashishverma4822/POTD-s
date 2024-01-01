class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        priority_queue<int,vector<int>,greater<int>>pq1,pq2;
        for(int i=0;i<g.size();i++){
            pq1.push(g[i]);
        }
        for(int i=0;i<s.size();i++){
            pq2.push(s[i]);
        }
        int cnt=0;
        while(!pq1.empty() and !pq2.empty()){
            int val1 = pq1.top();
            int val2 = pq2.top();
            if(val2>=val1){
                cnt++;
                pq1.pop();
                pq2.pop();
            }
            else pq2.pop();
        }
        return cnt;
    }
};
