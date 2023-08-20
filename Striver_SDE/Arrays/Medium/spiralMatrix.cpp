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

vi sprialprint(vii mat, int n, int m){

    // Easy approach You will get once you see the code and dry run
    int count = 0, total = n*m;

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = n-1;
    int endingCol = m-1;

    vi ans;

    // Simple print the num unti you reach the count
    while(count < total){
        // Now print first Row -> ending col -> ending row -> firstcol 
        // First Row
        for(int i=startingCol;count<total && i<=endingCol;i++){
            ans.push_back(mat[startingRow][i]);
            count++;
        }
        startingRow++; // We need to increment the row

        // Ending Col
        for(int i=startingRow ; count<total && i<=endingRow;i++){
            ans.push_back(mat[i][endingCol]);
            count++;
        }
        endingCol--;

        // For Ending Row
        for(int i=endingCol ;count<total && i>=startingCol;i--){
            ans.pb(mat[endingRow][i]);
            count++;
        }
        endingRow--;

        // For First col
        for(int i=endingRow;count<total && i>=startingRow;i--){
            ans.pb(mat[i][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}


int main(){
        
    vii mat {{1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}};

    int n= mat.size();
    int m = mat[0].size();

    vi ans = sprialprint(mat,n,m);
    cout<<"[ ";
    for(auto i:ans){
        cout<<i<<" ";
    }cout<<"]";
    
    return 0;
}


