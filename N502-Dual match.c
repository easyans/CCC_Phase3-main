For any given Array A[N], its TwoSum Value with respect to a number K is denoted by the number of ordered pairs {i, j} such that A[i] + A[j] = K.
i and j must satisfy the following :
1 <= i <= N and 1 <= j <= N.
i may be equal to j at times.
You are given the Array A[N] and the number K.
Find and print the TwoSum value for the array.

Hint : You may want to use binary search algorithm for efficient implementation.
Hint2 : BinarySearch works only on sorted Arrays. So you may want to use library sort (qsort in C and sort in C++) function to sort the array first.

INPUT
The first line contains a number N(1 <= N <= 10^5), the size of array A[N].
The second line contains N space separated integers denoting the elements of the array A. (1 <= A[i] <= 10^9).
The third line contains one number K(1 <= K <= 10^9), with respect to which the TwoSum value of the array A is to be found.
OUTPUT
Output one number that is equal to the TwoSum value of the given input array A[N] with respect to K.
Sample Input 0

10
1 2 3 4 5 6 7 8 9 10
10
Sample Output 0

9
  
  
  
  
  //PROGRAM FOR THE ABOVE CODE IN 🐍Python language :
n = int(input())
a = list(map(int, input().split()))
k = int(input())

a.sort()

count = 0
for i in range(n):
    complement = k - a[i]
    left = 0
    right = n - 1
    while left <= right:
        mid = (left + right) // 2
        if a[mid] == complement:
            count += 1
            break
        elif a[mid] < complement:
            left = mid + 1
        else:
            right = mid - 1
print(count)
