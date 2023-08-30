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


// variant 1 = They may ask to return yes or no
// variant 2 = they may ask to return the indices else {-1,-1};

// Approach 1 using two loops
// Code variant 1 
bool approach1c1(vi a, int k){
    int n= a.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i] + a[j] == k) return 1;
        }
    }
    return 0;
}

// code variant 2
pii approach1c2(vi a, int k){
    int n = a.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i] + a[j] == k){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

// Approach 2 using hashing
// code variant 1
bool approach2c1(vi a, int k){
    umii hash;
    int n = a.size();
    for(int i=0;i<n;i++){
        int num = a[i];
        int need = k - num;
        if(hash.find(need) != hash.end()){
            return 1;
        }
        hash[num] = i;
    }
    return 0;
}

//code variant 2
pii approach2c2(vi a, int k){
    umii hash;
    int n = a.size();
    for(int i=0;i<n;i++){
        int num = a[i];
        int need = k - num;
        if(hash.find(need) != hash.end()){
            return {hash[need],i};
        }
        hash[num] = i;
    }
    return {-1,-1};
}

// Approach 3 U can name it as 2 pointers or BS
// code variant 1
bool approach3c1(vi a, int k){
    sort(a.begin(),a.end());  // <- First sort it
    int left= 0, right = a.size()-1;
    while(left < right){
        if(a[left]+a[right] == k){
            return 1;
        }else if(a[left] + a[right] < k){
            left++;
        }else{
            right--;
        }
    }
    return 0;
}

// code variant 2
pii approach3c2(vi a, int k){
    sort(a.begin(),a.end());
    int left = 0, right = a.size()-1;
    while (left<right){
        if(a[left] + a[right] == k){
            return {left, right};
        }else if(a[left] + a[right] < k){
            left++;
        }else{
            right--;
        }
    }
    return {-1,-1};
}


int main(){
        
    int n; cout<<"Enter the size of array:\n";
    cin>>n;
    vi a(n);
    cout<<"Enter the elements\n";
    inp(a);
    cout<<"Enter the target\n";
    int k; cin>>k;
    // Answer for variant 1
    if(approach3c1(a,k)){
        cout<<"\nYes it exists\n";
    }else{
        cout<<"\nNo it dont\n";
    }
    // Answer for variant 2
    pii ans = approach3c2(a,k);
    cout<<"\nThe indices are: ["<<ans.first<<","<<ans.second<<"]\n";


    return 0;
}


