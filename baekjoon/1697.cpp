#include<iostream>
#include<queue>
#include<bitset>
#define SIZE 100001
using namespace std;
int BFS(int S, int N){
    int  time=0;
    queue<int> q;
    bitset <SIZE> visited;
    
    visited.reset();//√ ±‚»≠
    q.push(N);

    while(!q.empty()){
        int cur =q.front();
        q.pop();

        if(S==cur) return time;

        if(cur+1 < SIZE && !visited.test(cur)){
            visited|=1<<(cur+1);
            q.push(cur+1);
        }

        if(cur-1 > -1 && !visited.test(cur)){
            visited|=1<<(cur-1);
            q.push(cur-1);
        }

        if(cur*2 < SIZE && !visited.test(cur)){
           visited|=1<<(2*cur);
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