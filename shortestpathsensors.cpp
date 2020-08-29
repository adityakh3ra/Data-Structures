#include <iostream>
#include <bits/stdc++.h>

#define N 10

using namespace std;


int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};


struct node{
	int x, y, d;
};

int helper(int mat[][N], int row){
	queue<node> q;
	vector<vector<bool> > visited(N, vector<bool>(N, false));
	
	node n;
	n.x = row;
	n.y = 0;
	n.d = 0;
	
	q.push(n);
	
	while(!q.empty()){
		node f = q.front();
		q.pop();
		
		if(visited[f.x][f.y]) continue;
		
		visited[f.x][f.y] = true;
		if(f.y == N-1){
			return f.d;
		}
		
		for(int i = 0; i<4; i++){
			int a = f.x + dx[i];
			int b = f.y + dy[i];
			
			if(a < 0 || b < 0 || a>=N || b>=N || mat[a][b] != 1) continue;
			
			node j;
			j.x = a;
			j.y = b;
			j.d = f.d + 1;
			q.push(j);
		}
	}
	
	
	return 1001;
}

int main(){
	int field[N][N] =
	{
		{ 0, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
		{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};
	
	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			if(field[i][j] == 0){
				for(int k = 0; k<8; k++){
					int a = i + dx[k];
					int b = j + dy[k];
					if(a < 0 || b<0 || a>=N || b>=N) continue;
					field[a][b] = -1;
				}
			}
		}
	}
	
	// for(int i = 0; i<N; i++){
	// 	for(int j = 0; j<N; j++){
	// 		cout<<field[i][j]<<"\t";
	// 	}
	// 	cout<<endl;
	// }
	
	int y = 1000;
	for(int i = 0; i<N; i++)
		if(field[i][0] == 1 && field[i][1] == 1){
			int x = helper(field, i);
			y = min(x, y);
		}
	
	
	cout<<y;
	return 0;
	

}
