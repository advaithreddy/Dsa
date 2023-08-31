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


int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); // size of the array
    long double low = 0;
    long double high = 0;

    //Find the maximum distance:
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    //Apply Binary search:
    long double diff = 1e-6 ;
    while (high - low > diff) {
        long double mid = (low + high) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return high;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}

