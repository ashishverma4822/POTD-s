class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int curr_score = 0;
        int score = 0;
        int i=0,j=tokens.size()-1;
        while(i<=j){
            if(tokens[i]<=power){
                power-=tokens[i];
                curr_score++;
                i++;
            }
            else if(tokens[i]>power and curr_score>=1){
                power+=tokens[j];
                curr_score--;
                j--;
            }
            else break;
            score=max(score,curr_score);
        }
        return score;
    }
};
