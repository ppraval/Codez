    #include<bits/stdc++.h>
    using namespace std;

    int main()
    {
        int t;
        cin >> t;
        while(t--)
        {
            int n;
            cin >> n;
            vector<int> arr(n);
            for(auto &a : arr)
                cin >> a;

            sort(arr.begin(), arr.end());
            int i = 0, j = n - 1;
            int count = 0;
            while(i <= j)
            {
                if(arr[j] == 4)
                {
                    count++;
                    j--;
                }
                else if(arr[j] + arr[i] == 4)
                {
                    count++;
                    i++;
                    j--;
                }
                else
                {
                    count++;
                    j--;
                }
            }
            cout << count << endl;
        }
        return 0;
    }