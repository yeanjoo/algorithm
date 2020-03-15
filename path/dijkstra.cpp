#include <iostream>
#include <vector>
#include<utility>
#include<queue>
#define SIZE 5
#define INF 987654321

using namespace std;
/*우선순위 큐를 이용한 다익스트라*/
vector<pair<int,int>> adj[SIZE];
int tree[SIZE][SIZE]= {{0,1,3,INF,INF},
                       {1,0,3,6,INF},
                       {3,3,0,4,2},
                       {INF,6,4,0,5},
                       {INF,INF,2,5,0}};

vector<int> dijkstra(int start){

    vector<int> dist(SIZE,INF);//초기에 인식되지 않은 노드사이의 거리임으로 INF (인식된 노드)
    dist[start]=0; // 시작점은 0으로 초기화 한다.

    priority_queue<pair<int,int>> pq;

    pq.push(make_pair(0,start));

    while(!pq.empty()){
        //우선순위 큐에 음의 가중치로 입력되어 있으므로 양으로 변환
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(dist[here]<cost) continue; //작은 값 존재시 무시

        //dist 인접한 노드를 검사 tree 선택 된 노드의 모든 노드를 검사
        for(int i=0;i<SIZE;i++){
            int there =i;
            int nextDist =cost+graph[here][i];

            if(dist[there]>nextDist){ // 더 짧은 경로를 발견하면 , dist[]를 갱신하고 우선순위 큐에 넣는다.
                dist[there]= nextDist;
                pq.push(make_pair(nextDist,there));
            }
        }
    }
    return dist;
}

/*우선순위 큐를 사용하지 않은 다익스트라*/
int V, E, K; // 정점의 수, 간선의 수, 시작 정점 번호

vector<vector<int>> graph; // 간선 가중치. 그래프의 인접 리스트.

vector<int> dijkstra()
{
    vector<int> s,d; // 방문 여부, 최단 경로

    s.assign(V,false);
    d.assign(V,INF);
    d[K-1] = 0; //자기 자신까지 가는 거리는 0

    while(true)
    {
        int m = INF, N=-1;

        //최소 N번째 노드를 찾는다.
        for(int j=0;j<V; j++)
        {
            if(!s[j] && (m>d[j]))
            {
                m = d[j];
                N = j;
            }
        }

        // m이 INF라는 얘기는 방문하지 않은 노드들의 d값이 전부 INF라는 뜻입니다.
        if(m == INF)
            break;

        s[N] = true; // N번째 노드를 방문.

        //d를 탐색하며 N번째 노드를 통해서 가는 길이 더 짧은 길이면 d를 더 짧은 길로 업데이트 한다.
        for(int j=0;j<V;j++)
        {
            //j번째 노드가 이미 방문되었다면 d[j]는 이미 결정된 최소값이므로 변경하면 안된다.
            if(s[j]) continue;

            //N번째 노드와 인접 노드들을 돌며, N을 통해서 가는 거리를 via에 저장한다.
            unsigned int via = d[N] + graph[N][j];

            //N을 통해서 가는 거리가 더 짧으면, 그 인접 노드의 d[j](d까지 가는 거리의 최소거리)를 N을 통해서 가는 거리로 바꿔준다.
            if(d[j] > via)
                d[j] = via;
        }
    }
    return d;
}

int main()
{
    cin>>V>>E;
    cin>>K;

    graph.assign(V, vector<int>(V,INF));

    while(E--)
    {
        int u,v,w;

        cin>>u>>v>>w;

        // 가중치 초기화
        graph[u-1][v-1] = w;
        //graph[v-1][u-1] = w; //무방향성 그래프일 경우 다음 코드를 추가한다.
    }

    vector<int> d = dijkstra();

    for(int i=0;i<d.size();i++)
    {
        if(d[i] == INF)
            cout<<"INF"<<endl;
        else
            cout<<d[i]<<endl;
    }

    return 0;
}