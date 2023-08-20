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

vii optimal(vii &mat, int n, int m){
    
    // Step - 1 Traverse the matrix and mark first row and col accordingly
    int col0 = 1; // first col
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 0){
                // If you find zero anywhere
                mat[i][0] = 0;

                if(j!=0){
                    mat[0][j] = 0;
                }else{
                    col0 = 0;
                }
            }
        }
    }
    // Now we have filled the first row and column now based on this we will fill the remaining matrix
    // Step - 2 Fill the matrix based on the column
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(mat[i][j] != 0){
                if(mat[0][j] == 0 || mat[i][0] == 0){
                    mat[i][j] = 0;
                }
            }
        }
    }

    // Now its time to fill the first row and col
    if(mat[0][0] == 0){
        for(int j=0;j<m;j++){
            mat[0][j] = 0;
        }
    }

    if(col0 == 0){
        for(int i=0;i<n;i++){
            mat[i][0] = 0;
        }
    }
    return mat;
}


int main(){
        
    // Set Matrix 0 is popular problem and cover the imp concept
    /*
        In brute force we use an extra matrix and in Better we just use row matrix and col matrix 
        But in optimal approach we will just replace it in place But this we save a lot of space but here comes the problem the 
        mat[0][0] comes twice for consideration so insted we take int col0 = 1; this will say whether the col 0 is 0 or not
        Lets move to the code step by step
    */

    vii arr = {{1,0,1},{1,0,1},{1,1,1}};

    int n = arr.size();
    int m = arr.size();

    vii ans = optimal(arr, n, m);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}


