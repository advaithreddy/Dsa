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

int approach1(vi &a, int k){
    // Appraoch 1 is waste of time but see if and understand how subarray work
    int n = a.size();
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;

            // Now subarray b/w i and j
            for(int m=i;m<=j;m++){
                sum+=a[m];
            }

            if(sum == k){
                count++;
            }
        }
    }
    return count;
}

int approach2(vi& a, int k){
    // Same like approach 1 but taking two loops insted of 3
    int cnt =0;
    int n = a.size();
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += a[j];

            if(sum == k){
                cnt++;
            }
        }
    }
    return cnt;
}

int approach3(vi& a, int k){
    // optimal using map or so called prefSum
    int n = a.size();
    mii mp;
    int cnt = 0, preSum = 0;

    mp[0] = 1;
    for(int i=0;i<n;i++){
        // First i am adding the value to preSUm array
        preSum += a[i];

        // Now calculate the remove
        int remove = preSum - k;

        // Add this remove to map
        cnt += mp[remove];   // I mean we are adding the cnt to the no. of remove subarrays present in the map

        // Simply update the preSum count in the pre array
        mp[preSum] += 1;
    }
    return cnt;
}


int main(){
        
    vi a {3,1,2,4};
    int k = 6;
    int ans = approach3(a,k);
    cout<<"The maximum count of sub array with sum k is "<<ans<<"\n";
    
    return 0;
}


