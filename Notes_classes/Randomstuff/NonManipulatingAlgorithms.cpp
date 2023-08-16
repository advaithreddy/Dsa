// A C++ program to demonstrate working of sort(),
// reverse()
#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Initializing vector with array values
    int arr[] = {10, 23, 5, 23 ,42 , 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vect(arr, arr+n);

    cout << "Vector is: ";
    for (int i=0; i<n; i++)
        cout << vect[i] << " ";

    cout<<"\ncount of 23 : "<<" ";
    cout<<count(vect.begin(),vect.end(),23);


    find(vect.begin(),vect.end(),5)!= vect.end()?
    cout<<"Found:":
    cout<<"not found:";

    cout<<"Value at";
    cout<<binary_search(vect.begin(),vect.end(),15);


    // Sorting the Vector in Ascending order
    sort(vect.begin(), vect.end());


    cout << "\nVector after sorting is: ";
    for (int i=0; i<n; i++)
        cout << vect[i] << " ";


    // Sorting the Vector in Descending order
    sort(vect.begin(),vect.end(), greater<int>());

    cout << "\nVector after sorting in Descending order is: ";
    for (int i=0; i<n; i++)
        cout << vect[i] << " ";


    // Reversing the Vector (descending to ascending , ascending to descending)
    reverse(vect.begin(), vect.end());

    cout << "\nVector after reversing is: ";
    for (int i=0; i<n; i++)
        cout << vect[i] << " ";

    cout << "\nMaximum element of vector is: ";
    cout << *max_element(vect.begin(), vect.end());

    cout << "\nMinimum element of vector is: ";
    cout << *min_element(vect.begin(), vect.end());

    // Starting the summation from 0
    cout << "\nThe summation of vector elements is: ";
    cout << accumulate(vect.begin(), vect.end(), 0);

    return 0;
}
