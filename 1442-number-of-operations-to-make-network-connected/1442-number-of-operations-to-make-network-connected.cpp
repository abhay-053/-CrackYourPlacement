class Solution {
public:
    int find(int u, vector<int>& parent) {
        if (parent[u] != u) {
            parent[u] = find(parent[u], parent);
        }
        return parent[u];
    }

    void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
        int pu = find(u, parent);
        int pv = find(v, parent);

        if (pu != pv) {
            if (rank[pu] > rank[pv]) {
                parent[pv] = pu;
            } else if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;

        vector<int> parent(n);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        for (const auto& conn : connections) {
            unionSets(conn[0], conn[1], parent, rank);
        }

        int components = 0;
        for (int i = 0; i < n; ++i) {
            if (find(i, parent) == i) {
                components++;
            }
        }

        return components - 1;
    }
};
