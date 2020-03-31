#include<iostream>
#include<queue>
//#include<bitset>
#define SIZE 100001
using namespace std;
    int visited[SIZE]={0, };

void BFS(int S, int N){
    //int  time=0;
    queue<int> q;
    //bitset <SIZE> visited;
    
    //visited.reset();//√ ±‚»≠
    q.push(S);
    visited[S]=1;

    while(!q.empty()){
        int cur =q.front(); q.pop();

        if(N==cur) cout<<visited[cur]-1;
        
        if(cur-1 > -1 && visited[cur-1] == 0){
            //visited|=1<<(cur-1);
            visited[cur-1] = visited[cur]+1;
            q.push(cur-1);
        }

        if(cur+1 < SIZE && visited[cur+1] == 0){/*!visited.test(cur)*/

            visited[cur+1] = visited[cur]+1;
            q.push(cur+1);
        }

        if(cur*2 < SIZE && visited[cur*2] == 0){
           //visited|=1<<(2*cur);
           visited[cur*2] = visited[cur]+1;
           q.push(2*cur);
        }
    }
}

int main(){
    int S,N;
    cin>>S>>N;
    BFS(S,N);
}
