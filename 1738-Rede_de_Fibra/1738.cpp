//Equipe: Piazada, Alunos: Vinicius Alves Beló, Willian Penteado e Felipe Zorzo

#include <iostream>


#define inf 999999999


using namespace std;


int d[201][201][26];
int n;

void Floyd_Warshall() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int l = 0; l < 26; l++) {
                    d[i][j][l] = min(d[i][j][l], d[i][k][l] + d[k][j][l]);
                }
            }
        }
    }
}

int main()
{
    int u, v, flag;

    string provedores;

    while (1) {
        cin >> n;
        if (n == 0) {
            return 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 26; k++)
                    d[i][j][k] = inf;
            }
        }

        while (1) {
            cin >> u >> v;
            if (u == 0 && v == 0) {
                break;
            }
            cin >> provedores;
            --u;
            --v;
            for (int i = 0; i < provedores.size(); i++){
                d[u][v][provedores[i] - 'a'] = 1;
            }
        }

        Floyd_Warshall();

        while (1) {
            cin >> u >> v;
            if (u == 0 && v == 0) {
                break;
            }
            --u;
            --v;
            flag = 0;
            for (int i = 0; i < 26; i++) {
                if (d[u][v][i] != inf) {
                    cout << (char)(i + 'a');
                    flag = 1;
                }
            }
            if (flag == 0) {
                cout << '-';
            }
            cout << endl;
        }
        cout << endl;
    }
}