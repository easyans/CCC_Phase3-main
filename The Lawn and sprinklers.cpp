n sprinklers are installed in a horizontal strip of grass l meters long and w meters wide.
Each sprinkler is installed at the horizontal center line of the strip.
For each sprinkler we are given its position as the distance from the left end of the center line and its radius of operation.
What is the minimum number of sprinklers to turn on in order to water the entire strip of grass?
image

Input Format

Input consists of a number of cases. The first line for each case contains integer numbers n, l and w with n ≤ 10000. The next n lines contain two integers giving the position of a sprinkler and its radius of operation. (The picture above illustrates the first case from the sample input.)

Constraints

n <= 10000
-10^18 <= all positions <= 10^18

Output Format

For each test case output the minimum number of sprinklers needed to water the entire strip of grass. If it is impossible to water the entire strip output ‘-1’.

Sample Input 0

8 20 2
5 3
4 1
1 2
7 2
10 2
13 3
16 2
19 4
3 10 1
3 5
9 3
6 1
3 10 1
5 3
1 1
9 1
Sample Output 0

6
2
-1
  
  
  
  
  
  // Program in cpp :
  
  #include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include <queue>
#include <vector>
#include<bitset>
#include<map>
#include<deque>
using namespace std;
typedef long long LL;
const int maxn = 1e4+5;
const int mod = 77200211+233;
typedef pair<int,int> pii;
#define X first
#define Y second
#define pb push_back
//#define mp make_pair
#define ms(a,b) memset(a,b,sizeof(a))
const int inf = 0x3f3f3f3f;
#define lson l,m,2*rt
#define rson m+1,r,2*rt+1
typedef long long ll;
#define N 1000010
struct node {
    double a,b;
}square[10005];

int cmp(node x,node y){
    return x.b>y.b;
}

int main(){
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif // LOCAL
    int n;
    double l,w;
    double r,p;
    while(~scanf("%d%lf%lf",&n,&l,&w)){
        int tot=0;
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&p,&r);
            if(r<=w/2) continue;
            square[tot].a=p-sqrt(r*r-w*w/4);
            square[tot++].b=p+sqrt(r*r-w*w/4);
        }

        sort(square,square+tot,cmp);

        double st=0;
        int ans=0;

        while(st<l){
            int i;
            for(i=0;i<tot;i++){
                if(square[i].a<=st && square[i].b>st){
                    st=square[i].b;
                    ans++;
                    break;
                }
            }
            if(i==tot) break;
        }
        if(st<l){
            puts("-1");
        }else{
            printf("%d\n",ans);
        }
    }
    return 0;
}
