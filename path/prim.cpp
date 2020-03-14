#include<iostream>
#include<vector>
#include<queue>
#include<utility>

#define SIZE 5
#define INF 99999999999
using namespace std;
//인접한 노드들 중 최소 간선으로 연결된 노드를 선택하여 트리를 확장하는 알고리즘

int tree[SIZE][SIZE]= {{0,1,3,INF,INF},
                       {1,0,3,6,INF},
                       {3,3,0,4,2},
                       {INF,6,4,0,5},
                       {INF,INF,2,5,0}};

vector<bool> selected(SIZE,false);
vector<int> dist(SIZE,INF);
vector<int> v(SIZE,0);//경로를 저장할 벡터
priority_queue <pair<int,int>> pq;

int vertex_min(){
    int v;
    for(int i=0;i<SIZE;i++){
        if(selected[i]==true) continue;
        v=i;
        break;
    }

    for(int i=0;i<SIZE;i++){
        if(selected[i]==false&&dist[i]<dist[v]) v=i;
    }
    return v;
}
int prim(){
    dist[0]=0;
    int u;
    int total=0;
    int temp=0;

    for(int i=0;i<SIZE;i++){
        u=vertex_min();
        selected[u]=true;
        if(dist[u]==INF) return 0;

        for(int j=0;j<SIZE;j++){
            if(tree[u][j]==INF) continue;

            if(selected[j]==false&&tree[u][j]<dist[j]){
                dist[j]=tree[u][j];
                v[j]=i;
            }
        }
    }
    for(int i=0;i<SIZE;i++){
        total+=tree[v[i]][i];
    }
    return total;
}
//우선순위 큐를 사용한 알고리즘

int qprim(){
    int u;
    int total=0;
    int temp =0;
    pq.push(make_pair(0,0));

    for(int i=0;i<SIZE;i++){
        u=pq.top().second;
        pq.pop();

        if(selected[u]==true) continue;
        selected[u]=true;

        for(int j=0 ; j<SIZE;j++){
            if(selected[j]==false&&tree[u][j]<dist[j]){
                dist[j]=tree[u][j];
                pq.push(make_pair(-tree[u][j],j));
            }
        }
    }
    
    for(int i=0;i<SIZE;i++){
        total+=tree[v[i]][i];
    }
    return total;
    
}
int main(){

}