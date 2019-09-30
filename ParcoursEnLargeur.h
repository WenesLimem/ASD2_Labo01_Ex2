/*
 * File:   ParcoursEnLargeur.h
 * Author: Olivier Cuisenaire
 *
 * Created on 4. septembre 2014, 14:38
 * Updated on 29 septembre 2017 by Michael Sandoz
 */

#ifndef PARCOURSENLARGEUR_H
#define	PARCOURSENLARGEUR_H

#include <vector>
#include <queue>
#include <stack>

template<typename GraphType>
class BFS {
public:
    
    BFS(const GraphType& G) : g(G) {
    }
    
    template <typename Func> void visit(int v, Func f) {
        parent.assign(g.V(), -1);
        this->bfs(v, f);
    }
    
    int parentOf(int v) const {
        return this->parent[v];
    }
    
private:
    const GraphType& g;
    std::vector<int> parent;
    
    template<typename Func> void bfs(int v, Func f) {
        std::queue<int> queueBfs;
        parent[v] = v;
        queueBfs.push(v);
        
        while (!queueBfs.empty()) {
            v = queueBfs.front();
            queueBfs.pop();
            
            for (int w : g.adjacent(v))
                if (parent[w] == -1) {
                    parent[w] = v;
                    queueBfs.push(w);
                }
            
            f(v);
        }
    }
};

#endif	/* PARCOURSENLARGEUR_H */

