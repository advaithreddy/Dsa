#include<iostream>
using namespace std;

/*

Given two numbers N and M, find the Nth root of M. The nth root 
of a number M is defined as a number X when raised to the power N equals M. 
If the ‘nth root is not an integer, return -1.

*/

// Approach 1
// Brute way to find the pow
int helper(int base, int exponent){
    
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

// Using Bs here to find pow too
int func(int b, int exp) {
    int ans = 1;
    int base = b;
    while (exp > 0) {
        if (exp % 2) {
            exp--;
            ans = ans * base;
        }
        else {
            exp /= 2;
            base = base * base;
        }
    }
    return ans;
}


int nthroot(int n, int m){
    for(int i=1;i<=m;i++){
        if(func(i,n) == m){
            return i;
        }else if(func(i,n) > m){
            break;
        }
    }
    return -1;
}

// Approach 2 using BS
int nthrootbs(int n, int m){
    int left = 0, right = m;
    while(left <= right){
        int mid = (left + right)/2;
        if(func(mid, n) == m){
            return mid;
        }else if(func(mid, n) > m){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return -1;
}

signed main(){

    int n = 3,m = 64;

    // So num cube root of 27 is 3;
    cout<<"The "<<n<<" root of "<<"number "<<m<<" is "<<nthrootbs(n,m);
    
    return 0;
}