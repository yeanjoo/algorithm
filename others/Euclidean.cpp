#include<iostream>
using namespace std;
//최소 공약수를 구하는 알고리즘

int euclidean_algorithm(int a, int b);
int resmod_algorithm(int a,int b);
int mod_algorithm(int a, int b);

int main(){
    cout<<euclidean_algorithm(48,18)<<endl;
    cout<<resmod_algorithm(48,18)<<endl;
    cout<<mod_algorithm(48,18)<<endl;
}

int euclidean_algorithm(int a, int b){
    while(1){
        if(a<0||b<0) return 0;
        if(a==b) return a;
        if(a>b) a=a-b;
        else b=b-a;
    }
}

int resmod_algorithm(int a,int b){
    int mid;
    while(1){
        if(b==0) return a;
        if(a<0||b<0) return 0;
        else{
            mid=a%b;
            a=b;
            b=mid;
        }
    }
};

int mod_algorithm(int a, int b){
    if(b==0) return a;
    else mod_algorithm(b,a%b);
};