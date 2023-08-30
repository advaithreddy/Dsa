#include<bits/stdc++.h>
using namespace std;


/*

You are given a positive integer n. 
Your task is to find and return its square root. If ‘n’ is not a perfect square, 
then return the floor value of ‘sqrt(n)’.

*/

void squareroot(int n){
    int left = 0, right = n;
    while(left <= right){
        int mid = (left + right) /2;
        int val = mid * mid;
        if(val <= n){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    cout<<right<<"\n";
}

int main(){
        
    squareroot(81);
    
    
    return 0;
}


