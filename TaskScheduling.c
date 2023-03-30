You are given N tasks.
The ith task has deadline Ti and generates a profit of Pi. Every task takes one second to complete. Time starts at t = 0.
Your task is to find an optimal way to do the tasks so as to generate the maximum amount of total profit.
You have to print the maximum possible profit that you were able to make.
  
INPUT
First line contains the number of test cases T.
For every test case :
First line contains the integer N.
Next line contains N integers denoting the array T.
Last line contains N integers denoting the array P.

OUTPUT
Print one number, the maximum profit that you can make for every test case on a new line

NOTES
1 ≤ N, Ti, Pi ≤ 105

Sample Input 0

2
4
4 1 1 1
20 10 40 30
5
2 1 2 1 3
100 19 27 25 15
Sample Output 0

60
142
  
  
  
  //Program for above problem in 🐍Python languagae :
  #Question is same as Task Scheduling 1
class Job:
    def __init__(self, taskId, deadline, profit):
        self.taskId = taskId
        self.deadline = deadline
        self.profit = profit
def scheduleJobs(jobs, T):
    profit = 0
    slot = [-1] * T
    jobs.sort(key=lambda x: x.profit, reverse=True)
    for job in jobs:
        for j in reversed(range(job.deadline)):
            if j < T and slot[j] == -1:
                slot[j] = job.taskId
                profit += job.profit
                break
    print( profit)
if __name__ == '__main__':
    t=int(input())
    while t!=0:
        t-=1
        n=int(input())
        jobs = []
        deadline=[int(i) for i in input().split()]
        profit=[int(i) for i in input().split()]
        for i in range(n):
            jobs.append(Job(i+1, deadline[i], profit[i]))
        maxdead=max(deadline)
        scheduleJobs(jobs, maxdead)

  
