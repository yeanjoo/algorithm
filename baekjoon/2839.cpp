#include<iostream>
using namespace std;
int main(){
    int N;
    int F,T,temp=0;
    cin>>N;
    F=N/5;//�ʱⰪ F 5�� ���� ��
    T=N%5;//T ������ ��
    while(F>=0){
        if(T%3==0){//���������� 3���� ���� �� �ִٸ� �ּ�
            cout<<F+(T/3);
            break;
        }
        F--;
        T+=5;//���� 5�� ������ �������� �ʴ´ٸ� �������� 5�� �����ֱ�
    }
    /*F=N/5;
    T=(N%5)/3;
    while(F>=0){
        if(F*5+T*3==N) cout<<" ";
        F--;
        T=(N-5*F)/3;
    }*/
}