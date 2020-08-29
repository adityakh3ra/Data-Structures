#include <iostream>
#include <queue>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define N 10

void addedge(vector<int> *v, int a, int b){
	v[a].push_back(b);
}

struct queueEntry{
	int curr;
	vector<int> v;
};

void helper(vector<int> *graph, int src, int dst){
	vector<bool> visited(N, false);
	queue<queueEntry> q;
	
	queueEntry p;
	p.curr = src;

	
	q.push(p);
	
	while(!q.empty()){
		queueEntry c = q.front();
		q.pop();
		int currentnode = c.curr;
		
		if(currentnode==dst){
			for(int i = 0; i<c.v.size(); i++){
				cout<<c.v[i]<<"\t";
			}
			cout<<dst;
			return;
		}
		
		if(visited[currentnode]) continue;
			visited[currentnode] = true;
		
		for(int i = 0; i<graph[currentnode].size(); i++){
			int y = graph[currentnode][i];
			
			queueEntry u;
			u.curr = y;
			u.v = c.v;
			u.v.push_back(currentnode);
			
			q.push(u);
			
		}
		
		
	}
	
	cout<<"NOT POSSIBLE";return;
}


int main()
{
	vector<int> graph[N];
	
	addedge(graph, 0, 3);
	addedge(graph, 3, 4);
	addedge(graph, 3, 5);
	addedge(graph, 1, 0);
	addedge(graph, 1, 4);
	addedge(graph, 1, 2);
	addedge(graph, 4, 3);
	addedge(graph, 4, 6);
	addedge(graph, 5, 6);
	addedge(graph, 2, 7);
	addedge(graph, 6, 7);

	
	int src = 0, dst = 7;
	
	helper(graph, src, dst);
	
	
	
		
	return 0;
}