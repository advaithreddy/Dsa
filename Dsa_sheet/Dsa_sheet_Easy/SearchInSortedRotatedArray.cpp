#include<iostream>
using namespace std;

int getPivot(int arr[],int size){
    int start = 0;
    int end = size-1;
    int mid;
    while(start<end){
        mid = start + (end - start)/2;
        if(arr[mid] >= arr[0]){
            start = mid + 1;
        }else{
            end = mid;
        }
    }
    return start;
}

int binarysearch(int arr[],int s, int e,int key){
    int low  = s;
    int high = e;

    while(s<=e){
        int mid = low + (high-low)/2;

        if(arr[mid] == key){
            return mid;
        }else if(arr[mid]<key){
            low = mid +1;
        }else{
            high = mid -1;
        }
    }
    return -1;
}

int main(){
    int size = 7;
    int arr[10000] = {4,5,6,7,0,1,2};
    int key = 5;

    int p = getPivot(arr,size);

    if(key >= arr[p] && key <= arr[size-1]){
        cout<<binarysearch(arr,p,size-1,key)<<endl;
    }else{
        cout<<binarysearch(arr,0,p-1,key)<<endl;
    }
}


// Time Complexity = O(n);
// Space complexity = 0(1);