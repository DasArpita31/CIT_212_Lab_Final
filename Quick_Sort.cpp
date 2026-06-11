#include <iostream>
using namespace std;

// function to swap two numbers
void swapNumber(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// partition function (pivot placement)
int partition(int a[], int low, int high)
{
    int pivot = a[high];   // last element as pivot
    int i = low - 1;       // smaller element index

    for (int j = low; j < high; j++)
    {
        // if current element is smaller than pivot
        if (a[j] < pivot)
        {
            i++;
            swapNumber(a[i], a[j]);
        }
    }

    // place pivot in correct position
    swapNumber(a[i + 1], a[high]);

    return (i + 1);
}

// quick sort function
void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        // partition index
        int pi = partition(a, low, high);

        // left side sort
        quickSort(a, low, pi - 1);

        // right side sort
        quickSort(a, pi + 1, high);
    }
}

// print array function
void printArray(int a[], int n)
{
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // calling quick sort
    quickSort(a, 0, n - 1);

    // print result
    printArray(a, n);

    return 0;
}