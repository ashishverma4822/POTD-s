class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_arr, pq_exit;
        
        for (int i = 0; i < times.size(); i++) {
            pq_arr.push({times[i][0], i});
            pq_exit.push({times[i][1], i});
        }

        unordered_map<int, int> mp;
        unordered_map<int, int> mp2;
        set<int> availableChairs;
        int pos = 0;

        while (!pq_arr.empty()) {
            auto arr_f = pq_arr.top();
            pq_arr.pop();
            
            while (!pq_exit.empty() && pq_exit.top().first <= arr_f.first) {
                int friendIndex = pq_exit.top().second;
                int chairToFree = mp2[friendIndex];
                availableChairs.insert(chairToFree);
                mp.erase(chairToFree);
                mp2.erase(friendIndex);
                pq_exit.pop();
            }

            if (!availableChairs.empty()) {
                pos = *availableChairs.begin();
                availableChairs.erase(pos);
            }

            mp[pos] = arr_f.second;
            mp2[arr_f.second] = pos;
            
            if (arr_f.second == targetFriend) return pos;

            while (mp.find(pos) != mp.end()) pos++;
        }

        return -1;
    }
};
