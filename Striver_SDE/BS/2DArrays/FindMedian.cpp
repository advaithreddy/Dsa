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

// Helper function
int helper(vi &a,int mid){
    // Using bs here too
    int n = a.size();
    int low =0,high = a.size()-1;
    while(low <= high){
        int m = (low + high) >> 1;
        if(a[m] <= mid){
            low = m+1;
        }else{
            high = m-1;
        }
    }
    return low;
}

// Approach 1 - Naive Approach
int approach1(vvi &a){
    int n = a.size();
    int m = a[0].size();
    vi b(n*m);
    int k = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            b[k] = a[i][j];
            k++;
        }
    }
    sort(b.begin(),b.end());
    return b[b.size()/2];
}

// Approach 2 - Using BInary Search
int approach2(vvi &a){
    int row = a.size();
    int col = a[0].size();

    // First we need to find the range for that find min element from the first column
    // and max can be found from the last column
    int low,high;
    for(int i=0;i<row;i++){
        low = min(low, a[i][0]);
        high = max(high, a[i][col-1]);
    }
    while(low <= high){
        int mid = (low + high) >> 1;
        int cntless = 0;
        for(int i=0;i<row;i++){
            cntless += helper(a[i],mid);
        }

        if(cntless <= (row * col) /2){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return low;
}


int main() {

    vvi a = {{1,3,8},{2,3,4},{1,2,5}};
    cout<<"\nThe median is:"<<approach2(a)<<"\n";
    
    return 0;
}
