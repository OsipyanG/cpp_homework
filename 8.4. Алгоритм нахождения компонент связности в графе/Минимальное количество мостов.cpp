#include <algorithm>
#include <iostream>
#include <vector>

struct Edge {
    int u, v;
};

struct DisjointSet {
    std::vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (rank[u] < rank[v]) {
                std::swap(u, v);
            }
            parent[v] = u;
            if (rank[u] == rank[v]) {
                rank[u]++;
            }
        }
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> edges[i].u >> edges[i].v;
        edges[i].u--;
        edges[i].v--;
    }

    std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) { return a.u < b.u; });

    DisjointSet dsu(n);

    std::vector<Edge> result;

    for (const Edge& e : edges) {
        int u = e.u;
        int v = e.v;
        if (dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v);
            result.push_back(e);
        }
    }

    int k = n - 1 - result.size();

    std::cout << k << "\n";
    for (int i = 0; i < k; ++i) {
        std::cout << (i + 1) << " " << (i + 2) << "\n";
    }

    return 0;
}