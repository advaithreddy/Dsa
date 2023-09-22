#include<bits/stdc++.h>
using namespace std;

int m=10;

// Inline function
inline int sum(int a, int b){
    return a+b;
}

// Function overloading
int area(int a,int b){
    return a*b;
}

int area(int a){
    return a*a;
}

void printarray(int *a,int n){
    for(int i=0;i<n;++i){
        cout<<a[i]<<" ";
    }
}

int substring(string s1, string s2){
    int m = s1.length();
    int n = s2.length();
    for(int i=0;i<=n-m;i++){
        int j;
        for(j=0;j<m;j++){
            if(s2[i+j]!=s1[j]){
                break;
            }
        }
        if(j == m){
            return i;
        }
    }
    return -1;
}

template<class A,class B>
auto findMin(A a,B b) -> decltype(a,b ? a:b){
    return (a<b) ? a : b;
}

int main() {
//    int a,b;
//    cin>>a>>b;
//    cout<<findMin(a,b)<<endl;

//    vector<int> v;
//    int n = 5;
//    for(int j=0;j<n;++j){
//        v.push_back(j);
//    }
//    vector<int>::iterator i;
//    for(i = v.begin();i!=v.end();++i){
//        cout<<*i<<" ";
//    }


//    string name,section;
//    cin>>name;
//    char c;
//    cin>>c;
//    size_t gotcha = name.find(c);
//    if(gotcha != string::npos){
//        cout<<"first"<<gotcha<<endl;
//    }
//    gotcha = name.find(c,gotcha+1);
//    if(gotcha != string::npos){
//        cout<<"second"<<gotcha<<endl;
//    }
//    gotcha = name.find(c,gotcha+2);
//    if(gotcha != string::npos){
//        cout<<"third"<<gotcha<<endl;
//    }

//
//    // :: Scope resolution operator use for global variable
//    int m=20;
//    for(int i=0;i<1;i++){
//        int k=m;
//        int m =30;
//        cout<<"We are in inner block "<<endl;
//        cout<<"k "<<k<<endl;
//        cout<<"m "<<m<<endl;
//        cout<<"::m "<<::m<<endl;
//    }
//    cout<<"we are in outer block "<<endl;
//    cout<<"m "<<m<<endl;
//    cout<<"::m "<<::m<<endl;
//
//
//    // Dynamic Memory allocation
//    int *p = new int;
//    *p = 35;
//    cout<<*p<<endl;
////Arrays
//    int *arr = new int[10000];
//    cout<<"Enter thr array elements : "<<endl;
//    for(int i=0;i<1;i++){
//        cin>>arr[i];
//    }
//    cout<<arr[9]<<endl;
//    delete []arr;
//
//    // Manipulators
//    int sum=10;        // Gives gap
//    cout<<"I want to print this"<<setw(5)<<sum<<endl;
//
//
//    // Reference variable (pass by address)
//    string advaith = "Me";
//    string &sunny = advaith;
//    cout<<sunny<<endl;
//
//    // inline functions
//    int a,b,c;
//    cin>>a>>b;
//    c = sum(a,b);
//    cout<<c;

//    // Function overloading
//    int a,b,l;
//    cin>>a>>b>>l;
//    cout<<area(a,b)<<endl;
//    cout<<area(l);

    return 0;
}