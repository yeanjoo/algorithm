//�ε��� Ű�� ���� ���� �� Ű���� ũ���� �տ� ���� ���
//���� �� Ű�� �ε��� �տ� �����ϴ� ����
#include<iostream>
using namespace std;

int insertion(int n, int array[]){
    int key;
    int x;
    for(int i= 2; i<n; i++){
        x=i;
        key =array[i];
        
        for(int j = i-1 ; j>=0 ; j--){
            if(key<array[j]){
                array[x] = array[j];
                x = j;}
        }
        array[x] = key;
    }
    //print
    for(int i=0; i<n; i++){
        cout<<array[i]<<" ";
    }
}

int main(){
    int array[]={3,7,1,2,6,4};
    insertion(6,array);
}