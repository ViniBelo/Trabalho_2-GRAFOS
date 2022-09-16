#include <iostream>

using namespace std;

void Floyd_Warshal(int g[201][201][28], int n){
    int D[n+1][n+1][28];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < 28; k++){
                D[i][j][k] = g[i][j][k];
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if((g[i][k][0] != (64000 / 2) - 1) && (g[k][j][0] != (64000 / 2) - 1) && (i != j) && (k != j) && (k != i)){
                    for (int x = 1; x < 28; x++) {
                        if(g[i][k][x] == 1 && g[k][j][x] == 1){
                            D[i][j][x] = 1;
                        }
                    }
                }
                if (g[i][j][0] > g[i][k][0] + g[k][j][0]) {
                    D[i][j][0] = g[i][k][0] + g[k][j][0];
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int l = 0; l < 28; l++) {
                    g[i][j][l] = D[i][j][l];
                }
            }
        }
    }
}

void imprimir(int vertices[201][201][28], int u, int v) {
    bool temp = false;
    for (int i = 1; i < 28; i++) {
        if(vertices[u][v][i]==1){
            temp = true;
            cout << char(i + 96);
        }
    }
    if(temp == false){
        cout << "-" << endl;
    }
    cout << endl;
}

int main() {
    int n, a, b;
    string provedores;
    int vertices[201][201][28];
    
    while (cin >> n && n != 0) {
    	for (int i = 1; i < 201; i++) {
            for (int j = 1; j < 201; j++) {
                for (int k = 0; k < 28; k++) {
                    vertices[i][j][k] = (64000 / 2) - 1;
                }
            }
            vertices[i][i][0] = 0;
        }

        while(cin >> a >> b && a != 0 && b != 0) {
            cin >> provedores;
            vertices[a][b][0] = 1;
            for (int j = 0; provedores.length() > j; j++) {
                vertices[a][b][provedores[j] - 96] = 1;
            }
        }
        Floyd_Warshal(vertices, n);
        while(cin >> a >> b && a != 0 && b != 0){
            imprimir(vertices, a, b);
        }
    }
}