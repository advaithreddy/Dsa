#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;


// Question 1 Longest Subarray with given Sum K(Positives)
int Approach1(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++) { // starting index
        for (int j = i; j < n; j++) { // ending index
            // add all the elements of
            // subarray = a[i...j]:
            long long s = 0;
            for (int K = i; K <= j; K++) {
                s += a[K];
            }

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}

int Approach2(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++) { // starting index
        long long s = 0; // Sum variable
        for (int j = i; j < n; j++) { // ending index
            // add the current element to
            // the subarray a[i...j-1]:
            s += a[j];

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}


int Approach3(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        long long rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

int Approach4(vector<int> arr, long long k){
    // Two pointer or sliding window approach
    long long int n = arr.size();
    long long int left = 0, right = 0;
    long long int sum = arr[0];
    long long int maxlen = 0;
    while(right < n){
        while(left<=right && sum >k){
            sum -= arr[left];
            left++;
        }

        if(sum == k){
            maxlen = max(maxlen,right-left+1);
        }

        right++;
        if(right < n) sum += arr[right];
    }
    return maxlen;
}


// Question 2 Longest Subarray with sum K | [Postives and Negatives]
// Here the three approaches are same as above first 3 and the optimal is third one
// Approach 3 is optimal cause we cant use pointers here



signed main(){

    vector<int> a = {-1,1,1};
    long long k = 1;
    int len = Approach3(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";

    return 0;
}

// Easy Completed