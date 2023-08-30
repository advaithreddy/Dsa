#include<bits/stdc++.h>
using namespace std;

/*
Problem Statement: Given an array ‘arr of integer numbers, ‘ar[i]’ 
represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, 
and the task is to allocate all the books to the students.
Allocate books in such a way that:

    Each student gets at least one book.
    Each book should be allocated to only one student.
    Book allocation should be in a contiguous manner.

You have to allocate the book to ‘m’ students such that the maximum number of pages assigned 
to a student is minimum. If the allocation of books is not possible. return -1
*/

// Helper Function
int helper(vector<int> &a,int p){
    int studentcount = 1;
    int totalpages = 0;
    for(int i=0;i<a.size();i++){
        if(totalpages + a[i] <= p){
            totalpages += a[i];
        }else{
            studentcount++;
            totalpages = a[i];
        }
    }
    return studentcount;
}

// Approach 1 using LS
int approach1(vector<int> &a, int n, int m){
    if(m>n) return -1; // base case

    int low = *max_element(a.begin(),a.end());
    int high = accumulate(a.begin(),a.end(),0);

    for(int pages = low ; pages <= high ; pages++){
        if(helper(a,pages) == m){
            return pages;
        }
    }
    return low;
}


// Approach 2 using BS
int approach2(vector<int> &a, int n, int m){
    // base case
    if(m>n) return -1;

    int left = *max_element(a.begin(),a.end());
    int right = accumulate(a.begin(),a.end(),0);

    while(left <= right){
        int mid = (left+right)/2;
        if(helper(a,mid) > m){
            left = mid+1;
        }else{
            right = mid -1;
        }
    }
    return left;
}

signed main(){

    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = approach2(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    
    return 0;
}