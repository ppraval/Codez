stack<int> stk;

let s be input string

for(int i going till s.length)
    if(s[i] == '(')
        we push i into the stack
    else
        if(stack is empty or the top of the stack corresponds to a '(')
            we pop it out

we get max_len to be 0

while(if stack not empty)
    current index = stack.top
    max_len = max(n - index - 1)
    n = current index

returning (the max between current max_len and n)

( ( ) )

))))))))

Pushing '(' index = 0;

stack is empty

index = 0

and our max len = n - 1

n > n - 1

return n
i.e the lenght of the string 


---------------------------------------
If we use stack the time complexties are 
time  = O(n)
space = O(n)

if we optimise using two pointers 
we get out new
time = O(n)
space = O(1)
------------------------------
