#include<bits/stdc++.h>
using namespace std;

bool isEven(int n){
    if(n<=1)
        return false;
    if(n%2 != 0){
        return 0;
    }else{
        return 1;
    }
}

int gcd(int a,int b){
    if(a==0)
        return b;

    if(b==0)
        return a;

    while(a!=b){
        if(a>b){
            a = a-b;
        }else{
            b = b-a;
        }
    }
    return a;
}

int lcm(int a,int b,int c){
    int lcm = (a*b)/c;
    return lcm;
}

void binary(int n){
    int binaryNum[32];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}

// prime
bool isPrime(int n){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            cnt++;
        }
    }
    if(cnt<=2){
        return 1;
    }
    return 0;
}

int main() {
    int n;
    cout<<"Enter your number : "<<endl;
    cin>>n;

    if(isEven(n)){
        cout<<"It is an Even number";
    }else{
        cout<<"It is an Odd number";
    }
    cout<<"\n";
    if(isPrime(n)){
        cout<<" Given number is prime \n";
    }else{
        cout<<" Given number is not prime \n";
    }
//    cout<<endl;
//    int a,b;
//    cout<<"Enter the values of a and b: ";
//    cin>>a>>b;
//    cout<<endl;
//    int GCD = gcd(a,b);
//    cout<<"GCD of the values "<<a<<" and "<<b<<" is "<<GCD<<endl;
//    cout<<"LCM of the values "<<a<<" and "<<b<<" is "<<lcm(a,b,GCD)<<endl;
//
//    double x = 0.3*3+0.1;
//    printf("%.18f\n", x); // 0.99999999999999988898
//    int l = 7, m = 4;
//    cout<<abs(b-b)<<"\n";
//    if (abs(l-m) < 1e-9) {
//        cout<<"Yes\n";
//
//    }


    return 0;

}