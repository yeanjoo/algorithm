//최소 간선 거리를 선택하는 알고리즘
#include<iostream>
#include<vector>
#include<algorithm>

#define SIZE 5
#define INF 99999999999
using namespace std;

struct graph{
    int node[2];
    int val;
};

bool cmp(graph a, graph b){
    return((double)a.val < (double)b.val) ? true : false;
}
int getset(int set[],int x){
    if(set[x]==x) return x;
    set[x]=getset(set,set[x]);
}
void unionset(int set[],int a, int b){
    a=getset(set,a);
    b=getset(set,b);
    if(a<b) set[b]=a; // 더 작은 쪽이 조상
    else set[a]=b;
}
bool find(int set[],int a, int b){
    a=getset(set,a);
    b=getset(set,b);
    if(a==b) return true;
    else false;
}
void kruskal(){
    graph s[]={{{1,2},1},{{3,5},2},{{1,3},3},{{2,3},4},{{4,5},5},{{2,4},6}};
    sort(s,s+SIZE,cmp);
    int set[SIZE];
    int total=0;

    for(int i=0;i<SIZE;i++){
        set[i]=i;
    }
    for(int i=0;i<SIZE;i++){
        if(!find(set,s[i].node[0],s[i].node[1])){
            unionset(set, s[i].node[0],s[i].node[1]);
            cout<<s[i].node[0]<<"->"<<s[i].node[1]<<" ";
            total+=s[i].val;
        }
        cout<<endl<<"kruskal 값 : " << total;
    }
}