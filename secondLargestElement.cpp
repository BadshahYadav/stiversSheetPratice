#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int secondLargestElement(vector<int> &arr){
    int n = arr.size();
    if(n<2){
        return -1;
    }
    int largest = arr[0];
    int secondLargest = arr[0];
    for(int i =1;i<n;i++){
        if(arr[i]>largest){
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > secondLargest && arr[i] != largest){
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}
int main()
{
vector<int> arr1 = {2,5,1,3,0};
    vector<int> arr2 = {8,10,5,7,9};
   
    cout<<"The Largest element in the array is: "<<secondLargestElement(arr1)<<endl;
    cout<<"The Largest element in the array is: "<<secondLargestElement(arr2);
return 0;
}