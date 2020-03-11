#include <iostream>
#define N 7
using namespace std;
int sorted[N];

int merge(int left, int right, int array[]){
    int mid =(left+right)/2;
    int i= left;
    int j =mid+1;
    int k =left;

    while(i<=mid && j<=right){
        if(array[i]<=array[j]){
            sorted[k++] = array[i++];
        }else{
            sorted[k++] = array[j++];}
    }//last
    if(i<mid){
        for(int l=i;l<=mid;l++){
            sorted[k++]=array[l];}

    }else{
        for(int l=j;l<right;l++){
            sorted[k++]=array[l];}

    }
    //swap
    for(int l=left;l<right;l++){
        array[l]=sorted[l];}

}
int merger_sort(int left, int right,int array[]){
    int mid;
    left=mid;
    if(left<right){
        mid= (left + right)/2;
        merger_sort(left,mid,array);
        merger_sort(mid+1,right,array);
        merge(left,right,array);
    }
}

int main(){
    int array[]={3,7,1,2,6,4,5};
    merger_sort(0,N,array);
    //print
    for(int i=0;i<N;i++){
        cout<<array[i]<<" ";
    }
}