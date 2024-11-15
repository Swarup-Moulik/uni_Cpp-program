#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = (low - 1);
  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}
void printArray(int arr[], int n)
{
  for (int i = 0; i < n; ++i) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}
int main()
{
  int arr[10], s;
  cout << "Enter the size of array :- ";
  cin >> s;
  cout << "Enter the elements in the array :-\n";
  for(int i = 0; i<s; i++)
  {
    cin >> arr[i];
  }
  cout << "Unsorted array: \n";
  printArray(arr, s);
  quickSort(arr, 0, s - 1);
  cout << "Sorted array: \n";
  printArray(arr, s);
  return 0;
}
