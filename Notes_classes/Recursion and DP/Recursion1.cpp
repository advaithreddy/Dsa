#include<Bits/stdc++.h>
using namespace std;

int fibonnaci(int n){
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }
    return fibonnaci(n-1) + fibonnaci(n-2);
}

int power2(int n){
    if(n==0){
        return 1;
    }
    return 2 * power2(n-1);
}

int factorial(int n){
    if(n==0){
        return 1;
    }
    return n * factorial(n-1);
}

// Say Digits
void sayDIgits(int n,string arr[]){
    // Base case
    if(n==0){
        return;
    }

    int digit = n%10;
    n = n/10;

    cout<<arr[digit] <<" ";
    sayDIgits(n,arr);
}

bool isSorted(int *arr, int n){
    if(n==0 || n==1){
        return true;
    }

    if(arr[0] > arr[1]){
        return false;
    }else{
        bool ans = isSorted(arr+1, n-1);
        return ans;
    }
}

int sumrecur(int *arr, int n){
    if(n==0){
        return 0;
    }
    int sum = arr[0];
    sum += sumrecur(arr+1,n-1);
    return sum;
}

int linearsearch(int *arr, int n, int k,int i){
    if(i>n){
        return -1;
    }
    if(arr[i] == k){
        return i;
    }
    return linearsearch(arr,n,k,i+1);
}

int binarysearch(int *arr, int n, int k, int i){
    if(i>n){
        return -1;
    }
    int mid =  i+(n-i)/2;
    if(arr[mid] == k){
        return mid;
    }else if(arr[i] > k){
        return (arr,mid-1,k,i);
    }else{
        return (arr,n,k,mid+1);
    }
}

string reverse(string s,int i, int j){
    if(i>=j){
        return s;
    }
    swap(s[i], s[j]);
    return reverse(s,i+1,j-1);
}

char tolower(char ch){
    if((ch>'a'&&ch<'z')||(ch>'0'&&ch<'9')){
        return ch;
    }else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool isPalindrome(string s, int l, int r){
    if(l>r){
        return true;
    }
    if(tolower(s[l]) != tolower(s[r])){
        return false;
    }
    return isPalindrome(s,l+1,r-1);
}

int power(int a, int b){
    // Base case
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    int ans = power(a,b/2);
    if(b%2==0){
        return ans * ans;
    }else{
        return a * ans * ans;
    }
}

void bubblesort(int *arr, int n){
    if(n==0 || n==1){
        return;
    }
    for(int i=0;i<n-1;i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    return bubblesort(arr,n-1);
}

// Merge Sort
// Merge Function
void merge(vector<int>& arr, int left, int mid, int right){
    int n1= mid - left +1;
    int n2 = right - mid;

    std::vector<int> leftarray(n1);
    std::vector<int> rightarray(n2);

    // Input the elements
    for(int i=0;i<n1;++i){
        leftarray[i] = arr[left+i];
    }
    for(int i=0;i<n2;++i){
        rightarray[i] = arr[mid+1+i];
    }

    // Now merge the arrays
    int i=0;
    int j=0;
    int k= left;
    while(i<n1 && j<n2){
        if(leftarray[i]<= rightarray[j]){
            arr[k] = leftarray[i];
            ++i;
        }else{
            arr[k] = rightarray[j];
            ++j;
        }
        ++k;
    }
    // Remaining of n1
    while(i<n1){
        arr[k] = leftarray[i];
        ++i;
        ++k;
    }
    while(j<n2){
        arr[k] = rightarray[j];
        ++j;
        ++k;
    }
}

void mergesort(vector<int>& arr, int left, int right){
    if(left < right){
        int mid = left + (right - left)/2;

        mergesort(arr, left, mid);
        mergesort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
}

// Quick Sort
// Partition
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = low - 1;  // Index of the smaller element

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);  // Swap elements
        }
    }

    std::swap(arr[i + 1], arr[high]);  // Place the pivot in the correct position
    return i + 1;  // Return the index of the pivot
}


void quicksort(vector<int>& arr, int low, int high){
    if(low < high){
        int pi = partition(arr,low,high);

        quicksort(arr, low, pi -1);
        quicksort(arr, pi+1, high);
    }
}

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}


// Subsets
void solve(vector<int> nums, vector<vector<int>>& ans, vector<int> output, int i){
    if(i>=nums.size()){
        ans.push_back(output);
        return;
    }
    // Exclude
    solve(nums, ans, output, i+1);
    // Include
    int v =nums[i];
    output.push_back(v);
    solve(nums, ans, output, i+1);
}

vector<vector<int>> subset(vector<int>& nums){
    vector<vector<int>> ans;
    vector<int> output;
    int i=0;
    solve(nums, ans, output, i);
    return ans;
}

//Rat Maze Problem
class RatMaze{
private:
    bool isSafe(vector<vector<int>>& m, int n,vector<vector<int>>& visited, int x, int y){
        if((x>=0 && x<n)&&(y>=0 && y<n) /* to be in path */ && visited[x][y] == 0 && m[x][y] == 1){
            return true;
        }else{
            return false;
        }
    }

    void solve(vector<vector<int>>& m, int n,vector<vector<int>> visited,vector<string>& ans, int x, int y,string path){
        // Base case
        if(x==n-1 && y == n-1){
            ans.push_back(path);
            return;
        }

        // Recursive Approacj
        visited[x][y] = 1;

        // We have 4 moves
        /* [1, 0, 0, 0]
         * [1, 1, 0, 0]
         * [1, 1, 0, 0]
         * [0, 1, 1, 1] */       // [[DDRDRR] , [DRDDRR]]

        // Down
        int newx = x+1;
        int newy = y;
        if(isSafe(m, n, visited, newx, newy)){
            path.push_back('D');
            solve(m, n, visited, ans, newx, newy, path);
            path.pop_back();  // Bcktrack
        }
        // Left
        newx = x;
        newy = y-1;
        if(isSafe(m, n, visited, newx, newy)){
            path.push_back('L');
            solve(m, n, visited, ans, newx, newy, path);
            path.pop_back();  // Bcktrack
        }
        // Up
        newx = x-1;
        newy = y;
        if(isSafe(m, n, visited, newx, newy)){
            path.push_back('U');
            solve(m, n, visited, ans, newx, newy, path);
            path.pop_back();  // Bcktrack
        }
        // Right
        newx = x;
        newy = y+1;
        if(isSafe(m, n, visited, newx, newy)){
            path.push_back('R');
            solve(m, n, visited, ans, newx, newy, path);
            path.pop_back();  // Bcktrack
        }
        // Back track to check for new paths you will get it if you dry run
        visited[x][y] = 0;
    }
public:
    vector<string> findpath(vector<vector<int>>& m, int n){
        vector<string> ans;
        // No Value case
        if(m[0][0] == 0){
            return ans;
        }
        string path = "";
        vector<vector<int>> visited = m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]= 0;
            }
        }
        int srcx = 0, srcy = 0;
        solve(m,n, visited, ans,srcx, srcy, path);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
int main() {
    char choice;
    do{
        int n;
        cout<<"Enter the size of n: "<<"\n";
        cin>>n;
        vector<vector<int>> m(n, vector<int>(n,0));
        cout<<"Enter the maze: \n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>m[i][j];
            }
        }
        RatMaze solution;
        vector<string> result = solution.findpath(m, n);
        sort(result.begin(),result.end());
        if(result.size() == 0){
            cout<<"No path found\n";
        }else{
            for(int i=0;i<result.size();i++){
                cout<<result[i]<<" ";
            }
            cout<<endl;
        }
        cout<<"Do you want to play again (y/n): ";
        cin>>choice;
    }while(choice == 'y'|| choice == 'Y');

    cout<<"Thank You For Playing !!!";

    return 0;
}
