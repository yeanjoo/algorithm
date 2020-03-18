#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define SIZE 5
using namespace std;
// << DP로 바꿔보기 >>
bool visited[]={false,false,false,false,false};
int array[SIZE]={7,3,2,5,8};
vector <string>res;
bool search(int S, int N, vector<int> V){
    string temp;
    for(int i=0;i<SIZE;i++){
        if(visited[i]==true) continue;
        //cout<<"1 : "<<N<<endl;
        //if(S<N){
           // cout<<"들어가는 수 : "<<i<<" "<<endl;
            V.push_back(i);
            visited[i]=true;
            search(S+array[i],N,V);
      //  }
       //cout<<S<<" "; << Debug
      //  if(visited[V.back()]==true){
            //int next = V.back();
            visited[V.back()]=false;
            V.pop_back();
          //  cout<<endl<<"나가는 수 : "<<next<<endl;
            //visited[next]=false;
           // S-=array[next];<<?? 이걸 왜 안넣어도 되는 거지
            
     //   } 
        if(S==N){   
            temp=" ";
            for(int j=0;j<SIZE;j++){
                if(visited[j]==true) temp+=to_string(array[j])+" ";//print
            }
            res.push_back(temp);
        }
    }
}

int main(){
    vector<int> v;
    vector<string>::iterator iter= res.begin();
    search(0,18,v);
    if(!res.size()){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES ";
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        for(iter=res.begin();iter!=res.end();++iter){
            cout<<" ["<<*iter<<"]";
        }
    }
}