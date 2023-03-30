Place the letters A,B,C,D,E,F,G,H into the eight circles in such a way that 
no letter is adjacent to a letter that is adjacent to a letter that is next
to it in the alphabet.

//Program in C language :

#include <stdio.h>
#include <string.h>

void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *str, int l, int r)
{
    if (l == r)
        printf("%s\n", str);
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap((str + l), (str + i));
            permute(str, l + 1, r);
            swap((str + l), (str + i)); // backtrack
        }
    }
}

int main()
{
    char str[] = "ABCDEFGH";
    int n = strlen(str);
    permute(str, 0, n - 1);
    return 0;
}


//Note that this code only generates all permutations of the letters A to H, and the rest of the algorithm will need to be implemented to solve the problem.



  
