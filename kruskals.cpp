//kruskals

#include <iostream>

using namespace std;

struct Edge{
  int src;
  int dst;
  int wt;
  
  Edge(int a, int b, int c){
      src = a;
      dst = b;
      wt = c;
  }
  
  Edge(){
      src = 0;dst = 0; wt = 0;
  }
};

struct subset{
    int parent;
    int rank;
};


struct Graph{
    int V, E;
    Edge *adj;
    
    Graph(int a, int b){
        V = a;
        E = b;
        adj = new Edge[E];
    }
};

int cmp(const void* a, const void* b){
    Edge *x = (Edge*)a, *y = (Edge*) b;
    return x->wt > y->wt;
}

int find(subset s[], int i){
    if(s[i].parent==i){
        return i;
    }
    s[i].parent = find(s, s[i].parent);
}

void _union(subset s[], int a, int b){
    int x = find(s, a);
    int y = find(s, b);
    
    if(s[x].rank < s[y].rank){
        s[x].parent = y;
    }
    else if(s[x].rank > s[y].rank){
        s[y].parent = x;
    }
    else{
        s[x].parent = y;
        s[y].rank++;
    }
}



void getKruskal(Graph* g){
    qsort(g->adj, g->E, sizeof(g->adj[0]), cmp);
    Edge soln[(g->V)-1];
    subset *subsets = new subset[g->V];
    
    for(int i = 0; i<g->V; i++){
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    int parent[g->V];
    
    int i = 0;
    int e = 0;
    
    while(e<g->V-1 && i<g->E){
        
        Edge next_edge = g->adj[i++]; 
        int a = find(subsets, next_edge.src);
        int b = find(subsets, next_edge.dst);
        if(a!=b){
            soln[e++] = next_edge;
            _union(subsets, a, b);
        }

    }    
    
    
    int c = 0;
    for(int ii = 0; ii<g->V-1; ii++){
        cout<<soln[ii].src<<"\t->\t"<<soln[ii].dst<<endl;
        c+=soln[ii].wt;
    }
    
    cout<<"weight : "<<c;
    
    return;
    
}

int main()
{
   Graph* g = new Graph(6, 7);
   
   g->adj[0].src = 0;
   g->adj[0].dst = 1;
   g->adj[0].wt = 10;
   
   g->adj[1].src = 0;
   g->adj[1].dst = 3;
   g->adj[1].wt = 5;
  
   g->adj[2].src = 0;
   g->adj[2].dst = 2;
   g->adj[2].wt = 6;
   
   g->adj[3].src = 2;
   g->adj[3].dst = 3;
   g->adj[3].wt = 4;
   
   
   g->adj[4].src = 1;
   g->adj[4].dst = 3;
   g->adj[4].wt = 15;
   
   g->adj[5].src = 5;
   g->adj[5].dst = 3;
   g->adj[5].wt = 14;
   
   
   g->adj[6].src = 1;
   g->adj[6].dst = 4;
   g->adj[6].wt = 1;

    getKruskal(g);
   return 0;
}