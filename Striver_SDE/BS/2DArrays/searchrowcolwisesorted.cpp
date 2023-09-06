#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    // Brute Force approach is to use linear search 
    // Second Approach is to Binary Search 2 functions that is apply binary search for each row
    bool approach3(vector<vector<int>> a,int k){
        int row = a.size();
        int col = a[0].size();

        int low = 0,high = col-1;
        while(low < row && high >= 0){
            if(a[low][high] == k){
                return 1;
            }else if(a[low][high] < k){
                low++;
            }else{
                high--;
            }
        }
        return 0;
    }
};

signed main(){

    Solution output;
    vector<vector<int>> mat = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};
    cout<<"\n";
    int k = 14;
    if(output.approach3(mat,k) == true){
        cout<<"Present\n";
    }else{
        cout<<"Not Present\n";
    }
    

    return 0;
}