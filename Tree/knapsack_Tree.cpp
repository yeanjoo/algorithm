#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
struct item{
    float cost;
    int value;
};
//트리에 관한 정보를 가지고 있는 노드 구조체
struct node{
    int level, profit, bound;
    float cost;
};
bool compare(item a, item b){
    return((double)a.value/a.cost>(double)b.value/b.cost)? true : false;
}
int bound(node u, int n, int W, item array[]){
    if(u.cost>=W) return 0; //cost보다 크면 return

    int profit_bound =u.profit;
    int j= u.level+1;
    int totcost = u.cost;
    while((j < n)&&(totcost + array[j].cost <=W)){
        totcost+=array[j].cost;
        profit_bound += array[j].value;
        j++;
    }
    if(j < n) profit_bound+=(W-totcost)* array[j].value/array[j].cost;
    return profit_bound;
}
int knapsack(int W, item array[], int n){
    sort(array,array+n,compare);
    
    queue<node> queue;
    node u,v;

    u.level =1;
    u.profit = u.cost=0;
    queue.push(u);

    int max_profit =0;

    while(!queue.empty()){
        u = queue.front();
        queue.pop();

        if(u.level ==-1) v.level =0;

        if(u.level == n-1) continue;

        v.level = u.level + 1;
        v.cost = u.cost + array[v.level].cost;
        v.profit = u.profit + array[v.level].value;

        if(v.cost <= W && v.profit > max_profit) max_profit = v.profit;

        v.bound = bound(v, n, W, array);

        if(v.bound > max_profit) queue.push(v);

        v.cost = u.cost;
        v.profit = u.profit;
        v.bound = bound(v, n, W, array);

        if(v.bound>max_profit) queue.push(v);
    }

    return max_profit;
}
int main(){
    
}