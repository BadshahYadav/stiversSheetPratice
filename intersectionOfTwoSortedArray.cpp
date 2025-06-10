#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute Force Approach ...

vector<int> findIntersection(int a[], int b[], int n, int m){
    vector<int> ans;
    int visited[m] = {0};
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i]==b[j] && visited[j] == 0){
                ans.push_back(a[i]);
                visited[j] = 1;
                break;
            }
            if(a[i]<b[j])
                break;
        }
    }
    return ans;
}

// Optimal Solution ....

// vector<int> findIntersection(int a[], int b[], int n, int m){
//     int i = 0;
//     int j = 0;
//     vector<int> ans;
//     while(i<n && j<m){
//         if(a[i]<b[j]){
//             i++;
//         }else if(a[i]>b[j]){
//             j++;
//         }else{
//             ans.push_back(a[i]);
//             i++;
//             j++;
//         }
//     }
//     return ans;
// }

int main()
{
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};
    vector<int> Union = findIntersection(arr1, arr2, n, m);
    cout << "Union of arr1 and arr2 is " << endl;
    for (auto &val : Union)
        cout << val << " ";
    return 0;
}