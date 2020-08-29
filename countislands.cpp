#include <bits/stdc++.h> 
#include <vector>
using namespace std; 
#define R 10
#define C 10

int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 0, -1, 1, 0, -1, 1};

struct queueEntry{
    int x;
    int y; 
};

void helper2(int mat[][C], int x, int y, vector<vector<bool> > &visited, int &islands){
     queue<queueEntry> q;
     
     visited[x][y] = true;
     
     queueEntry e;
     e.x = x; e.y = y;
     q.push(e);
     while(!q.empty()){
        e = q.front();
        q.pop();
        
        for(int i = 0; i<8; i++){
         int a = e.x + dx[i], b = e.y + dy[i];
         
         if(a<0 || b<0 || a>=R || b>=C || visited[a][b] || mat[a][b]==0) continue;
         
         queueEntry t;
         t.x = a; t.y = b;
         visited[a][b] = true;
         q.push(t);
     }
     }
     
     islands++;
     
     return;
}

void helper(int mat[][C]){
   
    vector<vector<bool> > visited(R, vector<bool>(C, false));
for(int i = 0; i<R; i++){
    for(int j = 0; j<C; j++){
        if(mat[i][j] == 0) visited[i][j] = true;        
    
    }
    
}        
            
    int islands = 0;
    
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            if(mat[i][j] == 1 && !visited[i][j]){
                helper2(mat, i, j, visited, islands);
            }
            
        }
    }
    
    
    cout<<islands;
    
    return;

}





int main(){
    int mat[R][C]=
	{
		{ 1, 0, 1, 0, 0, 0, 1, 1, 1, 1 },
		{ 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 1, 0, 0, 0 },
		{ 1, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 },
		{ 0, 1, 0, 1, 0, 0, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0 },
		{ 0, 0, 0, 1, 0, 0, 1, 1, 1, 0 },
		{ 1, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 }
	};

    helper(mat);
    
    
    
    return 0;
}