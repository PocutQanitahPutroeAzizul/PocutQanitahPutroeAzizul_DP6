#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int src, dest;
    int distance, cost;
};

void bellmanFord(int V, int E, int start, const vector<Edge>& edges) {
    vector<int> distance(V, INT_MAX);
    vector<int> cost(V, INT_MAX);
    vector<int> parent(V, -1);
    
    distance[start] = 0;
    cost[start] = 0;
    
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int dist = edges[j].distance;
            int c = edges[j].cost;
            
            if (distance[u] != INT_MAX && distance[u] + dist < distance[v]) {
                distance[v] = distance[u] + dist;
                cost[v] = cost[u] + c;
                parent[v] = u;
            }
        }
    }
    
    cout << "Jarak terpendek dari kos " << start << " ke semua kos:\n";
    for (int i = 0; i < V; i++) {
        if (distance[i] == INT_MAX) {
            cout << "Kos " << i << ": Tidak dapat dijangkau\n";
        } else {
            cout << "Kos " << i << ": " << distance[i] << " meter\n";
        }
    }
    
    cout << "\nBiaya termurah dari kos " << start << " ke semua kos:\n";
    for (int i = 0; i < V; i++) {
        if (cost[i] == INT_MAX) {
            cout << "Kos " << i << ": Tidak dapat dijangkau\n";
        } else {
            cout << "Kos " << i << ": Rp " << cost[i] << "\n";
        }
    }
    
    cout << "\nRute menuju kos terakhir (kos " << V - 1 << "):\n";
    if (distance[V - 1] == INT_MAX) {
        cout << "Tidak ada rute yang tersedia ke kos " << V - 1 << "\n";
    } else {
        vector<int> path;
        int current = V - 1;
        while (current != -1) {
            path.insert(path.begin(), current);
            current = parent[current];
        }
        
        cout << "Rute: ";
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << "\n Total jarak: " << distance[V - 1] << " meter\n";
        cout << "Total biaya: Rp " << cost[V - 1] << "\n";
    }
}

int main() {
    int V, E, start_kos;
    cout << "Masukkan jumlah kos (V), jumlah jalan (E), dan kos awal (misal : 3 4 0): ";
    cin >> V >> E >> start_kos;
    
    vector<Edge> edges(E);
    cout << "Masukkan " << E << "kos_asal, kos_tujuan, jarak dan biaya (misal: 0 1 100 5000) :\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].distance >> edges[i].cost;
    }
    
    bellmanFord(V, E, start_kos, edges);
    
    return 0;
}