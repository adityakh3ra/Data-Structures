#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define N 19

bool issafe(int c){
    if(c>=0 && c<N) return true;
    return false;
}

void foo(int arr[N]){
    bool visited[N] = {false};
    map<int, vector<int>>  mat;
    queue<pair<int, int>> q;
    vector<int> distance(0, N);

    for(int i = 0; i<N; i++){
        (mat[arr[i]]).push_back(i);
    }
  

    q.push({0, 0});
    
    while(!q.empty()){
        pair<int, int> temp = q.front();
        q.pop();
        
        int curr = temp.first, d = temp.second;
        if(visited[curr]) continue;
        
        visited[curr] = true;
        
        if(curr == N-1){
            cout<<d;
            return;
        }
        
        if(issafe(curr+1)) q.push({curr+1, d+1});
        if(issafe(curr-1)) q.push({curr-1, d+1});
        
        for(int i = 0; i<mat[arr[curr]].size(); i++){
            if(issafe(mat[arr[curr]][i])) q.push({mat[arr[curr]][i], d+1});
        }
    }
    
    cout<<"error";
    return;
}
    
int main()
{
    int arr[] =  {0, 1, 2, 3, 4, 5, 6, 7, 5, 4,
                 3, 6, 0, 1, 2, 3, 4, 5, 7};
    
    foo(arr);
    
    return 0;
}