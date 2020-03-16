#include<iostream>
#include<vector>
#define SIZE 5
using namespace std;

bool visited[]={false,false,false,false,false};
int array[SIZE]={7,3,2,5,8};

void search(int N, int S, vector<int> V){
    int cur =V.back();

    if(V.size()==SIZE) return;
        
    if(visited[cur]==true) return;
     
    V.push_back(cur);
    visited[cur]=true;
        
    search(N+array[cur],S,V);
        
    cout<<N<<" ";
     int next =V.back();
    V.pop_back();
     visited[next]=false;

    search(N-array[next],S,V);
}

int main(){
    vector<int> v={0,1,2,3,4};
    search(0,12,v);
    }
