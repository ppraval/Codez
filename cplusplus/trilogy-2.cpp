#include<bits/stdc++.h>
using namespace std;

struct Request {
    long long timestamp;
    int holder_id;
    int amount;
    string type;
};

vector<int> solution(vector<int> balances, vector<string> requests) {
    unordered_map<int, long long> cashback;
    vector<int> result = balances;
    queue<Request> q;
    for(int i = 0; i < requests.size(); i++) 
    {
        stringstream ss(requests[i]);
        string type;
        long long timestamp;
        int holder_id, amount;
        ss >> type >> timestamp >> holder_id >> amount;

        while(!q.empty() && q.front().timestamp + 86400 <= timestamp) 
        {
            Request req = q.front();
            q.pop();
            if(req.type == "withdraw") 
            {
                result[req.holder_id - 1] += cashback[req.timestamp];
            }
        }

        if(type == "deposit") 
        {
            if(holder_id < 1 || holder_id > result.size()) 
            {
                return {-i - 1};
            }
            result[holder_id - 1] += amount;
        } 
        else if(type == "withdraw") 
        {
            if(holder_id < 1 || holder_id > result.size() || result[holder_id - 1] < amount) 
            {
                return {-i - 1};
            }
            result[holder_id - 1] -= amount;
            cashback[timestamp] = (amount * 2) / 100;
            q.push({timestamp, holder_id, amount, type});
        }
    }
    return result;
}

int main() {
    vector<int> balances = {1000, 1500};
    vector<string> requests = {"withdraw 1613327630 2 480", "withdraw 1613327644 2 800", "withdraw 1614105244 1 100", "deposit 1614108844 2 200", "withdraw 1614108845 2 150"};
    vector<int> res = solution(balances, requests);
    for (int num : res) 
    {   
        cout << num << " ";
    }
    return 0;
}
