#include <bits/stdc++.h> 
#include <vector>
#include <set>

using namespace std;

#define R 8
#define C 8


int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

struct point{
    int x;
    int y; 
    int d;
    
    point(int x, int y, int d = 0) : x(x), y(y), d(d) {}
    
    // bool operator<(const point &a) const{
    // 	if(x < a.x)
    // 		return true;
    		
    // 	if(x==a.x)
    // 		if(y<a.y) return true;
    	
    // 	return false;
    // }
    
    bool operator<(const point& o) const
	{
		return x < o.x || (x == o.x && y < o.y);
	}
};

bool issafe(int x, int y){
    if(x>=0 && y>=0 && y<C && x<R) return true;
    return false;
}

void helper(point src, point dst){
	set<point> visited;
	queue<point> q;
	q.push(src);
	int k = 0;
	while(!q.empty()){
		
		point temp = q.front();
		q.pop();
		
		if(temp.x == dst.x && temp.y == dst.y){
			cout<<temp.d;
			return;
		}
		if(visited.count(temp)) continue; 
		visited.insert(temp);
		
		for(int i = 0; i<8; i++){
			int a = temp.x + dx[i], b = temp.y + dy[i], c = temp.d + 1;
						
			if(issafe(a, b)){
				point x(a, b, c);
				k = c;
				q.push(x);
			}
		}
	}

	cout<<k;
}

int main(){
	point src(0,7), dst(7,0);

	helper(src, dst);
	
    return 0;
}