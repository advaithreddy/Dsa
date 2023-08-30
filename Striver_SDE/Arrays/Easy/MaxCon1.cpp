#include<iostream>
using namespace std;

int solve(int *a, int n){
    int maxcount = 0;
    int curr = 0;
    for(int i=0;i<n;i++){
        if(a[i] == 1){
            curr++;
        }else{
            curr = 0;
        }
        if(curr>maxcount)
            maxcount = curr;
    }
    return maxcount;
}

signed main(){


    int a[] = {1,0,1,1,0,1};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<"The Length of max concesutive one is: "<<solve(a,n)<<"\n";
    
    return 0;
}