Given an array of integers, replace every element with the greatest element on the right side in the array. Replace last element with 0 as there no element on the right side of it.

Input Format

First line contains N , the number of Numbers. Next line contains N integers a[1]..a[n] the numbers

Constraints

1<= N <= 10^5
1<= ai <= 10^5

Output Format

Print the array required

Sample Input 0

6
6 7 4 3 5 2
Sample Output 0

7 5 5 5 2 0 
  
  
  
  // Progarm in CPP :
  #include <iostream>
#include <stdio.h>
using namespace std;

void nextGreatest(int arr[], int size)
{
    int maxFromRight = 0;
    int n = size;
    for(int i= n-1; i>=0;i--) {
    int temp = maxFromRight;
    if(arr[i]> maxFromRight){
        maxFromRight = arr[i];
    }
    arr[i] = temp;
    }
    return;
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
        cin>>arr[i];
    nextGreatest (arr, size);
    printArray (arr, size);
    return (0);
}
