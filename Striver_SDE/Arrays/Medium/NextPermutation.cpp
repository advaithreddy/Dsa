#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


vector<int> permutation(vector<int> a){

    /* 
        Our main goal is to find the break point
        ex {6,1,5,4,3,0,0};
        in this 1 is the break point cause we traverse from the end and find the element arr[i] < arr[i+1]
        6 > "1 < 5" > 4 > 3 > 0 >= 0 -> Check double quote 
        2 cases
        If we dont find the break point then it is the last permutation we can simply reverse the array
        but is if do find check out the code
    */

    int n= a.size();
    // Step 1 Find Break point
    int break_point = -1;
    for(int i=n-1;i>=0;i--){
        if(a[i] < a[i+1]){
            break_point = i;
            break;
        }
    }

    // If no breakpoint exists
    if(break_point == -1){
        reverse(a.begin(),a.end());
        return a;
    }

    // But if it exists
    for(int i=n-1;i>break_point;i--){
        if(a[i] > a[break_point]){
            swap(a[i],a[break_point]);
            break;
        }
    }

    // Now final step reverse the right part
    reverse(a.begin() + break_point + 1, a.end());
    return a;
}


signed main(){

    vector<int> arr = {1,3,2};
    // Inbuilt function in C++ STL
    next_permutation(arr.begin(),arr.end());
    cout<<"This is Inbuilt STL function generated answer :";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    cout<<"This is Userbuilt function generated answer: ";
    vector<int> ans = permutation(arr);
    for(int i:ans){
        cout<<i<<" ";
    }

    return 0;
}