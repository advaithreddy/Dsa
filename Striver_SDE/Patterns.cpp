#include<iostream>
using namespace std;
#define linebreak(){ cout<<endl<<endl;}
#define initialize(n,m){n=0,m=0; cin.ignore();}

int main(){

    int n,m;
    cin>>n>>m;

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;++j){
    //         cout<<"*"<<" ";
    //     }
    //     cout<<"\n";
    // }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}