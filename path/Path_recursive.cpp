#include<iostream>
#define SIZE 5
using namespace std;
//��͸� ����Ͽ� N�� M ���� �ִ� ��θ� ���ϴ� ����
void search(int N, int M){
    int array[SIZE][SIZE]={
        {0,0,4,0,4},
        {5,0,0,0,4},
        {5,5,0,0,4},
        {5,5,0,0,0},
        {0,1,4,1,0}};

        if(array[N][M]==0) return;
        search(N,array[N][M]-1);
        cout<<array[N][M]<<"->";
        search(array[N][M]-1,M);
}
int main(){
    search(2,3);
}