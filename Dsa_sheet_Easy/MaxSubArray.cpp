#include <iostream>
#include <vector>

using namespace std;

int Kadanes(int arr[], int n){
    int sum =arr[0];
    int maxi =INT_MIN;

    for(int i=0;i<n-1;i++){
        sum += arr[i];
        maxi = max(maxi,sum);

        if(sum<0)
            sum =0;
    }
    return maxi;
}

int main(){
    int n;
    cin>>n;
    int arr[100000];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    cout<<Kadanes(arr,n);
}