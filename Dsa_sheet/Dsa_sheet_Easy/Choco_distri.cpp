#include<iostream>
#include<algorithm>
using namespace std;

int chocolate(int arr[], int n,int m){
    int diff = 0;
    int mindiff = INT_MAX;

    sort(arr,arr+n);

    for(int i=0;i+m-1<n;++i){
        diff = arr[i+m-1]-arr[i];
        if(diff<mindiff){
            mindiff = diff;
        }
    }
    return mindiff;
}


int main(){
    int n;
    cout<<"Enter the no. of chocolate packets : "<<endl;
    cin>>n;
    int m;
    cout<<"Enter the no. of students : "<<"\n";
    cin>>m;
    int arr[10000];
    cout<<"Enter the array : ";
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }

    cout<<"Min difference is : "<<chocolate(arr,n,m)<<endl;
}