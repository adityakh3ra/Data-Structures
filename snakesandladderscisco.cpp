#include <iostream>
#include <queue>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#define N 10
//1 - 100
struct Node{
    int x;
    int d;
    int l = 0;
    int s = 0;
};

void findSolution(unordered_map<int, int> ladder, unordered_map<int, int> snake, int m){
    int ladders = 0, snakes = 0, rolls = 0;
    
    queue<Node> q;
    
    Node e;
    e.x = 0;
    e.d = 0;
    
    vector<bool> visited(N+1, false);
    
    q.push(e);
    
    while(!q.empty()){
        Node curr = q.front();
        q.pop();
        // cout<<curr.x<<endl;
        if(visited[curr.x]) continue;
        visited[curr.x] = true;
        
        if(curr.x == 100){
            rolls = curr.d;
            cout<<curr.l<<"\t\t"<<curr.s<<"\t\t"<<rolls<<endl;
            break;
        }
        
        for(int i = 0; i<m; i++){
            int a = curr.x + i;
            int l1 = 0, s1 = 0;
            if(a>100 || visited[a]) continue;
            
    
            while( snake.find(a) != snake.end() || ladder.find(a) != ladder.end()){
                if(snake.find(a) != snake.end()){
                    int newposition = snake[a];
                    a = newposition;
                    s1++;
                }
                else{
                    int newposition = ladder[a];
                    a = newposition;
                    l1++;
                }
            }
            

            
            Node temp;
            temp.x = a;
            temp.d = curr.d + 1;
            temp.l = curr.l + l1; temp.s = curr.s + s1;
            q.push(temp);
        }
        
    }
    
    return;
    
}

int main()
{
    // snakes and ladders are represented using a map
    unordered_map<int, int> ladder, snake;

    // insert ladders into the map
    ladder[1] = 38;
    ladder[4] = 14;
    ladder[9] = 31;
    ladder[21] = 42;
    ladder[28] = 84;
    ladder[51] = 67;
    ladder[72] = 91;
    ladder[80] = 99;

    // insert snakes into the map
    snake[17] = 7;
    snake[54] = 34;
    snake[62] = 19;
    snake[64] = 60;
    snake[87] = 36;
    snake[93] = 73;
    snake[95] = 75;
    snake[98] = 79;

    findSolution(ladder, snake, 6);

    return 0;
}