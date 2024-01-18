#include<bits/stdc++.h>
using namespace std;

class MinStack
{
    private:
        stack<int> s;
        stack<int> min_stack;
    public:
        MinStack()
        {   
            stack<int>* s = new stack<int>;
            stack<int>* min_stack = new stack<int>;
        }
        void push(int val)
        {
            s.push(val);
            if(min_stack.empty() || val <= min_stack.top())
            {
                min_stack.push(val);
            }
        }
        void pop()
        {
            if(s.empty())
                return;
            if(min_stack.top() == s.top())
            {
                min_stack.pop();
            }
            s.pop();
        }
        int top()
        {
            if(s.empty())
                return -1;
           return s.top();
        }
        int getMin()
        {
            if(min_stack.empty())
                return -1;
            return min_stack.top();
        }
};


int main()
{
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->top() << endl;
    cout << obj->getMin() << endl;
    return 0;
}