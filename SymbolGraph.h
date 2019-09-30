/* 
 * File:   SymbolGraph.h
 * Author: Olivier Cuisenaire
 * Modified: Valentin Minder (2018), Raphaël Racine (2018), Antoine Rochat (2019)
 *
 * Created on 26. septembre 2014, 15:08
 */

#ifndef SYMBOLGRAPH_H
#define	SYMBOLGRAPH_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <list>
#include <map>

#include "Util.h"

template<typename GraphType>
class SymbolGraph
{
    typedef GraphType Graph; 
private:
    Graph* g;
    std::map<std::string, int> symbolToNodeID;
    // A IMPLEMENTER: vos structures privées ici.
    
public:
    
    ~SymbolGraph()
    {
        delete g; 
    }            
    
    //creation du SymbolGraph a partir du fichier movies.txt
    SymbolGraph(const std::string& filename) {
        // Indication: nous autorisons une double lecture du fichier.

        // exemple de lecture du fichier, ligne par ligne puis element par element (separe par des /)
        std::string line;

        std::ifstream s(filename);
        // compter le nombre de symboles dans le fichier
        // necessaire afin d'instancier le Graph
        size_t nodeID = 0;
        while (std::getline(s, line))
        {
            auto names = split(line,'/');
            for( auto name : names ) {
                if(!contains(name)){
                    symbolToNodeID[name] = nodeID++;
                }
            }
        }

        // revenir au début du fichier
        s.clear();
        s.seekg(0, std::ios::beg);

        // Instanciation et population du Graph
        g = new Graph(nodeID);

        while (std::getline(s, line)) {
            auto names = split(line,'/');
            bool isFirstSymbolOfLine = true;
            size_t lineStartNode = 0;
            for (auto name : names) {
                int nodeId = symbolToNodeID[name];
                if(isFirstSymbolOfLine){
                    // le premier symbole de la ligne est movie
                    lineStartNode = nodeId;
                    isFirstSymbolOfLine = false;
                }else{
                     // attacher les acteurs aux movies
                     g->addEdge(lineStartNode, nodeId);
                }
            }
        }

        s.close();
    }
    
    //verifie la presence d'un symbole
    bool contains(const std::string& name) const {
        return !(symbolToNodeID.find(name) == symbolToNodeID.end());
    }
    
    //index du sommet correspondant au symbole
    int index(const std::string& name) const {
        for (auto it = symbolToNodeID.begin(); it != symbolToNodeID.end(); ++it ){
            if (it->first == name){
                return it->second;
            }
        }
    }
    
    //symbole correspondant au sommet
    std::string symbol(int idx) const {
        for (auto it = symbolToNodeID.begin(); it != symbolToNodeID.end(); ++it ){
            if (it->second == idx){
                return it->first;
            }
        }
    }

    //symboles adjacents a un symbole
    std::vector<std::string> adjacent(const std::string& name) const {
        std::list<int> nodes = g->adjacent(symbolToNodeID.at(name));
        std::vector<std::string> symbolesAdjacents;
        for (auto it = nodes.begin(); it != nodes.end(); ++it ){
            symbolesAdjacents.push_back(symbol(*it));
        }
        return  symbolesAdjacents;
    }
    
    const Graph& G() const {
        return *g; 
    }
    
};


#endif	/* SYMBOLGRAPH_H */
