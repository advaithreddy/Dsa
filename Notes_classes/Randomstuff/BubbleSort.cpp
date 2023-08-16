#include<bits/stdc++.h>
using namespace std;

/* Bubble sortingWorking Principle
 * Take sie of arr and elements of arr
 * Compare it to the next value and swap it
 * use temp*/

int main(){
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements to be sorted : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // Using for loop

    for(int c =1;c<n;c++){
        for(int i=0;i<n-c;i++)
        {
            if(arr[i]>arr[i+1])
            {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1]= temp;
            }
        }
    }

    // Using while loop
//    while(n>counter)
//    {
//        for(int i=0;i<n-counter;i++)
//        {
//            if(arr[i]>arr[i+1])
//            {
//                int temp = arr[i];
//                arr[i] = arr[i+1];
//                arr[i+1]= temp;
//            }
//        }
//        counter++;
//    }
    cout<<"Sorted array using Bubble sort : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}