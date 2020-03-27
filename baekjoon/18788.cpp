#include<iostream>
#include<vector>

#include<time.h>
using namespace std;

int swapity_swap(int N,int K, int A1,int A2,int B1,int B2){
    int V[N];

    for(int i=0;i<N;i++){
        V[i]=i+1;
    }

    for(int i=0;i<K;i++){
        for(int j=A1,l=A2;j<l;j++,l--){
            swap(V[j],V[l]);
        }
        for(int j=B1,l=B2;j<l;j++,l--){
            swap(V[j],V[l]);
        }
    }
    
    //PRINT
    for(int i=0;i<N;i++){
        cout<<V[i]<<" ";
    }

}
int main(){
   // clock_t begin,end;
   // begin= clock();
    int N,K,A1,A2,B1,B2;
    cin>>N>>K>>A1>>A2>>B1>>B2;
    swapity_swap(N,K,A1-1,A2-1,B1-1,B2-1);
     //end= clock();
    // cout<<"수행시간 "<<((end-begin)/CLOCKS_PER_SEC)<<endl;7 2
}