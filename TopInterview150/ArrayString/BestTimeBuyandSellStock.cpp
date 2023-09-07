#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/*
You are given an array prices where prices[i] is the 
price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and 
choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot 
achieve any profit, return 0.


Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy 
before you sell.
*/


// Simple appraoch
// We need to keep track of three elements maxi, mini, and profit
// Here maxi is not the maximum element in the array but the final answer
int part1(vector<int> &a, int n){
    int ans = INT_MIN, profit = 0, mini = a[0];
    for(int i=1;i<n;i++){
        profit = a[i] - mini;
        ans = max(ans, profit);
        mini = min(mini, a[i]);
    }

    // edge condition
    if(ans <= 0) return 0;

    return ans;
}

// Part II
/*
Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
*/

// This is similar to kadanes algorithm
int part2(vector<int> &a, int n){
    // same but here we will use mini as a pointer
    int mini = 0, cost = 0, profit = 0; // this is the final profit
    for(int i=1;i<n;i++){
        cost = a[i] - a[mini];
        if(cost > 0){
            profit += cost;
        }
        mini++;
    }
    return profit;
}

signed main(){

    vector<int> a = {7,1,5,3,6,4};
    int n = a.size();
    cout<<"\nThe Profit can be made is "<<part2(a,n)<<"\n";

    return 0;
}

