class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        //divisibility rule for 8
        // if last tree digit of number is divisible by that means number is diviisble by 8
        // string t = s.substr(s.size()-3);
        // int n = stoi(t);
        // if(n%8==0) return 1;
        // else return -1;
        
        // here problem is that number is given in string format and substr function contain
        //(index,lenght)
        // due to lenght of string is large thats why it gives us error
        
        // so now we use some technique
        
        reverse(s.begin(),s.end());
        string t = s.substr(0,3);
        reverse(t.begin(),t.end());
        int n = stoi(t);
        if(n%8==0) return 1;
        else return -1;
    }
};
