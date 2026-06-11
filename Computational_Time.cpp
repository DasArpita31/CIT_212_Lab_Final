#include <iostream>
#include <ctime>
using namespace std;

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int n;

    cout << "Enter array size: ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    int key;

    cout << "Enter search element: ";
    cin >> key;

    clock_t start, end;

    start = clock();

    for (int i = 0; i < 10000; i++)
    {
        linearSearch(arr, n, key);
    }

    end = clock();

    double linearTime = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();

    for (int i = 0; i < 10000; i++)
    {
        binarySearch(arr, n, key);
    }

    end = clock();

    double binaryTime = (double)(end - start) / CLOCKS_PER_SEC;

    cout << "Linear Search Time: " << linearTime << " seconds" << endl;
    cout << "Binary Search Time: " << binaryTime << " seconds" << endl;

    return 0;
}