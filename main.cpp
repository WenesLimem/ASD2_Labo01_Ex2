/* 
 * File:   ex2.cpp
 * Author: Olivier Cuisenaire
 * Modified: Valentin Minder (2018), Raphaël Racine (2018), Antoine Rochat (2019)
 *
 * Inspiré par http://oracleofbacon.org 
 * 
 * Created on 26. septembre 2014, 16:38
 */

#include <cstdlib>

#include "SymbolGraph.h"
#include "GraphUsingAdjacencyLists.h"
#include "ParcoursEnLargeur.h"

using namespace std;

int main(int argc, char** argv) {

    string file("movies.txt");
    string source("Grandberry, Omarion");
    string sink("Bacon, Kevin");
    
    SymbolGraph<GraphUsingAdjacencyLists> SG(file);

    BFS<GraphUsingAdjacencyLists> bfs(SG.G());
    bfs.visit(SG.index(sink),[](int){});
    
    // Affiche le chemin acteur->film->acteur->...->film->acteur
    int v = SG.index(source);
    while(v != bfs.parentOf(v))
    {
        cout << SG.symbol(v) << endl;
        v = bfs.parentOf(v);
    }
    cout << SG.symbol(v) << endl;
    
    cout << endl;

    // Affiche les films dans lesquels Omarion Grandberry a joué
    std::vector<std::string> adjacents = SG.adjacent("Grandberry, Omarion");
    for (auto adj : adjacents) {
        cout << adj << endl;
    }

    cout << endl;
    
    return EXIT_SUCCESS;
    
}

