#include<iostream>
#include<vector>
#include<bitset>
using namespace std;
#define SIZE 1000001

int dp(int N){
      int dp[N+1];
      dp[0]=dp[1]=0;
      int count=0;
      for(int i=1;i<N;i++){

          dp[i]=dp[i-1]+1;
          
          if(dp[i]==0) break;
          
          if(dp[i]%2==0){
              dp[i]=min(dp[i],dp[i/2]+1);
          }
          if(dp[i]%3==0){
              dp[i]=min(dp[i],dp[i/3]+1);
          }
      } 
      return dp[N];
}

int main(){
    int N;
    cin>>N;
    dp(N);
    return 0;
}