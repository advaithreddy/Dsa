#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

// Search the row with max 1
class Solution{
public:
    int approach1(vector<vector<int>> &mat){
        int row = mat.size();
        int col = mat[0].size();

        int maxCount = 0;
        int rowIndex = -1;
        int count = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j] == 1){
                    count++;
                }
            }
            if(count > maxCount){
                maxCount = count;
                rowIndex = i;
            }
            count = 0;
        }
        return rowIndex;
    }

    // helper function for approach 2
    int helper(vector<int> a, int n, int k){
        int low = 0, high = n-1;
        int ans = n;
        
        // Lower bound code
        while(low <= high){
            int mid = (low+high) >> 1;
            if(a[mid] >= k){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }

    int approach2(vector<vector<int>> mat){
        int row = mat.size();
        int col = mat[0].size();

        int cnt_max = 0;
        int index = -1;

        for(int i=0;i<row;i++){
            int cnt = col - helper(mat[i],col, 1);
            if(cnt > cnt_max){
                cnt_max = cnt;
                index = i;
            }
        }
        return index;
    }
};

signed main(){

    vector<vector<int>> mat = {{1,1,0},{1,0,0},{1,1,1}};
    Solution output;
    int ans = output.approach2(mat);
    switch (ans)
    {
    case 1:
        cout<<"\nThe row with max no. of 1's "<<ans<<"st row\n";
        break;
    case 2:
        cout<<"\nThe row with max no. of 1's "<<ans<<"nd row\n";
        break;
    case 3:
        cout<<"\nThe row with max no. of 1's "<<ans<<"rd row\n";
        break;
    default:
        cout<<"\nThe row with max no. of 1's "<<ans<<"th row\n";
        break;
    }
    

    return 0;
}