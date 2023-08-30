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


/*
Problem Description
Input Format: N = 4, a[] = {7, 15, 6, 3}, h = 8
Result: 5
Explanation: If Koko eats 5 bananas/hr, he will 
take 2, 3, 2, and 1 hour to eat the piles accordingly. So, he will take 8 hours to complete all the piles. 

So the problem simply states we need to find the k value that is min value of 'k' in which koko can eat bananas in given h time
and eat all bananas

*/


// Approach 1 using LS
// We will have 3 functions
int findMax(vi &a){
    int maxi = INT_MIN;
    for(int i:a){
        maxi = max(maxi, i);
    }
    return maxi;
}

int calculatetime(vi &a, int hour){
    // here hour is not h it is the i value which will change by the loop in the below function
    int time = 0;
    for(int i=0;i<a.size();i++){
        time += ceil((double)a[i] / (double)hour);
    }
    return time;
}

int approach1(vi& a, int h){
    int maxi = findMax(a);

    for(int k=1;k<=maxi;k++){
        // for each k we need to check
        int reqtime = calculatetime(a,k);
        if(reqtime <= h){
            return k;
        }
    }
    return -1;
}

// Approach 2 using BS
// I will use the same above functions 
int approach2(vi &a, int h){
    int left = 1;
    int right = findMax(a);
    while(left <= right){
        int k = (left + right)/2;
        int reqtime = calculatetime(a,k);
        if(reqtime <= h){
            right = k-1;
        }else{
            left = k+1;
        }
    }
    return left;
}


int main(){
        
    vi a = {25, 12, 8, 14, 19};
    int h = 5;
    cout<<"The Min K value is "<<approach2(a,h);
    
    return 0;
}


