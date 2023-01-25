# ApacheAge-Task
#### Envirmoent and IDE
- C Programming language v.(C18)
- Any C compiler (EX: CodeBlocks)
- gcc (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0

#### Usage
- Copy the source code from [here](https://github.com/Mohamed-ElGemeie/ApacheAge-Task/tree/main/src)
- Install the above GCC version and C, and use any IDE you prefer.

#### Explanation
- Q1- The fibonacci function should be implemented using Dynamic Programming.
    - A function pointer array was initilized "funcArrayPointer" to hold all our functions addresses
    - Enum "index" is used to refrence each address according to the passed enum value.
    - A function pointer is returned which is used with parameters later in "calc"
    - Recursive Fibonacci function is called with the last number, it is used to return the value in the sequence that holds that index. 
    - The function uses Memorization.
    <br><br><br>
- Q2- Implement the following piecewise recurrence relation in the 3 different ways.
    - For loop ```O(n)``` - Linear
    - recursion = ```O(2^n)``` - Expo
    - recursion using memorization ```O(n)```<br><br>
This concludes that the for loop is the best approach between these three as it uses less memory that the 3rd method.<br><br>
Note: There are methods with O(log(n)) time that are better than the above.