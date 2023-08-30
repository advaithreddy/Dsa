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

// Approach 1 Brute Force   - O(n^2)
bool linearsearch(vi a,int k){
    for(int i=0;i<a.size();i++){
        if(a[i] == k){
            return 1;
        }
    }
    return 0;
}

int approach1(vi a, int n){
    int maxi = 0;
    for(int i=0;i<n;i++){
        int x = a[i];
        int cnt = 1;  // base count is 1 cause ther will be atleast one number minimal
        while(linearsearch(a,x+1) == true){
            x += 1;    // In while loop until you find an element which is x+1 you can increase the count
            cnt += 1; // Incerement the count
        }
        maxi = max(maxi, cnt);
    }
    return maxi;
}



// Approach 2 Using Sorting   o(n)
int approach2(vi a, int n){
    sort(a.begin(),a.end());
    int maxi = 0;
    int cur = 1;
    for(int i=0;i<n-1;i++){
        if(a[i+1] == a[i] + 1){
            cur++;
            maxi = max(maxi , cur);
        }else{
            cur = 1;
        }
    }
    return maxi;
}


// Approach 3 Using Set Data structure
int approach3(vi a, int n){
    if(n==0) return 0;

    // Use set to store the elements
    usi s;
    for(int i:a){
        s.insert(i);
    }

    int maxi = 1;
    // Now check for the elements
    for(int i:s){
        // Here i is the first number in out case its 100
        if(s.find(i-1) == s.end()){
            int cnt = 1;
            int x = i;
            while(s.find(x+1) != s.end()){
                x += 1;
                cnt++;  
            }
            maxi = max(maxi,cnt);
        }
    }
    return maxi;
}

int main(){

    vi a = {3,8,5,7,6};
    int n = a.size();
    cout<<"The longest subsequence is : "<<approach3(a,n);

    cout<<"\n";
    
    return 0;
}


