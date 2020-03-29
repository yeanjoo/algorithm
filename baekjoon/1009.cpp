#include<iostream>
using namespace std;
//��� �ŵ� �������� �̿�
//a^2 mod b = (a*a) mod b = ((a mod b) *(a mod b))mod b
int POW(long base,long long index, int M){
    long long res =1;
    while(index!=0){
        if(index & 1) res =((res*base)%M);//���� �����ʿ� �ִ� ��Ʈ �� ���� ���� ��Ʈ �ڸ��� 1�� ���� �˻� ��
        base =(base*base)%M;
        index=index/2;//������ ��Ʈ ����
        //2�� ������ �Ǹ� ��Ʈ�� ������ ���� �з� �������� �ȴ�
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