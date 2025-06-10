#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Broute Force Approach ..........
// void rotateToRight(int arr[], int n, int k)
// {
//     k = k % n;
//     vector<int> temp;
//     for (int i = 0; i < k; i++)
//     {
//         temp.push_back(arr[i]);
//     }
//     // Shifting
//     for (int i = k; i < n; i++)
//     {
//         arr[i - k] = arr[i];
//     }
//     for (int i = n-k; i < n; i++)
//     {
//         arr[i] = temp[i - (n - k)];
//     }
// }


// Optimal Approach ........
// Intution is like  we have [1, 2, 3, 4, 5, 6, 7] and rotate from 2nd postion ..
// Step 1 : Reverse till kth position array will looks like [2,1,3,4,5,6,7]
// Step 2 : Reverse from (k+1)th position till last and array will looks like [2,1,7,6,5,4,3]
// Step 3 : Reverse from strating to ending and final array will looks like this [3,4,5,6,7,1,2]

void rotateToRight(int arr[], int n, int k){
    reverse(arr,arr+k);
    reverse(arr+k,arr+n);
    reverse(arr,arr+n);
}

int main()
{
    int n = 7;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int k = 2;
    rotateToRight(arr, n, k);
    cout << "After Rotating the elements to right " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}