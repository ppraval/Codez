#include <iostream>
#include <vector>

using namespace std;

struct Player {
    int id;
    int distance;
    int points;
};

void playerMove(vector<Player>& players, int playerID, int movedDistance, int thresholdDistance, int additionalPoints) {
    for (auto& player : players) {
        if (player.id == playerID) {
            player.distance += movedDistance;
            if (player.distance > thresholdDistance) {
                player.points += additionalPoints;
            }
            break;
        }
    }
}

int playerScore(const vector<Player>& players, int firstPlayerID, int secondPlayerID) {
    int totalScore = 0;
    for (const auto& player : players) {
        if (player.id >= firstPlayerID && player.id <= secondPlayerID) {
            totalScore += player.points;
        }
    }
    return totalScore;
}

int main() {
    int N, thresholdDistance, additionalPoints;
    cin >> N >> thresholdDistance >> additionalPoints;

    vector<Player> players(N);
    for (int i = 0; i < N; ++i) {
        cin >> players[i].id >> players[i].distance >> players[i].points;
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int queryType;
        cin >> queryType;
        if (queryType == 1) {
            int playerID, movedDistance;
            cin >> playerID >> movedDistance;
            playerMove(players, playerID, movedDistance, thresholdDistance, additionalPoints);
        } else if (queryType == 2) {
            int firstPlayerID, secondPlayerID;
            cin >> firstPlayerID >> secondPlayerID;
            cout << playerScore(players, firstPlayerID, secondPlayerID) << endl;
        }
    }

    return 0;
}
