#include<iostream>
using namespace std;


int fibo(int n){
    int fibo[n+1];
    fibo[0]=0;
    fibo[1]=1;
    int K =0;
    int N=0;
    for(int i=0;i<=n;i++){
        fibo[i+2]=fibo[i+1]+fibo[i];
        if(fibo[i]==0) K++;
        if(fibo[i]==1) N++;
    }
    cout<<K<<endl;
    cout<<N<<endl;
    return fibo[n+1];
}

int fibonacci(int n,int count) {
    
    if (n == 0) {
        //printf("0");
        cout<<++count<<endl;
        return 0;
    } else if (n == 1) {
        //printf("1");
        return 1;
    } else {
        return fibonacci(n-1,count)+fibonacci(n-2,count);
    }
}

int main(){
    fibo(0);
}