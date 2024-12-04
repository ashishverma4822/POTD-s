class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n=arr.size();
        d=d%n;
        reverse(arr.begin(),arr.begin()+n);
        reverse(arr.begin(),arr.begin()+(n-d));
        reverse(arr.begin()+(n-d),arr.begin()+n);
    }
};