#include <bits/stdc++.h>
using namespace std;

class AuthenticationManager {
public:
    
    int timeToLive;
    unordered_map<string, int> token_map;

    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }

    void generate(string tokenId, int currentTime) {
        token_map[tokenId] = currentTime + timeToLive;
    }

    void renew(string tokenId, int currentTime) {
        if(token_map.count(tokenId) && token_map[tokenId] > currentTime)
        {
            token_map[tokenId] = currentTime + timeToLive;
        }
    }

    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (auto it = token_map.begin(); it != token_map.end();) 
        {
            if (it->second <= currentTime) 
            {
                it = token_map.erase(it);
            } 
            else 
            {
                count++;
                it++;
            }
        }
        return count;
    }
};


int main()
{
    AuthenticationManager authManager(5);
    authManager.generate("token1", 1);
    authManager.renew("token1", 2);
    cout << authManager.countUnexpiredTokens(3) << endl; // Output:
    authManager.generate("token2", 4);
    cout << authManager.countUnexpiredTokens(6) << endl; // Output:
    authManager.renew("token2", 7);
    cout << authManager.countUnexpiredTokens(8) << endl; // Output:
    authManager.generate("token3", 9);
    cout << authManager.countUnexpiredTokens(10) << endl; // Output:
    authManager.renew("token3", 11);
    return 0;
}