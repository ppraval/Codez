#include<bits/stdc++.h>
using namespace std;

bool isKmirror(int k, long long num)
{
    vector<int> digits;
    while(num > 0)
    {
        digits.push_back(num % k);
        num /= k;
    }
    int left = 0, right = digits.size() - 1;
    while(left < right)
    {
        if(digits[left] != digits[right])
            return false;
        left++;
        right--;
    }
    return true;
}

// bool isKMirror(long long num, int k) 
// {
//     vector<int> digits;
//     while (num > 0) 
//     {
//         digits.push_back(num % k);
//         num /= k;
//     }
//     for (int i = 0, j = digits.size() - 1; i < j; i++, j--) 
//     {
//         if (digits[i] != digits[j]) return false;
//     }
//     return true;
// }

int main()
{
    int k = 2;
    int n = 5;
    long long sum = 0;
    int count = 0;
    int length = 1;

    while (count < n) 
    {
        for (int i = pow(10, length - 1); i < pow(10, length) && count < n; i++) 
        {
            string left = to_string(i);
            string right = left.substr(0, left.size() - 1);
            reverse(right.begin(), right.end());
            string full = left + right;
            long long num = stoll(full);
            if (isKmirror(num, k)) 
            {
                sum += num;
                count++;
            }
        }

        for (int i = pow(10, length - 1); i < pow(10, length) && count < n; i++) 
        {
            string left = to_string(i);
            string right = left;
            reverse(right.begin(), right.end());
            string full = left + right;
            long long num = stoll(full);
            if (isKmirror(num, k)) 
            {
                sum += num;
                count++;
            }
        }
        length++;
    }
    cout << sum << endl;
    return sum;
}