#include<iostream>
using namespace std;

void reverseArray(int arr[], int arr_size){
    int s = 0;
    int e = arr_size-1;

    while(s<e){
        int temp = arr[s];
        arr[s]= arr[e];
        arr[e] = temp;
        s++;
        e--;
    }
}

void printArray(int arr[], int arr_size){
    for(int i=0;i<arr_size;i++){
        cout<<arr[i];
    }
    cout<<endl;
}

int main(){
    int arr_size;
    cout<<"Enter the array Size : "<<endl;
    cin>>arr_size;
    int arr[10000];
    cout<<"Enter your array : "<<endl;
    for(int i=0;i<arr_size;i++){
        cin>>arr[i];
    }
    cout<<"Your array is: ";
    printArray(arr, arr_size);
    reverseArray(arr,arr_size);
    cout<<"Reversed array is:";
    printArray(arr,arr_size);

}


// Time Complexity = O(n);
// Space Complexity = O(1);