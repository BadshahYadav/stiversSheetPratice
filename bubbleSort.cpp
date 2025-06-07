#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        int flag = 0;
        for (int j = 0; j < i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }

    cout << "After Bubble Sorting : " << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {23, 12, 21, 9, 11, 6, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Befor Bubble Sort : " << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    bubbleSort(arr, n);
    return 0;
}