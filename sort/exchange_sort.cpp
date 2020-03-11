#include<iostream>
#define N 7
using namespace std;
//인덱스 키와 나머지 키를 비교하여 인덱스 키의 크기가 나머지 키보다 크면 서로 순서를
//바꾸는 정렬 방법
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