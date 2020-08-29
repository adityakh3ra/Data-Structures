#include <bits/stdc++.h> 
#include <vector>
using namespace std; 
#define R 10
#define C 10

//TO DO WITH DFS, JUST CHANGE QUEUE TO STACK, AND FRONT() TO TOP()


int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 0, -1, 1, 0, -1, 1};

struct queueEntry{
    int x;
    int y; 
};


void helper(char mat[][C], int x, int y, char newcolor){
  char oldcolor = mat[x][y];
  queue<queueEntry> q;
  queueEntry p;
  p.x = x; p.y = y;
  q.push(p);
  
  while(!q.empty()){
      p = q.front();
      q.pop();
      x = p.x; y = p.y;
      
      for(int i = 0; i<8; i++){
          int a = x + dx[i], b = y + dy[i];
          
          if(a<0 || b<0 || a>=R || b>=C || mat[a][b] != oldcolor) continue;
          
          mat[a][b] = newcolor;
          p.x = a;p.y = b;q.push(p);
          
      }
  }
  
  for(int i = 0; i<R; i++){
      for(int j = 0; j<C; j++){
          cout<<mat[i][j]<<"\t";
      }
      cout<<endl;
  }
  
  

}

int main(){
    char mat[R][C] =
	{
		{ 'Y', 'Y', 'Y', 'G', 'G', 'G', 'G', 'G', 'G', 'G' },
		{ 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'G', 'X', 'X', 'X' },
		{ 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'X', 'X', 'X' },
		{ 'W', 'W', 'W', 'W', 'W', 'G', 'G', 'G', 'G', 'X' },
		{ 'W', 'R', 'R', 'R', 'R', 'R', 'G', 'X', 'X', 'X' },
		{ 'W', 'W', 'W', 'R', 'R', 'G', 'G', 'X', 'X', 'X' },
		{ 'W', 'B', 'W', 'R', 'R', 'R', 'X', 'R', 'R', 'X' },
		{ 'W', 'B', 'B', 'B', 'B', 'R', 'R', 'X', 'X', 'X' },
		{ 'W', 'B', 'B', 'X', 'B', 'B', 'B', 'B', 'X', 'X' },
		{ 'W', 'B', 'B', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
	};
	
	int x = 3, y = 9;
	char c = 'C';
    
    for(int i = 0; i<R; i++){
      for(int j = 0; j<C; j++){
          cout<<mat[i][j]<<"\t";
      }
      cout<<endl;
  }
    
    cout<<endl;cout<<endl;cout<<endl;
    helper(mat, x, y, c);
    
    
    
    return 0;
}