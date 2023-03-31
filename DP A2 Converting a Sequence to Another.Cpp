You are given two integer sequences A and B,

Your task is to make the sequence A exactly identical to B.

You can perform three operations on the sequence A :

Insert an integer at some position
Remove an integer from some position
Modify an integer i.e. give a new value to an integer at some position
Every operation takes 1 unit of cost.

Your task is, given A and B, find the minimum cost to convert A to B.

Input

First line contains the number of elements in A
Second line contains the elements of the array A
Third line contains the number of elements in B
Fourth line contains the elements of the array B

Output

Print the minimum cost of converting A to B

Notes

Size of the sequences will not exceed 1000
All elements of the sequences fit in a 32-bit integer.

Sample Input 0

6
1 2 3 4 5 6
8
1 5 7 2 8 4 5 6
Sample Output 0

3


// Code in C++
  #include <iostream>
#include <vector>

using namespace std;

int min_cost_to_convert(const vector<int>& A, const vector<int>& B) {
    int n = A.size();
    int m = B.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
               dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
            }
        }
    }

    return dp[n][m];
}

int main() {
    int n, m;
    cin >> n;

    vector<int> A(n);
    for (auto& a : A) {
        cin >> a;
    }

    cin >> m;

    vector<int> B(m);
    for (auto& b : B) {
        cin >> b;
    }

    cout << min_cost_to_convert(A, B) << endl;

    return 0;
}
  
