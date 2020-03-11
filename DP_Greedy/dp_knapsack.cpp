#include<iostream>
#include<math.h>
#define W 27
using namespace std;

int dp_knapsack(int weight[],int price[]){
 /*   int size =sizeof(price)/sizeof(int)+1;
    int ans[size][W];
    int array[size]={0, };
//초기화
    for(int i=0;i<size;i++){
        for(int j=0;j<W;j++){
            ans[i][j]=1/weight[i]*price[i];
        }
    }
//dp
for(int i=1;i<size;i++){
    for(int j=0;j<W;j++){
        if(j>weight[i]){
            ans[i][j]=max(price[i]+ans[i-1][j-weight[i]],ans[i-1][j]);
        }
    }
    return ans[size-1][W-1];*/


    int dp[W];
    for(int i=0;i<=W-1;i++){
        dp[i]=0;
    }//초기화

    for(int i=0;i<=3;i++){
        for(int j=weight[i];j<=W-1;j++){
            dp[j]=max(dp[j],dp[j-weight[i]]+price[i]);
        }
    }
    cout<<dp[W-1];
}

int main(){
    int weight[]={10,10,25};
    int price[] ={15,9,10};
    dp_knapsack(weight,price);
}