#include<iostream>
#define N 10
using namespace std;
int array[N]={1,2,3,4,5,6,7,8,9,10};
int binary(int low, int high, int search){
    int mid =(high+low)/2;
    if(array[mid]==search){
        return mid;
    }else if(array[mid]>search){
        binary(low,mid,search);
    }else{
        binary(mid+1,high,search);
    }
}
int main(){
    cout<<binary(0,N,3);
}