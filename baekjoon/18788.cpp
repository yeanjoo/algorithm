#include<iostream>
#include<algorithm>
#include<vector>
#include<time.h>
using namespace std;

int swapity_swap(int N,int K, int A1,int A2,int B1,int B2){
    vector<int> V;
    int array[]={A1,A2,B1,B2};
    int time=K%3;
    sort(array,array+4);

// DC BA EF ,  DC FE AB ,  EF CD AB , EF BA DC  , AB FE DC  , AB CD EF ??? 3?
//DC FE AB  , EF BA DC , AB CD EF
if(B1<=A2||A1<=B2){
    if(time==1){
        //print array[2]->array[1]->array[3]->array[2]->array[0]-> array[1]
    };
    if(time==2){
        //print array[2]->array[3]->array[1]->array[0]->array[2]-> array[1]
    };
    else {
            //??????
    }
} //???? ? ??
//else if(A2<B1||B2<A2) //???? ?? ? ???? ?? ?? ?? ?? ???? ????
//else < // ??? ??? ?? ??? ? ?? ???? ??? ????  ??? ????
    
    
    /* for(int i=0;i<N;i++){
    //     V[i]=i+1;
    // }

    // for(int i=0;i<K;i++){
    //     reverse(V[A1],V[A2]);
    //     reverse(V[B1],V[B2]);
    // }
    //PRINT
*/
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