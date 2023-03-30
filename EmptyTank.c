There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
Print the minimum starting gas station’s index if you can travel around the circuit once, otherwise print -1.
You can only travel in one direction. i to i+1, i+2, ... n-1, 0, 1, 2.. Completing the circuit means starting at i and ending up at i again.

Input Format

First line contains the number of gas stations N.
Second line contains N integers, the ith of them denoting gas[i].
Third line contains N integers, the ith of them denoting cost[i].

Constraints

1 <= N <= 105

Output Format

Print the minimum starting gas station’s index if you can travel around the circuit once, otherwise print -1.

Sample Input 0

2
1 2
2 1
Sample Output 0

1
  
  
  //Program for the above probelm in 🐍 Python language : 
  
n = int(input())
gas = list(map(int, input().split()))
cost = list(map(int, input().split()))
def can_complete_circuit(gas, cost):
    n = len(gas)
    start, curr_gas, total_gas = 0, 0, 0
    
    for i in range(n):
        curr_gas += gas[i] - cost[i]
        total_gas += gas[i] - cost[i]
        
        if curr_gas < 0:
            start = i + 1
            curr_gas = 0
    
    if total_gas < 0 or start == n:
        return -1
    else:
        return start


print(can_complete_circuit(gas, cost))
          
          
          //Give a ⭐ for more code...
