#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Graph{
    int v;
    list<int> *adj;
    
    Graph(int j){
        v = j;
        adj = new list<int>[v];
    }
};


bool isCycleUtil(Graph* G, int src, vector<bool> visited){
    visited[src] = true;
    
    list<int>::iterator i = G->adj[src].begin();
    
    for(; i!=G->adj[src].end(); i++){
        if(!visited[*i] && isCycleUtil(G, *i, visited)){
            cout<<src<<"\t:\t"<<*i<<endl;
            return true;
        }
        if(visited[*i]) {
            cout<<src<<"\t:\t"<<*i<<endl;
            return true;
        }
    }
    
    return false;
}


bool isCycle(Graph* G){
    int v = G->v;
    vector<bool> visited(v, false); 
    if(v==0) return false;
    
    for(int i = 0; i<v; i++){
        if(isCycleUtil(G, i, visited)) return true;
    }
    return false;
}

int main()
{
   Graph *G = new Graph(5);
   G->adj[0].push_back(1);
   G->adj[2].push_back(1);G->adj[2].push_back(3);
   G->adj[3].push_back(4);
   G->adj[4].push_back(0);G->adj[4].push_back(2);
   
   cout<<isCycle(G);
   
   
   return 0;
}