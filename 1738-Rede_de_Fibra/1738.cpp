#include <iostream>
#include <list>

using namespace std;

struct Grafo{
    list<int> aresta;
    string empresas;
};


char Floyd_Warshal(Grafo g[], int n){
    
}

main() {
    int n, a, b;
    string provedores;
    
    while ((cin >> n) && n != 0) {
        Grafo vertices[n + 1];
        for(int i = 1; (i <= n) && ((a != 0) && (b != 0)); i++){
            cin >> a >> b >> provedores;
            vertices[a].aresta.push_front(b);
        }
        
    }
}