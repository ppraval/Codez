#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void floydWarshall(vector<vector<int>>& dist, int N) {
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> transmissionCost(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> transmissionCost[i][j];
            if (i != j && transmissionCost[i][j] == 0) {
                transmissionCost[i][j] = INT_MAX;
            }
        }
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int firstDevice, secondDevice, cost;
        cin >> firstDevice >> secondDevice >> cost;
        transmissionCost[firstDevice - 1][secondDevice - 1] = min(transmissionCost[firstDevice - 1][secondDevice - 1], cost);
        transmissionCost[secondDevice - 1][firstDevice - 1] = min(transmissionCost[secondDevice - 1][firstDevice - 1], cost);
    }

    floydWarshall(transmissionCost, N);

    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (transmissionCost[i][j] != INT_MAX) {
                sum += transmissionCost[i][j];
            }
        }
    }

    cout << sum << endl;

    return 0;
}
