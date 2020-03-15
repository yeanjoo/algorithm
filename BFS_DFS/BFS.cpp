#include<iostream>
#include<list>
#include<queue>
//너비 우선 탐색
using namespace std;
void BFS(list<int> graph[], int v, queue<int> q){
    int t;
    bool visited[]={0,0,0,0};

    while(!(q.empty())){
        t=q.front();
        q.pop();

        if(visited[t-1]==true) continue;

        cout<<t<<" ";

        while(!(graph[t].empty())){
            q.push(graph[t].back());
            //cout<<graph[t].back()<<" ";
            graph[t].pop_back();
        }
        visited[t-1]=true;
    }
}
int main(){
    
}