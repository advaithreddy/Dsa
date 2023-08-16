#include<iostream>
#include<vector>
using namespace std;

const int p = 31; // a prime number to use as the base for the hash function
const int m = 1e9 + 9; // a large prime number to use as the modulus

vector<int> rabinkarp(string const s, string const pat) {
    int n = s.size(), m = pat.size();
    vector<int> res;
    if (n < m) return res;

    // calculate powers of p modulo m
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; ++i)
        p_pow[i] = (p_pow[i-1] * p) % m;

    // calculate hash values for all substrings of s of length m
    vector<long long> h(n+1);
    for (int i = 0; i < n; ++i)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    // calculate hash value for the pattern
    long long h_pat = 0;
    for (int i = 0; i < m; ++i)
        h_pat = (h_pat + (pat[i] - 'a' + 1) * p_pow[i]) % m;

    // check all substrings of s of length m for a match with the pattern
    for (int i = 0; i <= n - m; ++i) {
        long long cur_h = (h[i+m] + m - h[i]) % m;
        if (cur_h == h_pat * p_pow[i] % m)
            res.push_back(i);
    }

    return res;
}


int main(){
    string txt = "aabacdabaab";
    string pat = "aab";
    vector<int> res = rabinkarp(txt,pat);
    for(int i:res){
        cout<<"Found at index : "<<i<<"\n";
    }

    return 0;
}
