#include<iostream>
#include<queue>
//#include<bitset>
#define SIZE 100001
using namespace std;
int BFS(int S, int N){
    int  time=0;
    queue<int> q;
    //bitset <SIZE> visited;
    bool visited[SIZE]={0, };
    
    //visited.reset();//√ ±‚»≠
    q.push(N);

    while(!q.empty()){
        int cur =q.front();
        q.pop();

        if(S==cur) return time;

        if(cur+1 < SIZE && visited[cur+1] == false){/*!visited.test(cur)*/

            visited[cur+1] = true;
            q.push(cur+1);
        }

        if(cur-1 > -1 && visited[cur-1] == false){
            //visited|=1<<(cur-1);
            visited[cur-1] = true;
            q.push(cur-1);
        }

        if(cur*2 < SIZE && visited[cur*2] == false){
           //visited|=1<<(2*cur);
           visited[cur*2] = true;
           q.push(2*cur);
        }
        time++;
    }
    return time;
}

int main(){
    int S,N;
    cin>>S>>N;
    cout<<BFS(S,N);
}