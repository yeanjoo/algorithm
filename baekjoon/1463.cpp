#include<iostream>
#include<vector>
using namespace std;

int array[]={2,3};


int dp(int N){
    vector<int> dp(1000000);
    
    
    for(int i=0;i<N;i++){
        dp[i]=i;
    }//???

    for(int i=0;i<2;i++){
        for(int j=array[i];j<N;j++){
            dp[j]=min(dp[j],dp[j-array[i]]+1);
        }
        
    }
    cout<<dp[N-1];   
}

int main(){
    int N;
    dp(N);
    return 0;
}