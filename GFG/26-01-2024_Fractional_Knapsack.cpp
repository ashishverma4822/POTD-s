class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,int>>v;
        for(int i=0;i<n;i++){
            double profit_per_weight = (double)arr[i].value / (double)arr[i].weight;
            v.push_back({profit_per_weight,arr[i].weight});
        }
        sort(v.begin(), v.end(), [](pair<double, int> &a, pair<double, int> &b){
            return a.first > b.first; 
        });
        
        double uttar = 0;
        for(int i=0;i<n;i++){
            if(W>v[i].second){
                W-=v[i].second;
                uttar += v[i].second * v[i].first;
            }
            else{
                uttar += W * v[i].first;
                W-=W;
            }
        }
        return uttar;
    }
        
};
