#include<iostream>
#define SIZE 5
#define INF 999999999
using namespace std;

int array[SIZE][SIZE]={
        {0,1,INF,1,5},
        {9,0,3,2,INF},
        {INF,INF,0,4,INF},
        {INF,INF,2,0,3},
        {3,INF,INF,INF,0}};

int dp[SIZE][1<<SIZE];

int TSP_DP(int cur, int visited){
    cout<<" HI ";
    if(visited ==(1<<SIZE)-1) return array[cur][0];
    int &cost =dp[cur][visited];
    if(cost !=0) return cost;
    cost = INF;

    for(int i=0;i<=SIZE;i++){
        if(visited&(1<<i)) continue;
        if(array[cur][i]==0) continue;
        cost=min(cost,TSP_DP(i,visited | (1<<i)+array[cur][i]));
    }
    return cost;
}

int main(){
    cout<<TSP_DP(0,0);
}