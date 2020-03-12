#include<iostream>
#define SIZE 5
#define INF 99999999
using namespace std;
//N과 M의 최단거리를 구하는 문제
void search(int N, int M){
    int Path[SIZE][SIZE]={-1, };
    int array[SIZE][SIZE]={
        {0,1,INF,1,5},
        {9,0,3,2,INF},
        {INF,INF,0,4,INF},
        {INF,INF,2,0,3},
        {3,INF,INF,INF,0}};

        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                for(int k=0;k<SIZE;k++){
                    if(array[j][k]>array[j][i])
                        array[j][k]=min(array[j][k],array[j][i]+array[i][k]);
                }
            }
        }
        cout<<array[N][M]<<endl;
}
int main(){
    search(2,3);
}