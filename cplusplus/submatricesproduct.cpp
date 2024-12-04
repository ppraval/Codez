#include <iostream>
#include <vector>
using namespace std;

int countSubmatricesWithProductLessThanK(const vector<vector<int>> &matrix, int maxK) {
    int n = matrix.size();
    int m = matrix[0].size();
    int count = 0;

    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= m; ++y) {
            long long product = 1;
            bool valid = true;
            for (int i = 0; i < x && valid; ++i) {
                for (int j = 0; j < y; ++j) {
                    product *= matrix[i][j];
                    if (product > maxK) {
                        valid = false;
                        break;
                    }
                }
            }
            if (valid && product <= maxK) {
                ++count;
            }
        }
    }
    
    return count;
}

int main() {
    int n, m, maxK;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
    cin >> maxK;

    int result = countSubmatricesWithProductLessThanK(matrix, maxK);
    cout << result << endl;
    return 0;
}
