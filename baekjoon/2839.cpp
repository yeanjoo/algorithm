#include<iostream>
using namespace std;
int main(){
    int N;
    int F,T,temp=0;
    cin>>N;
    F=N/5;//초기값 F 5로 나눈 몫
    T=N%5;//T 나머지 값
    while(F>=0){
        if(T%3==0){//나머지값을 3으로 나눌 수 있다면 최소
            cout<<F+(T/3);
            break;
        }
        F--;
        T+=5;//만약 5로 나누어 떨어지지 않는다면 나머지에 5를 더해주기
    }
    /*F=N/5;
    T=(N%5)/3;
    while(F>=0){
        if(F*5+T*3==N) cout<<" ";
        F--;
        T=(N-5*F)/3;
    }*/
}