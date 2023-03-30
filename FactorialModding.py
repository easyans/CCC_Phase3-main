Given 3 numbers, a,b and m, find (a! / b!) % m, where a! is factorial of a, i.e a x (a-1) x (a-2) ... x 1 and a % b is the mod function. which is the remainder when a is divided by b.

Input Format

Three numbers : a, b and m.

Constraints

1 <= b <= a <= 10 ^ 9

1 <= m <= 10 ^ 9

(b - a) <= 10 ^ 5

Output Format

Print only one number, equal to (a! / b!) % m.

Sample Input

5 2 7

Sample Output

4

Explanation

5! = 120
2! = 2
120 / 2 = 60
60 % 7 = 4



#THE CODE FOR ABOVE PROGRAM IN 🐍 PYTHON :


import math
p=1
l=[int(i) for i in input().split()]
a=l[0]
b=l[1]
c=l[2]
for i in range(a,b,-1):
    p*=i
print(p%c)
