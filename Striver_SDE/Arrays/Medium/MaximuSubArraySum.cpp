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


// There are many approaches but the famous one is
// Kadanes algorithm
pii kadanes(vi a){
    int n = a.size();
    int sum = 0;
    int maxsum = INT_MIN;
    int s=0,e=0;
    int ts = 0;
    for(int i=0;i<n;i++){
        sum += a[i];

        if(sum > maxsum){
            maxsum = sum;
            s = ts;
            e = i;
        }

        if(sum < 0){
            sum = 0;
            ts = i+1;
        }
    }
    int len = e-s+1;
    return {len,maxsum};
}

// We can edit the above code itself but i dont want to touch it
pair<pii,vi> kadanesalgo(vi a){
    int n = a.size();
    int sum = 0;
    int maxsum = INT_MIN;
    int s=0,e=0;
    int ts = 0;
    vi values;
    for(int i=0;i<n;i++){
        sum += a[i];

        if(sum > maxsum){
            maxsum = sum;
            s = ts;
            e = i;
        }

        if(sum < 0){
            sum = 0;
            ts = i+1;
        }
    }
    int len = e-s+1;
    pii ans = make_pair(len, maxsum);
    for(int i=s;i<=e;i++){
        values.push_back(a[i]);
    }
    return {ans,values};
}

int main(){
        
    // int n;
    // cout<<"Enter the size:"; cin>>n;
    vi a = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    // cout<<"\nEnter the elements:\n";
    // inp(a);
    pair<pii,vi> ans = kadanesalgo(a);
    pii val = ans.first;
    vi values = ans.second;
    cout<<"The maximum length is "<<val.first<<" and the elements are [";
    for(int i=0;i<values.size();i++){
        cout<<values[i];
        if(i!=values.size()-1){
            cout<<",";
        }
    }
    cout<<"] "<<" and the sum of them is "<<val.second<<"\n";
    
    return 0;
}


