#include<stdio.h>
typedef int (*ptr)(int); // used as return type for function pointer
typedef int (*point)(int ,int); // used as return type for function that calculates

typedef struct
{
/*
    point: Function pointer
    val: Value each node holds
*/
point funct;
int val;
}Node;


typedef enum  { // enum used to index each function
    ADD = 0,
    SUB= 1,
    MUL = 2

} index;

// + - *
int addr(int x, int y)
{
    return x+y;
}
int subr(int x, int y)
{
    return y-x;
}
int mulr(int x, int y)
{
    return x*y;
}

// DP recursive function to find the fibonacci sequence according to index
// using memoization
int Fibo(int n, int* memo)
{
    if(memo[n] != 0)
    {
        return memo[n];
    }
    if(n < 2)
    {
        return n;
    }
    memo[n-1] = Fibo(n-1,memo);
    memo[n-2] = Fibo(n-2,memo);

    return memo[n-1] + memo[n-2];

}


// Function called to display and call
// the passed pointer to function
void calc(Node* n, int x, int y)
{
    // uses Node's function pointer to find the function
    // and stores the value inside the Node's val attribute
    n->val = n->funct(x,y);
    printf("%d\n",n->val);
}

// function that return a function pointer
ptr func(int op)
{
    // according to the passed enum value
    // it will return a function pointer
    int(*funcArrayPointer[3])(int, int) = {&addr, &subr,&mulr};

    return *funcArrayPointer[op];
}



int main()
{
Node add;
Node mul;
Node sub;
Node fibo;

add.funct = func(ADD);
mul.funct = func(MUL);
sub.funct = func(SUB);
fibo.funct = func(SUB);


calc(&add,10,6);
calc(&mul,5,4);
calc(&sub,mul.val,add.val);
calc(&fibo,sub.val,NULL);


// array used for dp memoization
int memo[1000] = { 0 };
printf("\nFibo :%d",Fibo(fibo.val-1,memo));

return 0;
}
