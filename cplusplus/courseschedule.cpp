#include<bits/stdc++.h>
using namespace std;

bool bfs(int n, vector<vector<int>> adj_matrix)
{
    queue<int> q;
    vector<int> in_degree(n, 0);
    int visited = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(adj_matrix[i][j] == 1)
            {
                in_degree[j]++;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(in_degree[i] == 0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        visited++;

        for(int i = 0; i < n; i++)
        {
            if(adj_matrix[current][i] == 1)
            {
                in_degree[i]--;
                if(in_degree[i] == 0)
                {
                    q.push(i);
                }
            }
        }
    }
    if(visited == n)
        return true;
    return false;
}

int main()
{
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    vector<vector<int>> adj_matrix (numCourses, vector<int> (numCourses, 0));

    for(int i = 0; i < prerequisites.size(); i++)
    {
        adj_matrix[prerequisites[i][0]][prerequisites[i][1]] = 1;
    }

    for(int i = 0; i < numCourses; i++)
    {
        for(int j = 0; j < numCourses; j++)
        {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }

    if(bfs(numCourses, adj_matrix))
    {
        cout << "True";
        return true;
    }
    cout << "False";
    return false;
}