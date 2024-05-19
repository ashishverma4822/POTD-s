class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        int a = INT_MAX;
        int t = INT_MIN;
        for(int i=0;i<n;i++){
            if(abs(k-arr[i])<=a){
                a=abs(k-arr[i]);
                if(t<arr[i]){
                    t=arr[i];
                }
            }
        }
        return t;
    } 
};
