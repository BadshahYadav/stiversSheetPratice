#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    // if elements on the left half are still left
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    // if elements on the right half are still left
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    // Copying the temp array into original array..

    for (int i = low; i < high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);      // for left side
    mergeSort(arr, mid + 1, high); // for right side
    merge(arr, low, mid, high);    // for merging sorted array
}

int main()
{
    int arr[] = {19, 22, 11, 44, 21, 52, 6, 10, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Before merge sort : " << "\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    mergeSort(arr, 0, size - 1);
    cout << "After merge sort : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}