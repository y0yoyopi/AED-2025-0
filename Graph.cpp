





void dfs(vector<vector<int>>& graph, int nodo, vector<int>& camino, vector<vector<int>>& soluciones, int destino) {
    // 1️⃣ Agregar nodo actual al camino
    camino.push_back(nodo);

    // 2️⃣ Caso base: Si llegamos al destino, almacenamos el camino en la solución
    if (nodo == destino) {
        soluciones.push_back(camino);
    } else {
        // 3️⃣ Recorrer los vecinos del nodo actual
        for (int vecino : graph[nodo]) {
            dfs(graph, vecino, camino, soluciones, destino);
        }
    }

    // 4️⃣ Backtracking: Eliminamos el nodo antes de regresar
    camino.pop_back();
}



//Ordenación Topo 🐁
class Grafo {
private:
    vector<vector<int>> adj;
    vector<bool> visitado;
    vector<int> orden; // Aquí guardaremos la ordenación topológica en orden inverso

    void dfs(int nodo) {
        visitado[nodo] = true;

        for (int vecino : adj[nodo]) {
            if (!visitado[vecino]) {
                dfs(vecino);
            }
        }

        // Agregar al inicio del vector (simula una pila en reversa)
        orden.insert(orden.begin(), nodo);
    }

public:
    Grafo(int n) {
        adj.resize(n);
        visitado.resize(n, false);
    }

    void agregarArista(int u, int v) {
        adj[u].push_back(v);
    }

    vector<int> ordenacionTopologica() {
        for (int i = 0; i < adj.size(); i++) {
            if (!visitado[i]) {
                dfs(i);
            }
        }
        return orden; // Ya está en orden topológico sin necesidad de invertirlo
    }
};
