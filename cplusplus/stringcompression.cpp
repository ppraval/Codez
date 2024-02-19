#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<char> chars = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
    char current; char previous;
    string output;
    int count = 0;
    int n = chars.size();
    
    if(n == 1)
    {
        cout << chars[0];
        cout << "\n" << 1;
        return 0;
    }

    for(int i = 0; i < n; i++)
    {
        current = chars[i];
        cout << "i value " << i << "\n";
        if(i == 0)
        {
            previous = chars[i];
            cout << "previous: " << previous << " Current: " << current << "\n";
        }
        else
        {
            previous = chars[i - 1];
            cout << "previous: " << previous << " Current: " << current << "\n";
        }
        if(current == previous)
        {
            count++;
            cout << "The count is: " << count << " and value of i is: " << i << "\n";
        }
        if ((current != previous) || (i == (n - 1)))
        {   
            cout << "count is " << count << "\n";
            if(count != 1)
            {
                output.push_back(previous);
                output += to_string(count);
            }
            else
            {
                output.push_back(previous);
            }
            
            if(i == n - 1 && current != previous)
            {
                cout << "Can we get here?\n";
                output.push_back(current);
            }
            count = 1;
            previous = current;
            cout << "previous after change is : " << previous << "\n";
        }
    }
    for(int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << "\n" << output.size(); 
    return 0;
}