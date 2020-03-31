#include<iostream>
#include<queue>
#include<bitset>
using namespace std;
#define SIZE 100001
int array[]={2,3};


int dp(int N){
    
   //long long dp[SIZE];
    
    
    /*for(int i=0;i<N;i++){
        dp[i]=i;
    }

    for(int i=0;i<2;i++){
        for(int j=array[i];j<N;j++){
            dp[j]=min(dp[j],dp[j-array[i]]+1);
        }
        
    }*/
   // cout<<dp[N-1];

    int  time=0;
    queue<int> q;
    bitset <SIZE> visited;
    
    visited.reset();//√ ±‚»≠
    q.push(N);

    while(!q.empty()){

        int cur =q.front();
        q.pop();

        if(1==cur) cout<<visited[cur]-1;

        if(cur/2 > -1 && !visited.test(cur)){
            visited|=1<<(cur/2);
            q.push(cur/2);
        }

        if(cur-1 < SIZE && !visited.test(cur)){
            visited|=1<<(cur-1);
            q.push(cur-1);
        }

        if(cur/3 > -1 && !visited.test(cur)){
           visited|=1<<(cur/3);
           q.push(cur/3);
        }
        time++;
    }
    return time;
}

int main(){
    int N;
    cin>>N;
    dp(N);
    return 0;
}