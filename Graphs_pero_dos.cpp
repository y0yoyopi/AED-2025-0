vector<vector<int>> floydWarshall(vector<vector<int>>& graph, int n) {
    const int INF = INT_MAX / 2; // Para evitar overflow en sumas
    vector<vector<int>> dist(n, vector<int>(n, INF));

    // Inicializar la matriz de distancias con los valores del grafo
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) dist[i][j] = 0;  // Distancia a sí mismo es 0
            else if (graph[i][j] != -1) dist[i][j] = graph[i][j]; // Si hay conexión, usamos su peso
        }
    }

    // Algoritmo de Floyd-Warshall
    for (int via = 0; via < n; via++) { // Nodo intermedio
        for (int i = 0; i < n; i++) { // Nodo de origen
            for (int j = 0; j < n; j++) { // Nodo de destino
                if (dist[i][via] < INF && dist[via][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
    }

    return dist; // Retorna la matriz de distancias mínimas
}
