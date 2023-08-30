#include<bits/stdc++.h>
using namespace std;
#define f0(a,b) for(int i=a;i<b;i++)
#define f1(i,a,b) for(i=a;i<b;++i)
#define tst int t; cin>>t
#define vi vector<int>
#define MAX_SIZE 10000
#define vii vector<vector<int>>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long ll; typedef long double ld;
const int inf = INT_MAX, minf = INT_MIN;
typedef unsigned long long ULL;
#define ll long long
#define pb push_back
#define F first
#define S second
#define pll pair<ll, ll>
#define pii pair<int,int>
#define vll vector<ll>
#define mii map<int,int>
#define msi map<string, int>
#define sti set<int>
#define cov(x,n) find(x.begin(),x.end(),n)
#define trav(i,a) for(auto &i:a)
#define inp(a) for(auto& i:a){cin>>i;}
#define out(a) for(auto& i:a){cout<<i<<" ";}
typedef unordered_set<int> usi; typedef unordered_map<int,int> umii;
const int mod = 1e9 + 7;
typedef std::bitset<sizeof(int) * CHAR_BIT> BinaryNum;
std::string toBinary(int n) {
    return BinaryNum(n).to_string();
}


/*  
        Advaith 
*/

// Helper funcions
bool helper(vi &a, int day, int k, int m){
    int cnt = 0;
    int Bou = 0;
    for(int i=0;i<a.size();i++){
        if(a[i] <= day){
            cnt++;
        }else{
            Bou += (cnt/k);
            cnt = 0;
        }
    }
    Bou += (cnt/k);
    return Bou >= m;
}

// Approach 1
int approach1(vi &a, int m, int k){
    // Base case
    // if a.size() < m*k return -1
    int val = m*k;
    if(a.size() < val) return -1;

    // Now let us move to out problem
    // Find the range
    // ie mini and maxi
    int mini = INT_MAX, maxi = INT_MIN;
    for(int i : a){
        mini = min(mini, i);
        maxi = max(maxi, i);
    }

    for(int i=mini; i<=maxi; i++){
        if(helper(a,i,k,m)){
            return i;
        }
    }
    return -1;
}


// Approach 2 using BS
int approach2(vi& a,int m, int k){
    // Base case
    // if a.size() < m*k return -1
    int val = m*k;
    if(a.size() < val) return -1;

    // Now let us move to out problem
    // Find the range
    // ie mini and maxi
    int mini = INT_MAX, maxi = INT_MIN;
    for(int i : a){
        mini = min(mini, i);
        maxi = max(maxi, i);
    }

    // BS
    int left = mini, right = maxi;
    while(left <= right){
        int mid = (left + right)/2;
        if(helper(a,mid,k,m)){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return left;
}

int main(){
        
    int m = 2, k= 3;
    vi a = {7, 7, 7, 7, 13, 11, 12, 7};
    cout<<"We can make out required bouquets by "<<approach2(a,m,k)<<"th day\n";
    
    return 0;
}


