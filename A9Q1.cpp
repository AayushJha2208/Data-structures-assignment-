#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

// ---------- BFS ----------
void BFS(int start, vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal: ";
    while(!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";

        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

// ---------- DFS ----------
void DFSUtil(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) DFSUtil(neighbor, adj, visited);
    }
}

void DFS(int start, vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    cout << "DFS Traversal: ";
    DFSUtil(start, adj, visited);
    cout << endl;
}

// ---------- DSU for Kruskal ----------
struct Edge { int u, v, w; };

int findParent(int v, vector<int>& parent) {
    if(parent[v] == v) return v;
    return parent[v] = findParent(parent[v], parent);
}

void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);

    if(rank[u] < rank[v]) parent[u] = v;
    else if(rank[u] > rank[v]) parent[v] = u;
    else { parent[v] = u; rank[u]++; }
}

// ---------- Kruskal ----------
void Kruskal(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){ return a.w < b.w; });

    vector<int> parent(n), rank(n, 0);
    for(int i = 0; i < n; i++) parent[i] = i;

    int cost = 0;
    cout << "Kruskal MST edges:\n";
    for(auto &e : edges) {
        if(findParent(e.u, parent) != findParent(e.v, parent)) {
            cost += e.w;
            cout << e.u << " - " << e.v << " : " << e.w << endl;
            unionSet(e.u, e.v, parent, rank);
        }
    }
    cout << "Total Cost: " << cost << endl << endl;
}

// ---------- Prim ----------
void Prim(vector<vector<pair<int,int>>>& graph, int n) {
    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, false);
    key[0] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});

    int cost = 0;
    cout << "Prim MST edges:\n";

    while(!pq.empty()) {
        pair<int,int> top = pq.top(); pq.pop();
        int u = top.second;

        if(mst[u]) continue;
        mst[u] = true;
        cost += key[u];

        for(auto &p : graph[u]) {
            int v = p.first, w = p.second;
            if(!mst[v] && w < key[v]) {
                key[v] = w;
                pq.push(make_pair(key[v], v));
            }
        }
    }
    cout << "Total Cost: " << cost << "\n\n";
}

// ---------- Dijkstra ----------
void Dijkstra(vector<vector<pair<int,int>>>& graph, int n, int start) {
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});

    while(!pq.empty()) {
        pair<int,int> top = pq.top(); pq.pop();
        int u = top.second;

        for(auto &p : graph[u]) {
            int v = p.first, w = p.second;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << "Dijkstra Distances:\n";
    for(int i = 0; i < n; i++)
        cout << "Node " << i << " -> " << dist[i] << endl;
    cout << endl;
}

// ---------- MAIN DRIVER ----------
int main() {
    int n = 6;   
    int e = 8;   

    vector<vector<int>> adj(n);
    vector<vector<pair<int,int>>> graph(n);
    vector<Edge> edges;

    cout << "\nEdges (u v weight):\n";

    while(edges.size() < e) {
        int u = rand() % n;
        int v = rand() % n;
        int w = (rand() % 20) + 1;  

        if(u == v) continue; 
        bool exists = false;
        for(auto &ed : edges) {
            if((ed.u == u && ed.v == v) || (ed.u == v && ed.v == u)) {
                exists = true; break;
            }
        }
        if(exists) continue;

        adj[u].push_back(v);
        adj[v].push_back(u);

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});

        edges.push_back({u, v, w});
        cout << u << " " << v << " " << w << endl;
    }

    cout << endl;

    BFS(0, adj, n);
    DFS(0, adj, n);
    Kruskal(edges, n);
    Prim(graph, n);
    Dijkstra(graph, n, 0);

    return 0;
}
