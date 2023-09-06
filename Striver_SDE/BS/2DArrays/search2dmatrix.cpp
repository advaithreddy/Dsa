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

bool solve(vvi &a,int k){
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

int main() {

    vvi mat = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    cout<<"\n";
    int k = 14;
    if(solve(mat,k) == true){
        cout<<"Present\n";
    }else{
        cout<<"Not Present\n";
    }
    



    return 0;
}
