#include <iostream>
#include <fstream>

using namespace std;

void first();
void second();
const int MAX_N = 100;

int main() {
	first();
	second();
}

void first() {
	int n, m;
    int in_degree[MAX_N] = { 0 };
    int out_degree[MAX_N] = { 0 };
    bool homogeneous = true; // чи є граф однорідним
    int degree_of_homogeneity = 0; // степінь однорідності

    ifstream fin("input.txt");
    fin >> n >> m;

    // заповнити матрицю суміжності нулями
    int adj_matrix[MAX_N][MAX_N] = { 0 };

    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        adj_matrix[u - 1][v - 1] = 1;
        out_degree[u - 1]++;
        in_degree[v - 1]++;
    }

    cout << "In-degree and out-degree of each vertex:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i + 1 << ": in-degree = " << in_degree[i] << ", out-degree = " << out_degree[i] << endl;
    }

    // перевірити однорідність графу
    int d = out_degree[0]; // степінь першої вершини
    for (int i = 1; i < n; i++) {
        if (out_degree[i] != d) {
            homogeneous = false;
            break;
        }
    }
    if (homogeneous) {
        degree_of_homogeneity = d;
        cout << "Graph is homogeneous with degree " << degree_of_homogeneity << endl;
    }
    else {
        cout << "Graph is not homogeneous" << endl;
    }

    fin.close();

}


void second() {
    int n, m;
    ifstream fin("input.txt"); 
    fin >> n >> m;

    int* is_leaf = new int[n + 1];
    int* is_isolated = new int[n + 1];

    for (int i = 0; i <= n; i++) {
        is_leaf[i] = 0;
        is_isolated[i] = 0;
    }

    int u, v;
    for (int i = 0; i < m; i++) {
        fin >> u >> v;
        if (u == v) {
            is_isolated[u] = true;
        }
        else { 
            if (u < v) {
                is_leaf[u] = false;
            }
            else {
                is_leaf[v] = true;
            }
        }
    }
    fin.close();
    cout << "Leaf nodes:" << endl;
    for (int i = 1; i <= n; i++) {
        if (is_leaf[i]) {
            cout << i << endl;
        }
    }
    cout << "Isolated nodes:" << endl;
    for (int i = 1; i <= n; i++) {
        if (is_isolated[i]) {
            cout << i << endl;
        }
    }
    delete[] is_leaf;
    delete[] is_isolated;

}