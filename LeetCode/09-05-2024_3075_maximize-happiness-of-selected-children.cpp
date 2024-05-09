class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long uttar = 0;
        priority_queue<int>pq;
        for(int i=0;i<happiness.size();i++){
            pq.push(happiness[i]);
        }
        int t=0;
        while(k--){
            if(pq.top()-t>=0) uttar+=pq.top()-t;
            t++;
            pq.pop();
        }
        return uttar;
    }
};
