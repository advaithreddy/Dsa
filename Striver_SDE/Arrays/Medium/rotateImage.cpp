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

vii approach1(vii &mat){
    int n = mat.size();

    // Brute force approach take a dummy matrix and fill manually
    vector<vector<int>> dummy(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dummy[j][n-i-1] = mat[i][j];
        }
    }
    return dummy;
}

vii approach2(vii mat){
    // Approach 2 is smart approach just transpose the matrix and reverse each row
    // Transpose the matrix
    int n= mat.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Now reverse each row
    for(int j=0;j<n;j++){
        reverse(mat[j].begin(),mat[j].end());
    }
    return mat;
}


int main(){
        
    vii mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vii rotated = approach1(mat);
    cout<<"Rotated Matrix:\n";
    for(auto i:rotated){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}


