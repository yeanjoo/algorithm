#include<iostream>
using namespace std;
//모듈 거듭 제곱법을 이용
//a^2 mod b = (a*a) mod b = ((a mod b) *(a mod b))mod b
int POW(long base,long long index, int M){
    long long res =1;
    while(index!=0){
        if(index & 1) res =((res*base)%M);//가장 오른쪽에 있는 비트 즉 가장 작은 비트 자리에 1의 여부 검사 후
        base =(base*base)%M;
        index=index/2;//오른쪽 비트 제거
        //2로 나누게 되면 비트는 오른쪽 부터 밀려 없어지게 된다
    }
    return res;
}
int main(void){
    int N;
    cin>>N;
    int A[N];
    int B[N];
    
    for(int i=0;i<N;i++)
        cin>>A[i]>>B[i];

    for( int i=0;i<N;i++)
        cout<<POW(A[i],B[i],10)<<endl;
}