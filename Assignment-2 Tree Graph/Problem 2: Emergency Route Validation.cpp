#include <vector>
using namespace std;

class Graph {
private:
    int n;
    vector<vector<int>> adj;

public:
    Graph(int n) {
        this->n = n;
        adj.resize(n + 1);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);   // undirected graph
    }

    int efficientlyReachable(int D) {
        vector<int> distance(n + 1, -1);
        queue<int> q;

        // City 1 is the capital
        distance[1] = 0;
        q.push(1);

        int count = 0;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            // If shortest distance is <= D
            if (distance[current] <= D) {
                count++;
            }

            // Visit neighbors
            for (int next : adj[current]) {
                if (distance[next] == -1) {
                    distance[next] = distance[current] + 1;

                    // We don't need to explore beyond D roads
                    if (distance[next] <= D) {
                        q.push(next);
                    }
                }
            }
        }

        return count;
    }
};
