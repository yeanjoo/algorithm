#include<iostream>
#include<vector>
#define SIZE 5
using namespace std;

bool visited[]={true,false,false,false,false};
int array[SIZE]={7,3,2,5,8};
int ADD(int visited[], int array[]){
    int NUM=0;   
    for(int i=0;i<SIZE;i++){
        if(visited[i]==true) NUM+=array[i];
    }
    return NUM;
}

bool search(int S, int N, vector<int> V){
    int i=0;
    int cur=0;

for(int i=0;i<SIZE;i++){
        if(S==N){
            for(int j=0;j<SIZE;j++){
                if(visited[j]==true) cout<<array[j]<<" "; //print
            }
            return true;
        }

        if(S<N){
            N-=array[V.back()];
            visited[V.back()]= false;
            V.pop_back();
        }
        else if(S>N){
            cur = V.back();
            cout<<"2 : "<<cur<<" ";
            V.push_back(i);
            N+=array[cur];
            visited[cur]=true;
            search(S,N,V);
        }
}
    return false;
}

int main(){
    vector<int> v;
    v.push_back(0);
   if(search(15,0,v)) cout<<"yes";
   else cout<<"NO";
    }
