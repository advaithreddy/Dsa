#include<bits/stdc++.h>
using namespace std;


void printarray(int a[], int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}

int getmax(int arr[], int n){
    int mx = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>mx) mx= arr[i];
    }
    return mx;
}

void countsort(int arr[], int n){
    int mx = getmax(arr,n);
    int* count = (int *) malloc((mx+1)*sizeof(int));
    for(int i=0;i<n;i++){
        count[i] = 0;
    }

    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }

    int i=0,j=0;
    while(i<=mx){
        if(count[i]>0){
            arr[j] = i;
            count[i]--;
            j++;
        }else{
            i++;
        }
    }
}

int main(){
    int n,a[100000];
    cout<<"Enter the size of the array : "<<"\n";
    cin>>n;
    cout<<"Enter the elements of the array: "<<"\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Before sorting : \n";
    printarray(a,n);
    cout<<"\n";
    countsort(a,n);
    cout<<"After sorting\n";
    printarray(a,n);
    return 0;
}