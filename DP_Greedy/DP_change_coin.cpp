#include<iostream>
#define N 27
using namespace std;
int main(){
    int coin[]={1,3,5,7};
    int dp[N+1];
    for(int i=1;i<=N;i++){
        dp[i]=i;
    }
    for(int i=0;i<4;i++){
        for(int j=coin[i];j<=N;j++){
            dp[j]=min(dp[j],dp[j-coin[i]]+1); //Á¡È­½Ä
        }
    }
    cout<<dp[N];
}