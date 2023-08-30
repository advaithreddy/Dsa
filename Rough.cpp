//#include<bits/stdc++.h>
//using namespace std;
//
//
//void printDups(string str){
//    unordered_map<char, int> mp;
//    for(int i=0;i<str.length();++i){
//        mp[str[i]]++;
//    }
//
//    for(auto it : mp){
//        if(it.second>1){
//            cout<<it.first<<" "<<it.second<<endl;
//        }
//    }
//}
//
//int permute(int arr1[],int arr2[], int n,int k){
//    sort(arr1,arr1+n);
//    sort(arr2,arr2+n,greater<int>());
//
//    for(int i=0;i<n;i++){
//        if(arr1[i]+arr2[i]<k)
//            return false;
//    }
//    return true;
//}
//
//int ceil(int arr[],int n,int k){
//    int s=0;
//    int e = n-1;
//
//    sort(arr,arr+n);
//
//    int mid = s+(e-s)/2;
//
//    while(s<=e){
//        mid = s+(e-s)/2;
//
//        if(arr[mid]==k){
//            return arr[mid+1];
//        }else if(arr[mid] < k){
//            s++;
//        }else{
//            e--;
//        }
//    }
//    return arr[mid];
//}
//
//int floor(int arr[],int n,int k){
//    int s=0;
//    int e = n-1;
//
//    sort(arr,arr+n);
//
//    int mid = s+(e-s)/2;
//
//    while(s<=e){
//        mid = s+(e-s)/2;
//
//        if(arr[mid]==k){
//            return arr[mid-1];
//        }else if(arr[mid] < k){
//            s++;
//        }else{
//            e--;
//        }
//    }
//    return arr[mid-1];
//}
//
//int arrsearch(int arr[],int n,int k,int x){
//    int i=0;
//    while(i<n){
//        if(arr[i]==x){
//            return i;
//            break;
//        }
//
//        i = i + max(1, abs(arr[i]-x)/k);
//    }
//    return i;
//}
//
//void pairdiff(int arr[],int n,int k){
//    int i=0;
//    int j=1;
//
//    while(i<n && j<n){
//        if(i!=j && (arr[i] - arr[j] == k || arr[j] - arr[i] == k)){
//            cout<<arr[i]<<" "<<arr[j];
//        }else if(arr[j]-arr[i] < n){
//            j++;
//        }else{
//            i++;
//        }
//    }
//}
//
//bool findPair(int arr[], int size, int n)
//{
//    // Initialize positions of two elements
//    int i = 0;
//    int j = 1;
//
//
//    sort(arr,arr+size);
//    // Search for a pair
//    while (i < size && j < size)
//    {
//        if (i != j && (arr[j] - arr[i] == n || arr[i] - arr[j] == n) )
//        {
//            cout << "Pair Found: (" << arr[i] <<
//                 ", " << arr[j] << ")";
//            return true;
//        }
//        else if (arr[j]-arr[i] < n)
//            j++;
//        else
//            i++;
//    }
//
//    cout << "No such pair";
//    return false;
//}
//
//
//void printarr(int arr[],int n,int s=0){
//    for(int i=s;i<n;++i){
//        cout<<arr[i]<<" ";
//    }
//}
//
//int largest(int arr[],int n,int k){
//
//    sort(arr,arr+n,greater<int>());
//
//    return arr[k-1];
//}
//
//int smallest(int arr[],int n,int k){
//    sort(arr,arr+n);
//
//    return arr[k-1];
//}
//
//void sort012(int arr[],int n){
//    sort(arr,arr+n);
//}
//
//
//int countWords(string input) {
//    // Write your code here
//    int count =0;
//    int n=input.length();
//    for(int i=0;i<=n;++i){
//        if(input[i]==' '){
//            count++;
//            continue;
//        }
//    }
//    return count;
//}
//
//
//string removealloccChar(string str,char c){
//    int n = str.length();
//
//    for(int i=0;i<n;i++){
//        if(str[i]==c){
//            str.erase(str.begin()+i);
//            i--;
//        }
//    }
//    return str;
//}
//
//int power(int n){
//    if(n==0){
//        return 1;
//    }
//
//    int small = power(n-1);
//
//    int big = 2 * small;
//
//    return big;
//}
//
//int sumofarrRecur(int *arr, int n){
//
//    // base case
//    if(n==0){
//        return 0;
//    }
//
//    int ans = arr[0] + sumofarrRecur(arr+1,n-1);
//    return ans;
//}
//
//bool comp(string a, string b){
//    if(a.size()!= b.size()) return a.size() < b.size();
//    return a<b;
//}
//
//
//// Can you place flowers
//bool flowersbed(int a[], int n,int k){
//    if(n==0){
//        return true;
//    }
//    for(int i=0;i<n;++i){
//        if(a[i] == 0 && ( i==0 || a[i-1] == 0) && ( i== n-1 || a[i+1] == 0)){
//            a[i] = 1;
//            k--;
//
//            if(k==0){
//                return true;
//            }
//        }
//    }
//    return false;
//}
//
//int minmerge(int arr[], int n){
//    int s =0;
//    int e = n-1;
//    int c= 0;
//    while(s<=e){
//        if(arr[s]==arr[e]){s++;e--;}
//        else if(arr[s]>arr[e]){e--; arr[e] += arr[e+1]; c++;}
//        else{ s++; arr[s] += arr[s+1]; c++;}
//    }
//    return c;
//}
//
//// Mo's Algorithm to calculate the sum pair for query
//struct Query{
//    int L,R;
//};
//
//void solve(int arr[], Query q[],int n, int m){
//    for(int i=0;i<m;i++) {
//        int L = q[i].L, R = q[i].R;
//        int sum = 0;
//        for (int j = L; j <= R; j++) { sum += arr[j]; }
//        cout << " Sum of arr[] of elements in the range [" << L << "," << R << "] is " << sum << "\n";
//    }
//}
//
//
//void productofarrayself(int * arr, int n){
//    int * left = new int[sizeof(int*) * n];
//    int * right= new int[sizeof(int*) * n];
//    int * prd = new int[sizeof (int*) * n];
//    left[0] = 1;
//    right[n-1] = 1;
//    for(int i=1;i<n;i++){
//        left[i] = arr[i-1] * left[i-1];
//    }
//    for(int i=n-2;i>=0;i--){
//        right[i] = arr[i+1] * right[i+1];
//    }
//
//    for(int i=0;i<n;i++){
//        prd[i] = left[i]* right[i];
//    }
//
//    for(int i=0;i<n;i++){
//        cout<<prd[i]<<" ";
//    }
//    return;
//}
//
//int makealleleequal(int arr[], int n){
//    int y;
//    if(n%2==1){
//        y = arr[n/2];
//    }else{
//        y = (arr[n/2] + arr[(n-2)/2])/2;
//    }
//    int s =0;
//    for(int i=0;i<n;i++){
//        s += abs(arr[i]-y);
//    }
//    return s;
//}
//
//
//int Problem1(string str) {
//    int n = str.length();
//    int lps[n];
//    lps[0] = 0;
//    int len = 0;
//    int i = 1;
//
//    while (i < n) {
//        if (str[i] == str[len]) {
//            len++;
//            lps[i] = len;
//            i++;
//        }
//        else {
//            if (len != 0) {
//                len = lps[len - 1];
//            }
//            else {
//                lps[i] = 0;
//                i++;
//            }
//        }
//    }
//
//    return lps[n - 1];
//}
//
//int main() {
//
//    string s;
//    cin>>s;
//    int res = Problem1(s);
//    cout<<res<<"\n";
//
////    int arr[] = {1, 1, 2, 1, 3, 4, 5, 2, 8};
////    Query q[] = {{0, 4}, {1, 3}, {2, 4}};
////    int n= sizeof(arr)/sizeof(arr[0]);
////    int m = sizeof(q)/sizeof(q[0]);
////    solve(arr,q,n,m);
//
//
////    int n,cur;
////    int pos[n],t[n];
////    cin>>n>>cur;
////    for(int i=0;i<n;++i){
////        cin>>pos[i];
////    }
////    for(int i=0;i<n;++i){
////        cin>>t[i];
////    }
////    cout<<solve(pos, t, n, cur);
//
////
////    int n,a[10000],k;
////    cin>>n;
////    for(int i=0;i<n;i++){
////        cin>>a[i];
////    }
////    cin>>k;
////    if(flowersbed(a,n,k)==true){
////        cout<< "True";
////    }else{
////        cout<< "False";
////    }
//
//
////
////    int n;
////    cout<<"Enter the length of the path"<<endl;
////    cin>>n;
////    string path;
////    cout<<"Enter the path"<<endl;
////    cin>>path;
////    int height = 0;
////    int cnt =0 ;
////    for(int i=0;i<n;i++){
////        if(path[i] == 'U'){
////            height++;
////        }else{
////            if(height == 0){
////                cnt++;
////            }
////            height--;
////        }
////    }
////    if(height < 0){
////        cnt--;
////    }
////    cout<<"No. of vallyes have to travel are :"<<cnt<<endl;
////
////    typedef vector<int> vi;
////    vi v = {1,5,4,3,2,9};
////    sort(v.rbegin(),v.rend());
////    for(int i=0;i<6;i++){
////        cout<<v[i]<<" ";
////    }
////
////
////    int a[10]={1,2,3,4,5,6,7,8,9,10};
////    int n = sizeof(a)/sizeof(a[0]);
////    sort(a,a+n,greater<int>());
////    cout<<a[0]<<"\n";
////
////    typedef vector<pair<int,int>> vpi;
////    vpi vp;
////    vp.push_back({1,5});
////    vp.push_back({2,7});
////    vp.push_back({1,9});
////    sort(vp.begin(),vp.end());
////    string l,m;
////    getline(cin, l);
////    cin>>m;
////    if(comp){
////        cout<<"Working"<<"\n";
////    }else{
////        printf("Not working");
////    }
////    int arr[5] = {1,2,3,4,5};
////    int n = sizeof(arr)/sizeof(arr[0]);
////    int x = 4;
////    auto k = lower_bound(arr,arr+n,x)-arr;
////    if(k<n && arr[k]== x){
////        cout<<"Found at "<<x<<"\n";
////    }
//    return 0;
//}
//
//
//
//

#include <bits/stdc++.h>

using namespace std;

vector<int> accumulateDiagonals(const vector<vector<int>>& matrix) {
    int N = matrix.size();
    vector<int> diagonalSums;

    for (int k = N - 1; k >= 1 - N; k--) {
        int sum = 0;

        for (int i = 0; i < N; i++) {
            int j = i + k;
            if (j >= 0 && j < N) {
                sum += matrix[i][j];
            }
        }

        diagonalSums.push_back(sum);
    }

    return diagonalSums;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<vector<int>> matrix(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        vector<int> diagonalSums = accumulateDiagonals(matrix);

        for (int i = 0; i < diagonalSums.size(); i++) {
            cout << diagonalSums[i] << " ";
        }
        cout << endl;
    }

    return 0;
}



