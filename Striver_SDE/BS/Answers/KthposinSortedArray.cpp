#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef set<int> si;
typedef set<ll> sll;
typedef set<pii> spii;
typedef set<pll> spll;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef map<int, vi> mivi;
typedef map<int, vvi> mivii;
typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> umll;
typedef unordered_map<int, vi> umivi;
typedef unordered_map<int, vvi> umivii;
typedef priority_queue<int> pqi;
typedef priority_queue<int, vi, greater<int>> pqmin;
typedef priority_queue<ll> pql;
typedef priority_queue<ll, vll, greater<ll>> pqlmin;
#define inp(a) for(auto &i:a){cin>>i;}
#define out(a) for(auto &i:a){cout<<i<<" ";}cout<<"\n";
#define toBinary(n) bitset<32>(n).to_string()
#define toInt(binary) bitset<32>(binary).to_ulong()
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define power(x, y) pow(x, y)
#define abs(x) ((x) > 0 ? (x) : -(x))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define fastInput ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const int MOD = 1e+7;

/* 
    Advaith
   */

class Solution{
public:
    // Two pointer approach
    int approach1(vi a,vi b,int m, int n, int k){

        int count = 0, ans = 0;
        int i=0,j=0;
        while(i<m && j<n){
            if(count == k){
                return ans;
            }else if(a[i] < b[j]){
                ans = a[i];
                ++i;
            }else{
                ans = b[j];
                ++j;
            }
            ++count;
        }

        if(count != k){
            if(i != m-1){
                ans = a[k-count];
            }else{
                ans = b[k-count];
            }
        }
        return ans;
    }

    int approach2(vi a,vi b,int m, int n, int k){
        if(m>n) return approach2(b,a,n,m,k);

        int low = max(0,k-m), high = min(k,n);

        while(low<=high){
            int mid1 = (low+high) >> 1;
            int mid2 = k - mid1;

            int l1 = mid1 == 0 ? INT_MIN : a[mid1-1];
            int l2 = mid2 == 0 ? INT_MIN : b[mid2-1];

            int r1 = mid1 == n ? INT_MAX : a[mid1];
            int r2 = mid2 == m ? INT_MAX : b[mid2];

            // Now apply the condition
            if(l1 <= r2 && l2 <= r1){
                return max(l1,l2);
            }else if(l1 > r2){
                high = mid1-1;
            }else{
                low = mid1 + 1;
            }
        }
        return 1; // dummy
    }
}s;

int main() {
    

    vi a = {2,3,6,7,9};
    vi b = {1,4,8,10};
    int m = a.size(), n = b.size();
    int k = 5;
    Solution output;
    int ans = output.approach1(a,b,m,n,k);
    cout<<"\nThe kth element in the sorted array is "<<ans<<"\n";
    


    return 0;
}
