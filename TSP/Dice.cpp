#include<iostream>
#include<vector>
#include<bitset>
#define SIZE 1000
using namespace std;

bitset<SIZE> visited;
vector<int> V(100);

//���� �ֻ��� Ƚ��,  �������� ��, ���� Ƚ��
//�迭 0��° �Ⱦ�
int dp_dice(int cur,int k ,int size){
    int temp=0;

    for(int i=0;i<size;i++){
        V[cur]=i;
        if(cur<size) dp_dice(cur++,k,size); //�ߺ� ���� �̷���,,,
        //�������� ���� �ߴٸ�
        if(cur==size-1){
            for(int j=0;j<size;j++){
                temp+=V[j];
            }
            if(temp==k){
                for(int j=0;j<size;j++)
                cout<<V[j]<<" ";
            }
        }
    }

  /*  for(int i=1;i<size+1;i++){

        if(visited.test(i)) continue;
        
        V.push_back(i);
        dice[V.back()]=i;
        visited|=1<<i; //�湮 ǥ��
        num+=dice[i];

        dp_dice(size,N,dice,num);
        
        int next = V.back();
        V.pop_back();
        visited&= !(1<<next);
        num-=dice[next];

        for(int j=0;j<size;j++){
            temp+=dice[j];
        }

        if(N==temp){
            //print
        }
    }*/
    
}
int main(){
    int size,k;
    cin>>size>>k;
    dp_dice(0,k,size);
    
}

// ���� https://www.it-note.kr/288 [IT ������ Note]