#include<iostream>
#define N 7
using namespace std;
//�ε��� Ű�� ������ Ű�� ���Ͽ� �ε��� Ű�� ũ�Ⱑ ������ Ű���� ũ�� ���� ������
//�ٲٴ� ���� ���
int exchange(int array[]){
    for(int i=0; i<N;i++){
        int index =i;
        for(int j=i ; j<N; j++){
            if(array[index]>array[j]) swap(array[index],array[j]);
        }
    }
}
int main(){
    int array[]={3,7,1,2,9,0,2};
    exchange(array);
    //print
    for(int i=0;i<N;i++){
        cout<<array[i]<<" ";
    }
}