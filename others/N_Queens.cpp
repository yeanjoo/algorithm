#include<iostream>
#define SIZE 5
using namespace std;

int array[SIZE+1];
int stay[SIZE+1]={0};

bool promising(int i){
    int k;
    bool switches;
    k=1;
    switches =true;

    while(k<i&&switches){
        if(array[i]==array[k]||abs(array[i]-array[k])==i-k)
            switches =false;
            k++;
    }
    return switches;
}
void queens(int i){
    int j;
    int temp;

    if(promising(i)){
        if(i==SIZE){
            for(int j=1;j<=SIZE;j++){
                stay[j]==array[j];
            }
        }
        
        else{
            for(int j=1;j<=SIZE;j++){
                array[i+1]=j;
                queens(i+1);
            }
        }
    }
}