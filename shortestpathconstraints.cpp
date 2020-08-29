#include <iostream>
#include <queue>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define N 10

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

struct node{
	int x, y, d;
};

void helper(int mat[][N]){
	queue<node> q;
	
	vector<vector<bool> > visited(N, vector<bool>(N, false));
	
	node n;
	n.x = 0;
	n.y = 0;
	n.d = 0;
	
	q.push(n);
	
	while(!q.empty()){
		node curr = q.front();
		q.pop();
		// cout<<curr.x<<"\t\t"<<curr.y<<endl;
		if(visited[curr.x][curr.y]) continue;
		
		if(curr.x == N-1 && curr.y == N-1){
			cout<<curr.d;
			return;
		}
		
		visited[curr.x][curr.y] = true;
		
		for(int i = 0; i<4; i++){
			int a, b;
			if(dx[i]==1 && dy[i]==0){
				a = curr.x + mat[curr.x][curr.y];
				b = curr.y;
			}
			else if(dx[i]==-1 && dy[i]==0){
				a = curr.x - mat[curr.x][curr.y];
				b = curr.y;
			}
			else if(dy[i]==1 && dx[i]==0){
				b = curr.y + mat[curr.x][curr.y];
				a = curr.x;
				
			}
			else if(dy[i]==-1 && dx[i]==0){
				b = curr.y - mat[curr.x][curr.y];
				a = curr.x;
				
			}
			
			if(a<0 || b<0 || a>=N || b>=N || visited[a][b]) continue;
			
			node temp;
			temp.x = a;
			temp.y = b;
			temp.d = curr.d + 1;
			
			q.push(temp);
		}
	}
	
	cout<<"NOT POSSIBLE";
	return;
	
}

int main()
{
	int matrix[N][N] =
		{
			{ 9, 4, 6, 5, 5, 1, 1, 1, 7, 4 },
			{ 3, 6, 2, 4, 6, 5, 7, 2, 6, 6 },
			{ 1, 3, 6, 1, 1, 1, 7, 1, 4, 5 },
			{ 7, 5, 6, 3, 1, 3, 3, 1, 1, 7 },
			{ 3, 4, 6, 4, 7, 2, 6, 5, 4, 4 },
			{ 3, 2, 5, 1, 2, 5, 1, 2, 3, 4 },
			{ 4, 2, 2, 2, 5, 2, 3, 7, 7, 3 },
			{ 7, 2, 4, 3, 5, 2, 2, 3, 6, 3 },
			{ 5, 1, 4, 2, 6, 4, 6, 7, 3, 7 },
			{ 1, 4, 1, 7, 5, 3, 6, 5, 3, 4 }
		};
		
	
	helper(matrix);
		
	return 0;
}