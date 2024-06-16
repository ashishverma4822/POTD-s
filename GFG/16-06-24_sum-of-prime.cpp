class Solution {
  private:
    vector<int> SieveOfEratosthenes(int n){
        vector<int>v;
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));
        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true){
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        for (int p = 2; p <= n; p++) if(prime[p]) v.push_back(p);
        return v;
    }
  public:
    vector<int> getPrimes(int n) {
        // code here
        vector<int> nums = SieveOfEratosthenes(n);
        int i=0,j=nums.size()-1;
        while(i<=j){
            if(nums[i]+nums[j]==n) return {nums[i],nums[j]};
            else if(nums[i]+nums[j]>n) j--;
            else i++;
        }
        return {-1,-1};
    }
};
