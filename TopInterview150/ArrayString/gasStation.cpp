#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

/*

There are n gas stations along a circular route, where the amount of gas at the ith station 
is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the 
ith station to its next (i + 1)th station. You begin the journey with an empty tank at one 
of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can 
travel around the circuit once in the clockwise direction, otherwise return -1. If there 
exists a solution, it is guaranteed to be unique
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // I hope you understood the problem 
        // Circular road need to filled
        // base case 
        // if What we need > whaat we haeve return -1;
        int total_fuel = accumulate(gas.begin(),gas.end(),0);
        int total_cost = accumulate(cost.begin(),cost.end(),0);
        if(total_fuel < total_cost) return -1;

        // Lets start our problem
        int n = gas.size();
        int curr=0, start = 0;
        for(int i=0;i<n;i++){
            curr += (gas[i] - cost[i]);
            if(curr < 0){
                start = i+1;
                curr = 0;
            }
        }
        return start;
    }
};

signed main(){

    Solution output;

    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};

    cout<<"\nThe Start index must be: "<<output.canCompleteCircuit(gas, cost)<<"\n";

    return 0;
}