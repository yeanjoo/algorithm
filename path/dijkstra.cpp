#include <iostream>
#include <vector>
#include<utility>
#include<queue>
#define SIZE 5
#define INF 987654321

using namespace std;
/*�켱���� ť�� �̿��� ���ͽ�Ʈ��*/
vector<pair<int,int>> adj[SIZE];
int tree[SIZE][SIZE]= {{0,1,3,INF,INF},
                       {1,0,3,6,INF},
                       {3,3,0,4,2},
                       {INF,6,4,0,5},
                       {INF,INF,2,5,0}};

vector<int> dijkstra(int start){

    vector<int> dist(SIZE,INF);//�ʱ⿡ �νĵ��� ���� �������� �Ÿ������� INF (�νĵ� ���)
    dist[start]=0; // �������� 0���� �ʱ�ȭ �Ѵ�.

    priority_queue<pair<int,int>> pq;

    pq.push(make_pair(0,start));

    while(!pq.empty()){
        //�켱���� ť�� ���� ����ġ�� �ԷµǾ� �����Ƿ� ������ ��ȯ
        int cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(dist[here]<cost) continue; //���� �� ����� ����

        //dist ������ ��带 �˻� tree ���� �� ����� ��� ��带 �˻�
        for(int i=0;i<SIZE;i++){
            int there =i;
            int nextDist =cost+graph[here][i];

            if(dist[there]>nextDist){ // �� ª�� ��θ� �߰��ϸ� , dist[]�� �����ϰ� �켱���� ť�� �ִ´�.
                dist[there]= nextDist;
                pq.push(make_pair(nextDist,there));
            }
        }
    }
    return dist;
}

/*�켱���� ť�� ������� ���� ���ͽ�Ʈ��*/
int V, E, K; // ������ ��, ������ ��, ���� ���� ��ȣ

vector<vector<int>> graph; // ���� ����ġ. �׷����� ���� ����Ʈ.

vector<int> dijkstra()
{
    vector<int> s,d; // �湮 ����, �ִ� ���

    s.assign(V,false);
    d.assign(V,INF);
    d[K-1] = 0; //�ڱ� �ڽű��� ���� �Ÿ��� 0

    while(true)
    {
        int m = INF, N=-1;

        //�ּ� N��° ��带 ã�´�.
        for(int j=0;j<V; j++)
        {
            if(!s[j] && (m>d[j]))
            {
                m = d[j];
                N = j;
            }
        }

        // m�� INF��� ���� �湮���� ���� ������ d���� ���� INF��� ���Դϴ�.
        if(m == INF)
            break;

        s[N] = true; // N��° ��带 �湮.

        //d�� Ž���ϸ� N��° ��带 ���ؼ� ���� ���� �� ª�� ���̸� d�� �� ª�� ��� ������Ʈ �Ѵ�.
        for(int j=0;j<V;j++)
        {
            //j��° ��尡 �̹� �湮�Ǿ��ٸ� d[j]�� �̹� ������ �ּҰ��̹Ƿ� �����ϸ� �ȵȴ�.
            if(s[j]) continue;

            //N��° ���� ���� ������ ����, N�� ���ؼ� ���� �Ÿ��� via�� �����Ѵ�.
            unsigned int via = d[N] + graph[N][j];

            //N�� ���ؼ� ���� �Ÿ��� �� ª����, �� ���� ����� d[j](d���� ���� �Ÿ��� �ּҰŸ�)�� N�� ���ؼ� ���� �Ÿ��� �ٲ��ش�.
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

        // ����ġ �ʱ�ȭ
        graph[u-1][v-1] = w;
        //graph[v-1][u-1] = w; //�����⼺ �׷����� ��� ���� �ڵ带 �߰��Ѵ�.
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