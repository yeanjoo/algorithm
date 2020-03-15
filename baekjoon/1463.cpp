#include<iostream>
#define INF 9999999999
// #define THREE 3
// #define TWO 2
int array[]={2,3};

using namespace std;

int dp(int N){
    int dp[N];
    
    for(int i=0;i<N;i++){
        dp[i]=i;
    }//ÃÊ±âÈ­

    for(int i=0;i<2;i++){
        for(int j=array[i];j<N;j++){
            dp[j]=min(dp[j],dp[j-array[i]]+1);
        }
        
    }
    cout<<dp[N-1];   
}

void main(){
    int N;
    cin>>N;
    dp(N);
}