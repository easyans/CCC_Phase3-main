Mickey came across an interesting series as follows : FN = FN-1 xor FN-2 + FN-3
He is a better at managing the clubhouse than progamming, so he asked for your help.
He has given you four values, F0, F1, F2 and N. Your task is to write a program to tell him the value of FN.
Input
Four integers separated by spaces denoting F0, F1, F2 and N.
Output
Print one integer equal to the value of FN
Notes
1 ≤ N ≤ 15

Sample Input 0

1 2 3 5
Sample Output 0

6
  
  
  
  //PROGRAM IN C++ or C++14
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int a,b,c;
int series(int d)
{
    if(d==0)return a;
    else if(d==1)return b;
    else if(d==2)return c;
    return series(d-1)^(series(d-2)+series(d-3));
}
int main() {
    int d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int x=series(d);
    printf("%d",x);
    return 0;
}
