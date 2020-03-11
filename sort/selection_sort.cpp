//주어진 배열 중에서 최소 값을 찾아 앞에 위치시키는 정렬 방법
#include<iostream>
using namespace std;

void selection(int n, int array[]){
    int Min =array[0];

    for(int i=0; i<n; i++){
        Min =i;
        for(int j=i+1; j<n; j++){
            if(array[Min]>array[j]){
                Min =j;
            }
        }
        swap(array[i],array[Min]);
    }
    //print
    for(int i=0; i<n; i++){
        cout<<array[i]<<" ";
    }
}
int main(){
    int array[]={3,7,1,2,6,4};
    selection(6,array);

}