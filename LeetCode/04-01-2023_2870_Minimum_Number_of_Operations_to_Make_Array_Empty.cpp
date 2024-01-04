class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        int cnt2=0,cnt3=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto i :mp){
            cout<<i.first<<" "<<i.second<<endl;
        }
        for(auto i:mp){
            if(i.second%3==0){
                cnt3+=i.second/3;
            }
            else if(i.second%2==0){
                int cnt = i.second/2;
                cnt2 += cnt%3;
                cnt3 += (cnt/3)*2;
            }
            else if(i.second>3 and i.second%3==1){
                cnt3+=i.second/3-1;
                cnt2+=2;
            }
            else if(i.second>3 and i.second%3==2){
                cnt3+=i.second/3;
                cnt2+=1;
            }
            else return -1;
        }
        return cnt2 + cnt3;
    }
};
