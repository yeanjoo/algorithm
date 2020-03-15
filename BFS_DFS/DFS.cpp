#include<iostream>
#include<list>
#include<stack>

using namespace std;
void DFS(list<int> graph[], int v, stack<int> st){
    int t;
    bool visited[]={0,0,0,0};

    while(!(st.empty())){
        t=st.top();
        st.pop();

        if(visited[t-1]==true) continue;

        cout<<t<<" ";

        while(!(graph[t].empty())){
            st.push(graph[t].back());
            graph[t].pop_back();
        }
        visited[t-1]=true;
    }
}