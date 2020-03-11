#include<iostream>
#define N 4 // price의 종류
using namespace std;
//가중치
int greedy_profit(int weight[],int price[],int max){
    float array[N];
    int temp=0;
    int optp=0;
    int cnt=0;
    max =max-1;

    for(int i=0 ; i<N ; i++){
        array[i]=(float)price[i]/weight[i];
    }//가성비 구하기
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(array[temp]<=array[i]) temp =i;
        }
        array[temp]=-1; // 같은 값이 선택되지 않도록 음수
        cnt=max/weight[temp];
        max=max%weight[temp];
        optp=optp+price[temp]*cnt;
    }
    return optp;
}
//가격
int greedy_price(int weight[],int price[],int max){
    int temp=0;
    int optp=0;
    int cnt=0;
    max=max-1;
    
    for(int i=N;i>-1;i--){
        cnt=max/weight[i];
        max=max%weight[i];
        optp=optp+price[i]*cnt;
    }
    return optp;
}
//무게
int greedy_weight(int weight[],int price[],int max){
    int temp=0;
    int optp=0;
    int cnt=0;
    max=max-1;
    for(int i=0;i<N;i++){
        cnt=max/weight[i];
        max=max%weight[i];
        optp = optp+price[i]*cnt;
    }
    return optp;
}
int main(){

}