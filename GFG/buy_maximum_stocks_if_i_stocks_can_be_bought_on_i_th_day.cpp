class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Ashish Kumar Verma
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            pq.push({price[i],i+1});
        }
        int uttar=0;
        while(k>0 and !pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();
            while(p.second){
                int val=p.second*p.first;
                if(val<=k){
                    uttar+=p.second;
                    k=k-val;
                    break;
                }
                else{
                    p.second--;
                }
            }
        }
        return uttar;
    }
};
