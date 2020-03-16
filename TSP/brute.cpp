#include<iostream>
#include<vector>
#define SIZE 5
#define INF 999999999
using namespace std;

int array[SIZE][SIZE]={
        {0,1,INF,1,5},
        {9,0,3,2,INF},
        {INF,INF,0,4,INF},
        {INF,INF,2,0,3},
        {3,INF,INF,INF,0}};

int t_cost=INF;

int TSP(vector<int> path, bool visited[], int cost){
    int temp;

    if(path.size()==SIZE){
        return cost+array[path.back()][0];
    }

    for(int i=0;i<SIZE;i++){

        if(visited[i]==true) continue;

        int cur =path.back();
        path.push_back(i);
        visited[i]=true;

        temp=min(t_cost,TSP(path,visited,cost+array[cur][i]));
        
        if(t_cost>temp) cout<<cur<<"->"<<i<<" "; //경로 출력
       
        t_cost=temp;
        visited[path.back()]=false;
        path.pop_back();
    }

    return t_cost;
}
int main(){
    vector<int> v;
    v.push_back(0);
    bool visited[]={true,false,false,false,false};
    TSP(v,visited,0);
    }
