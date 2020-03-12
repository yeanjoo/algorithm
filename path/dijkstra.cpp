#include <iostream>
#include <vector>

#define INF 987654321

using namespace std;

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