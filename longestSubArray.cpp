#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getLongestSubarray(vector<int> &v, int k)
{
    int len = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        long long s = 0;
        for (int j = i; j < n; j++)
        {
            s += v[j];
            if (k == s)
            {
                len = max(len, j - i + 1);
            }
        }
    }
    return len;
}

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";

    return 0;
}