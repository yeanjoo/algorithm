#include<iostream>
#define N 4
using namespace std;
void greedy_coin(int price, int count[]){
    int coin[]={1,4,5,6}; //코인의 종류
    int cnt=0;
    for(int i=N-1;i>-1;i--){
        count[i]=price/coin[i];
        price = price%coin[i];
        cnt=cnt+count[i];
    }
    //print
    for(int i=0 ; i<N ; i++){
        cout<<coin[i]<<"는 "<<count[i]<<"개 "<<endl;
    }
    
}

int main(){
    int count[N];
    int price =75;
    greedy_coin(price,count);
}