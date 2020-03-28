#include<iostream>
#include<algorithm>
#include<vector>
#include<time.h>
using namespace std;

int swapity_swap(int N,int K, int A1,int A2,int B1,int B2){
    int V[N];
   // int temp;
    int time=K%3;
    //int array[6];
    for(int i=0;i<N;i++) V[i]=i+1; //초기화
    
    // if(B1<=A2 && B2>A2){
    //    temp = A2-A1;
    //   int array[]={A1,A1+temp,B1,A2,B2-temp,B2};//구간
    // }
    // else if(A1<=B2 && A2>B2){
    //    temp = B2 -A1;
    //  int array[]={B1,B1+temp,A1,B2,A2-temp,A2};
    //  }
// //DC BA EF ,  DC FE AB ,  EF CD AB , EF BA DC  , AB FE DC  , AB CD EF ??? 3?
//DC FE AB  , EF BA DC , AB CD EF
if((B1<=A2 && B2>A2)||(A1<=B2 && A2>B2)){
    for(int i=0;i<time;i++){
        reverse(V+A1,V+A2+1);
        reverse(V+B1,V+B2+1);
    }
} //겹칠 때
else{
    for(int i=0;i=K%2;i++){
        reverse(V+A1,V+A2);
        reverse(V+B1,V+B2); 
    }
}

    /* for(int i=0;i<N;i++){
    //     V[i]=i+1;
    // }

    // for(int i=0;i<K;i++){
    //     reverse(V[A1],V[A2]);
    //     reverse(V[B1],V[B2]);
    // }
    //PRINT
*/
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