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

vi v1approach1(vi a, int n){
    vi pos;
    vi neg;
    for(int i:a){
        if(i>0) pos.pb(i);
        else neg.pb(i);
    }

    for(int i=0;i<n/2;i++){
        a[2*i] = pos[i];
        a[2*i+1] = neg[i];
    }
    return a;
}

vi v1approach2(vi A){

    int n = A.size();

    // Define array for storing the ans separately.
    vector<int> ans(n,0);

    // positive elements start from 0 and negative from 1.
    int posIndex = 0, negIndex = 1;
    for(int i = 0;i<n;i++){
        
        // Fill negative elements in odd indices and inc by 2.
        if(A[i]<0){
            ans[negIndex] = A[i];
            negIndex+=2;
        }
        
        // Fill positive elements in even indices and inc by 2.
        else{
            ans[posIndex] = A[i];
            posIndex+=2;
        }
    }
  
  return ans;
}


// Variant 2 If pos and Neg elements count is not equal
vi v2approach(vi a){
    // It is hybrid of v1ap1 and v1ap2;
    vi pos;
    vi neg;

    for(auto i:a){
        if(i>0) pos.pb(i);
        else neg.pb(i);
    }

    // Now check count
    if(pos.size() > neg.size()){

        // fill regularly until one ends
        // here - is less fill upto neg.size ends so we can fill remaining + ele 
        for(int i=0;i<neg.size();i++){
            a[2*i] = pos[i];
            a[2*i+1] = neg[i];
        }

        // Now remainign elements
        // find the index
        int index = neg.size()*2;
        for(int i=neg.size();i<pos.size();i++){
            // By neg.size() to pos.size() we will get remainng pos elements
            a[index] = pos[i];
            index++;
        }
    }else{
        // Repeat the same for the - elements
        // here + is less
        for(int i=0;i<pos.size();i++){
            a[2*i] = pos[i];
            a[2*i+1] = neg[i];
        }

        // fill the remainig ele
        int index = pos.size()*2;
        for(int i=pos.size();i<neg.size();i++){
            a[index] = neg[i];
            index++;
        }
    }
    return a;
}


int main(){
        
    vector<int> A = {1,2,-4,-5,3,4,-7,-8,-14};

    vector<int> ans = v2approach(A);
    
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}


