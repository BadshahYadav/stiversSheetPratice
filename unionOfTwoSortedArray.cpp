#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// Brute Force Approach ....

// vector<int> FindUnion(int arr1[],int arr2[],int n, int m){
//     set<int> s;
//     for(int i =0; i<n;i++){
//         s.insert(arr1[i]);
//     }
//     for(int i =0; i<m;i++){
//         s.insert(arr2[i]);
//     }
//     vector<int> temp;
//     for(auto x : s){
//         temp.push_back(x);
//     }
//     return temp;
// }

// Optimal Solution....

vector<int> FindUnion(int arr1[], int arr2[], int n, int m)
{
    int i = 0, j = 0;
    vector<int> UA;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            if (UA.empty() || UA.back() != arr1[i])
                UA.push_back(arr1[i]);
            i++;
        }
        else if (arr2[j] < arr1[i])
        {
            if (UA.empty() || UA.back() != arr2[j])
                UA.push_back(arr2[j]);
            j++;
        }
        else
        {
            // arr1[i] == arr2[j]
            if (UA.empty() || UA.back() != arr1[i])
                UA.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    while (i < n)
    {
        if (UA.empty() || UA.back() != arr1[i])
            UA.push_back(arr1[i]);
        i++;
    }

    while (j < m)
    {
        if (UA.empty() || UA.back() != arr2[j])
            UA.push_back(arr2[j]);
        j++;
    }

    return UA;
}   


int main()
{
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    vector<int> Union = FindUnion(arr1, arr2, n, m);
    cout << "Union of arr1 and arr2 is " << endl;
    for (auto &val : Union)
        cout << val << " ";
    return 0;
}