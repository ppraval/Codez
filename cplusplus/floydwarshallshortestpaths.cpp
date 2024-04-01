#include<bits/stdc++.h>
using namespace std;

void floydWarshall(int vertices, vector<vector<int>> adj_matrix)
{
    vector<vector<int>> new_adj_matrix(vertices, vector<int> (vertices));
    for(int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++)
        {
            new_adj_matrix[i][j] = adj_matrix[i][j];
        }
    }

    for(int k = 0; k < vertices; k++)
    {
        for(int i = 0; i < vertices; i++)
        {
            for(int j = 0; j < vertices; j++)
            {
                if(new_adj_matrix[i][k] != -1 && new_adj_matrix[k][j] != -1 && (new_adj_matrix[i][j] == -1 || new_adj_matrix[i][k] + new_adj_matrix[k][j] < new_adj_matrix[i][j]))
                {
                    new_adj_matrix[i][j] = new_adj_matrix[i][k] + new_adj_matrix[k][j];
                }
            }
        }
    }

    for(int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++)
        {
            cout << new_adj_matrix[i][j] << " ";
        }
        cout << endl;
    }

}

int main()
{
    int vertices = 4;
    vector<vector<int>> adj_matrix(vertices, vector<int> (vertices));
    adj_matrix = {
        {0, 5,-1, 7},
        {5, 0, 3, -1},
        {-1, 3, 0, 2},
        {7, -1, 2, 0}
    };
    floydWarshall(vertices, adj_matrix);
    return 0;
}