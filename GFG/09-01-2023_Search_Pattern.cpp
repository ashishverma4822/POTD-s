class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code hee.
            vector<int>uttar;
            int ind = txt.find(pat,0);
            while(ind!=string::npos) {
                uttar.push_back(ind+1);
                ind = txt.find(pat,ind+1);
            }
            return uttar;
        }
     
};
