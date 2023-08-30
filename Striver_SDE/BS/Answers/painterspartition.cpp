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

// Same probelm from the previous book allocationn and split array

/* 
Problem Statement: Given an array/list of length ‘N’, where the array/list represents the boards 
and each element of the given array/list represents the length of each board. Some ‘K’ numbers of 
painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint. 
You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ 
boards under the constraint that any painter will only paint the continuous sections of boards.

*/

// Helper Function
int helper(vector<int> &a,int p){
    int count = 1;
    int partitions = 0;
    for(int i=0;i<a.size();i++){
        if(partitions + a[i] <= p){
            partitions += a[i];
        }else{
            count++;
            partitions = a[i];
        }
    }
    return count;
}

// Approach 1 using LS
int approach1(vector<int> &a, int n, int m){
    if(m>n) return -1; // base case

    int low = *max_element(a.begin(),a.end());
    int high = accumulate(a.begin(),a.end(),0);

    for(int pages = low ; pages <= high ; pages++){
        if(helper(a,pages) == m){
            return pages;
        }
    }
    return low;
}


// Approach 2 using BS
int approach2(vector<int> &a, int n, int m){
    // base case
    if(m>n) return -1;

    int left = *max_element(a.begin(),a.end());
    int right = accumulate(a.begin(),a.end(),0);

    while(left <= right){
        int mid = (left+right)/2;
        if(helper(a,mid) > m){
            left = mid+1;
        }else{
            right = mid -1;
        }
    }
    return left;
}


int main(){
        
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;
    int n = 4;
    int ans = approach1(boards, n,k);
    cout << "The answer is: " << ans << "\n";
    
    return 0;
}


