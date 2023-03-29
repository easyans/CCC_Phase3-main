Gunpreet is running up a staircase with  steps, and can hop(jump) either 1 step, 2 steps or 3 steps at a time.You have to count, how many possible ways Gunpreet can run up to the stairs.
Input Format
Input contains integer N that is number of steps
Constraints
Output Format
Output for each integer N the no of possible ways w.

Sample Input 0

3
Sample Output 0

4
  
  // PROGARM  FOR THE ABOVE QUESTION IN C Programming :
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d",&n);
    
    int grid[n+1],i;
    grid[0] = 0; grid[1] = 1; grid[2] = 2; grid[3] = 4;
    for(i=4;i<=n;i++)
        grid[i] = grid[i-1] + grid[i-2] + grid[i-3];
    
    printf("%d",grid[n]);
    
    return 0;
}
