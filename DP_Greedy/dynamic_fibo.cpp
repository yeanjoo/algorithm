#include<iostream>
#define N 4
using namespace std;
int dynamic_fibo(int n){
    int fibo[n+1];
    fibo[0]=0;
    fibo[1]=1;

    for(int i=2;i<=n;i++){
        fibo[i]=fibo[i-1]+fibo[i-2]; //memorizing
    }
    return fibo[n];
}
int main(){
    dynamic_fibo(N);
}