#include<stdio.h>

// recursion - method 1
int f1(int n)
{
    if(n <=2)
    {
        return n;
    }
    return f1(n-3) + f1(n-2);
}

// standard for loop - method 2
int f2(int n)
{
    int sum;
    int last3 = 0;
    int last2 = 1;
    int last1 = 2;
    int temp1,temp2;

    if(n <=2){

        return n;
    }
    for(int i =0;i<=n-4;i++)
    {
        temp1 = last3;
        temp2 = last2;
        last3 = last2;
        last2 = last1;
        last1 = temp1+ temp2;
    }
    return last3 + last2;

}

// recursion using memoization - method 3
int f3(int n, int* memo)
{
    if(memo[n] != 0)
    {
        return memo[n];
    }
    if(n <=2)
    {
        return n;
    }
    memo[n-3] = f3(n-3, memo);
    memo[n-2] = f3(n-2, memo);

    return memo[n-3] + memo[n-2];
}

int main()
{

    // Memoization array
    int memo[10] = { 0 };

    for(int i =0;i<10;i++)
    {
        // test all three methods
        printf("%d ",f1(i)); // recursion
        printf("%d ",f2(i)); // standard for loop
        printf("%d\n",f3(i,memo)); // DP recursion
    }
}
