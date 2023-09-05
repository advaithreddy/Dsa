#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;


/* 
    Advaith
   */
class Solution{
public:
    double solve(vi &a, vi &b){
        int n = a.size(), m = b.size();
        if(n > m) return solve(b,a);

        int lefthalf = (n+m+1)/2;

        // Apply binary search
        int low = 0, high = n;
        while(low <= high){
            int mid1 = (low + high) >> 1;
            int mid2 = lefthalf - mid1;

            // Now it is time to get the diagonal elements from two halves
            int l1 = mid1 == 0 ? INT_MIN : a[mid1-1];
            int l2 = mid2 == 0 ? INT_MIN : b[mid2-1];

            int r1 = mid1 == n ? INT_MAX : a[mid1];
            int r2 = mid2 == m ? INT_MAX : b[mid2];

            // Now checking the condition
            if(l1 <= r2 && l2 <= r1){
                if((n+m) %2 == 0){
                    return (max(l1,l2) + min(r1,r2)) / 2.0;
                }else{
                    return max(l1,l2);
                }
            }else if(l1 > r2){
                high = mid1-1;
            }else{
                low = mid1+1;
            }
        }
        return 0.0; // dummy
    }
};

int main() {
    
    vector<int> a = {1,4,7,10,12};
    vector<int> b = {2,3,6,15};
    Solution output;
    double ans = output.solve(a,b);
    cout<<fixed<<setprecision(1)<<ans;

    return 0;
}
