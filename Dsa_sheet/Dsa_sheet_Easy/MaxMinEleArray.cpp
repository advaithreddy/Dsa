#include<iostream>
using namespace std;

struct Pair{
    int min;
    int max;
};

Pair getMinMax(int num[],int n){

    struct Pair minmax;

    if(n == 1){
        minmax.max = num[0];
        minmax.min = num[0];
        return minmax;
    }

    if (num[0] > num[1])
    {
        minmax.max = num[0];
        minmax.min = num[1];
    }
    else
    {
        minmax.max = num[1];
        minmax.min = num[0];
    }

    for(int i = 2;i<n;i++){
        if(num[i]>minmax.max){
            minmax.max = num[i];
        }else if(num[i]<minmax.min){
            minmax.min = num[i];
        }
    }
    return minmax;

}

int main(){
    int n;
    cin>>n;
    int num[10000];
    for(int i=0;i<n;i++){
        cin>>num[i];
    }

    struct Pair minmax = getMinMax(num,n);

    cout<<"Max and min number are "<<minmax.max<<" & "<<minmax.min<< " respectively \n"<<endl;
}