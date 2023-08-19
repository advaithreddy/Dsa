#include<bits/stdc++.h>
using namespace std;
#define inp(a) for(auto& i:a){cin>>i;}
#define out(a) for(auto& i:a){cout<<i<<" ";}
#define vi vector<int>


/*  
        Advaith 
*/


// Approach 1 - use count variables
void approach1(vi &a){
    int cnt0=0,cnt1=0,cnt2=0;
    int n = a.size();
    for(int i:a){
        if(i==0) cnt0++;
        else if(i==1) cnt1++;
        else cnt2++;
    }

    for(int i=0;i<cnt0;i++) a[i] = 0;
    for(int i=cnt0;i<cnt0 + cnt1;i++) a[i] = 1;
    for(int i=cnt0 + cnt1;i<n;i++) a[i] = 2;
}

// Approach 2 - Dutch National Flag Algorithm
// Here left points 0 
// right points 2
// and with the help of mid we will move our array and swap accordingly;
void approach2(vi &a){
    int low=0, mid = 0, high = a.size()-1;
    while(mid<=high){
        if(a[mid] == 0){           // 0 case
            swap(a[low],a[mid]);
            low++;
            mid++;   
        }else if(a[mid] == 1){       // 1 case
            mid++;
        }else{                    // 2 case
            swap(a[mid] , a[high]);
            high--;
        }
    }
}

int main(){
        
    int n; cout<<"Enter the size of array:\n";
    cin>>n;
    vi a(n);
    cout<<"Enter the elements\n";
    inp(a);
    approach2(a);
    cout<<"Sorted order:\n";
    out(a);


    return 0;
}

