#include<iostream>
#include<algorithm>
using namespace std;


// Approach 1 O(n*log(n)) , O(n);
bool m1(int * arr, int n){
    int temp[n];

    // Copy the elements in temp
    for(int i=0;i<n;i++){
        temp[i] = arr[i];
    }

    sort(temp,temp+n);

    // front
    int front;
    for(front =0;front<n;front++){
        if(temp[front]!=arr[front]) break;
    }

    //  From back
    int back;
    for(back = n-1;back>=0;back--){
        if(temp[back]!=arr[back]) break;
    }

    // Now we got front and back points
    if(front>=back){
        return true;         // Already sorted
    }

    // now array looks like this      { 1,2,5,4,3}
    do{
        front++;
        if(arr[front-1]<arr[front]){
            return false;
        }
    }while(front!=back);
    return true;
}

// Approach 2 TC = O(n) SC = O(1)
bool m2(int * a, int n){
    // Initialize var x and y with -1
    int x = -1;
    int y = -1;

    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            if(x==-1){
                x=i;             // You can place only once so for this array { 1,2,5,4,3} x = 5that is staring point to rev the sub array
            }                      // and y = i+1 it will get changed until the last loop so y is last element of the subarray y = 3;
            y = i+1;
        }
    }

    if(x!=-1){
        reverse(a+x,a+y+1);
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                return false;
                return 0;
            }
        }
    }
    return true;
}

int main(){

    int a[]  = {1,2,5,4,3};
    int n = sizeof(a)/sizeof(a[0]);
    m2(a,n)?(cout<<"Yes"):(cout<<"No");
    return 0;
}