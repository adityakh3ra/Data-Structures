#include <bits/stdc++.h> 
#include <vector>
using namespace std; 
#define R 6
#define C 5

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct queueEntry{
    int x;
    int y; 
    int dist;
};

void helper(char mat[][C]){
    queue<queueEntry> q;
    vector<vector<int>> v(R, vector<int>(C, INT_MAX));
    
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            if(mat[i][j] == 'M'){
                v[i][j] = 0;
                queueEntry temp;
                temp.x = i; temp.y = j; temp.dist = 0;
                q.push(temp);
            }
            if(mat[i][j] == 'X'){
                v[i][j] = -1;
            }
        }
    }
    
    
    while(!q.empty()){
        queueEntry curr = q.front();
        q.pop();
        for(int i = 0; i<4; i++){
            int a = curr.x + dx[i];
            int b = curr.y + dy[i];
            
            if(a<0 || b<0 || a>=R || b>=C) continue;
            int p = v[a][b];
            v[a][b] = min(curr.dist + 1, v[a][b]);
            if(p==v[a][b]) continue;
            queueEntry e;
            e.x = a; e.y = b; e.dist = v[a][b];
            q.push(e);
        }
    }
    
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            cout<<v[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    
    return;

}





int main(){
    char mat[][C] =
	{
		{'O', 'M', 'O', 'O', 'X'},
		{'O', 'X', 'X', 'O', 'M'},
		{'O', 'O', 'O', 'O', 'O'},
		{'O', 'X', 'X', 'X', 'O'},
		{'O', 'O', 'M', 'O', 'O'},
		{'O', 'X', 'X', 'M', 'O'}
	};

    helper(mat);
    
    
    
    return 0;
}