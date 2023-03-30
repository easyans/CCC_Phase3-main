Given an array A = {a1, a2, a3..} of N elements, find the maximum possible sum of a

Contiguous subarray
Non-contiguous (not necessarily contiguous) subarray.
Empty subarrays/subsequences should not be considered.

Input Format

First line of the input has an integer T. T cases follow.
Each test case begins with an integer N. In the next line, N integers follow representing the elements of array A.

Constraints

1 <= T <= 10
1 <= N <= 10^5
-10^4 <= ai <= 10^4

The subarray and subsequences you consider should have at least one element

Output Format

Two, space separated, integers denoting the maximum contiguous and non-contiguous subarray. At least one integer should be selected and put into the subarrays (this may be required in cases where all elements are negative).

Sample Input 0

2
4
1 2 3 4
6
2 -1 2 3 4 -5
Sample Output 0

10 10
10 11
	
	
	
	
	// THE PROGRAM FOR THE ABOVE PROBLEM IS IN JAVA SO CHANGE COMPILER TO JAVA AND RUN THIS : 
	import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) throws IOException{
        Scanner scanner = new Scanner(System.in);
        String temp = scanner.nextLine();
        int numberOfInputs = Integer.parseInt(temp);
        int numberOfElements = 0;
        int[] elements;
        String input ;
        StringTokenizer stringTokenizer;
        if(numberOfInputs<1 || numberOfInputs>10)
            return;
        for(int i=0;i<numberOfInputs;i++){
            temp = scanner.nextLine();
            numberOfElements = Integer.parseInt(temp);
            if(numberOfElements<1 || numberOfElements>100000)
                return;
            elements = new int[numberOfElements];
            input = scanner.nextLine();
            stringTokenizer = new StringTokenizer(input);
            for(int j=0;j<numberOfElements;j++){
                elements[j] = Integer.parseInt(stringTokenizer.nextToken());
                if(elements[j]<-10000 || elements[j]>10000)
                    return;
            }
            findMaxContiguous(numberOfElements,elements);
        }
        for(String res : result )
            System.out.println(res);

        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
    static List<String> result = new ArrayList<String>();
    static void findMaxContiguous(int n,int[] elements){
        int[] table = new int[n+1];
        boolean allNegative=true;
        boolean allZeros = true;
        for(int i=0;i<n;i++){
            if(elements[i]>0){
                allNegative=false;
                allZeros = false;
                break;
            }
        }
        if(allNegative){
            Arrays.sort(elements);
            result.add(elements[elements.length-1]+" "+elements[elements.length-1]);
            return;
        }
        if(allZeros){
            result.add("0 0");
            return;
        }

        int maxSum=0,maxSumSofar=0;

        table[0] = elements[0]>0?elements[0]:0;

        for(int i=1;i<n;i++){
            table[i]=table[i-1];
            if(elements[i]>0){
                table[i] = table[i-1]+elements[i];
            }
        }

        for(int i=0;i<n;i++){
            maxSumSofar= maxSumSofar+elements[i];
            if(maxSumSofar>0){
                if(maxSum<maxSumSofar){
                    maxSum = maxSumSofar;
                }
            }
            else{
                maxSumSofar = 0;
                continue;
            }
        }
        String res = maxSum +" "+ table[n-1];
        result.add(res);
    }
}
