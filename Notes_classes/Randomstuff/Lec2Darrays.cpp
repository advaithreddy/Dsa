#include<bits/stdc++.h>
using namespace std;


void rowsum(int arr[][4],int n,int m){
    for(int i=0;i<n;++i){
        int sum =0;
        for(int j=0;j<m;++j){
            sum += arr[i][j];
        }
        cout<<sum<<" ";
    }
}

void colsum(int arr[][4],int n,int m){
    for(int j=0;j<m;++j){
        int sum =0;
        for(int i=0;i<n;++i){
            sum += arr[i][j];
        }
        cout<<sum<<" ";
    }
}

int largestSumrow(int arr[][4],int n,int m){
    int maxi = INT_MIN;
    int rowI = 0;
    for(int i=0;i<n;++i){
        int sum =0;
        for(int j=0;j<m;++j){
            sum += arr[i][j];
        }
        if(sum>maxi){
            maxi = sum;
            rowI = i;
        }
    }
    cout<<"Maximum sum in the row is : "<<maxi<<endl;
    cout<<"And its row is ";
    return rowI;
}

bool linearSearch(int arr[][4],int k, int n, int m){
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(arr[i][j] == k) {
                return 1;
            }
        }
    }
    return 0;
}



int main(){
    int arr[3][4];
    // Input
    cout<<"Enter the array elements : ";
    for(int i=0;i<3;++i){
        for(int j=0;j<4;++j){
            cin>>arr[i][j];
        }
    }

    // Output
    cout<<"Printing the array"<<endl;
    for(int i=0;i<3;++i){
        for(int j=0;j<4;++j){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int k;
    cout<<"Enter key value : ";
    cin>>k;

    if(linearSearch(arr,k,3,4)){
        cout<<"Found"<<endl;
    }else{
        cout<<"Not found"<<endl;
    }

    cout<<"Row Sum"<<endl;
    rowsum(arr,3,4);
    cout<<endl;
    cout<<"Column Sum"<<endl;
    colsum(arr,3,4);
    cout<<endl;

    cout<<largestSumrow(arr,3,4)<<endl;

    return 0;
}
