Jaime the Tailor's new customer wants to add n distinct clusters of buttons to her dress, where each cluster is filled with a distinct number of buttons of a certain color.
The customer also has specific ideas about how much she wants to pay for each cluster in that for some cluster i, she wants to pay at least ai dollars. In addition, she wants each cluster to contain a distinct number of buttons. And, finally, she wants to minimize her total cost.
Jaime stocks an infinite number of buttons in an infinite number of colors at his shop, and each button costs p dollars. Given n, p, and the amount of money that the customer wants to pay for each respective cluster, help Jaime by finding and printing a long integer denoting the minimum number of buttons he can use to satisfy her request.
Input Format
The first line contains two space-separated integers denoting the respective values of n and p.
The second line contains n space-separated integers where each integer i denotes the value of ai (i.e., the minimum amount of money she wants to spend on cluster i).
Constraints

1 <= n,p,a <= 105

Output Format

Print a single long integer denoting the minimum number of buttons required for Jaime to satisfy his customer's request.

Sample Input 0

3 2
4 6 6
Sample Output 0

9
Sample Input 1

2 3
4 5
Sample Output 1

5
  
  
  // Program for the above progarm in CPP
  #include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
int main()
{
    ll n,p; cin>>n >>p;
    ll a[n];
    for(ll i=0;i<n;i++) cin>>a[i];
    //sorting the array
    sort(a,a+n);
    ll ans=0;
    ll prev=-1; // to store the previous used buttons
    for(ll i=0;i<n;i++) {
        int buttons = a[i]/p;
        if(buttons * p == a[i]) // this is to check if cost is completely divisble by p or not  
        {
            if(buttons <= prev) // if equal to previous than answer will be the previous + 1 and our previous storing variable will be updated
            {
                ans = ans + prev+1;
                prev++;
            }
            else
            {
                ans = ans + buttons;
                prev = buttons;
            }
        }
        else
        {
            buttons++;
            if(buttons <= prev)
            {
                ans = ans + prev+1;
                prev++;
            }
            else
            {
                ans = ans + buttons;
                prev = buttons;
            }
        }
    }
    cout<<ans<<endl;
}


// Leave a ⭐ if u like the code 
