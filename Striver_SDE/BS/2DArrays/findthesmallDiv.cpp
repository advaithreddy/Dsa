#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

/*
You are given an array of integers ‘arr’ and an integer i.e. a threshold value ‘limit’. 
Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the 
given array by it, the sum of the division’s result is less than or equal to the given threshold value.
*/

// helper function
int findMax(vector<int> a){
    int maxi = INT_MIN;
    for(int i:a){
        maxi = max(i,maxi);
    }
    return maxi;
}

int calculatesum(vector<int> &a,int div){
    int sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += ceil((double)(a[i]) / (double)(div));
    }
    return sum;
}

// Approach 1 using LS
int approach1(vector<int>& a, int lim){
    int range = findMax(a);
    for(int i=1;i<=range;i++){
        if(calculatesum(a,i) <= lim){
            return i;
        }
    }
    return -1;
}

// Approach 2 using BS
int approach2(vector<int> &a, int lim){
    int left = 0, right = findMax(a);
    while(left <= right){
        int mid = (left + right)/2;
        if(calculatesum(a,mid) <= lim){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return left;
}


signed main(){

    vector<int> a = {1,2,3,4,5};
    int thres = 8;

    cout<<"The min divisor is "<<approach2(a,thres);


    return 0;
}