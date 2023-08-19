#include<iostream>
#include<vector>
#include<map>
using namespace std;


// Approach 1- Using Count Do it if necessary
// Approach 2 - Using Map given below
int approach1(vector<int> a){
    map<int,int> mp;
    for(int i:a){
        mp[i]++;
    }
    int maxi = 0;
    int ele=0;
    for(auto &i:mp){
        if(i.second > maxi){
            maxi = i.second;
            ele = i.first;
        }
    }
    return ele;;
}

// Approach 3 - Moore's voting Algorithm
/*
    Basically, we are trying to keep track of the occurrences of the majority element and minority elements dynamically.
    That is why, in iteration 4, the count becomes 0 as the occurrence of Element and the occurrence of the other elements 
    are the same. So, they canceled each other. This is how the process works. The element with the most occurrence will 
    remain and the rest will cancel themselves.

    Here, we can see that 2 is the majority element. But if in this array, the last two elements were 3, then the Element 
    variable would have stored 3 instead of 2. For that, we need to check if the Element is the majority element by traversing
    the array once more. But if the question guarantees that the given array contains a majority element, then we can bet the 
    Element will store the majority one.
*/
int approach2(vector<int> a){
    int n = a.size();
    int el = 0;
    int cnt = 0;
    for(int )
}

signed main(){

    vector<int> a = {2,2,1,1,1,2,2};
    cout<<"The majority element is:\n"<<solve(a);
    
    return 0;
}