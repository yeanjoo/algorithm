
#include<iostream>
#include<math.h>
int main(void){
	int function(int r, int c, int count, int size);
	int r,c,n;//r �� c �� 
	std::cin>>n>>r>>c;
	std::cout<<function(r,c,0,pow(2,n)/2);
}
int function(int r, int c, int count, int size){
	if(size<1) return count;
	
	if(r<size&&c<size)//1��и� 
		return function(r,c,count,size/2);
	
	if(r<size&&c>=size)//2��и� 
		return function(r,c-size,count+pow(size,2),size/2);
	 	
	if(r>=size&&c<size)//3��и� 
		return function(r-size,c,count+pow(size,2)*2,size/2);
		
	if(r>=size&&c>=size)//4��и� 
		return function(r-size,c-size,count+pow(size,2)*3,size/2);
	
}