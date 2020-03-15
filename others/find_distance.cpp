
#include<iostream>
#include<math.h>
int main(void){
	int function(int r, int c, int count, int size);
	int r,c,n;//r 행 c 열 
	std::cin>>n>>r>>c;
	std::cout<<function(r,c,0,pow(2,n)/2);
}
int function(int r, int c, int count, int size){
	if(size<1) return count;
	
	if(r<size&&c<size)//1사분면 
		return function(r,c,count,size/2);
	
	if(r<size&&c>=size)//2사분면 
		return function(r,c-size,count+pow(size,2),size/2);
	 	
	if(r>=size&&c<size)//3사분면 
		return function(r-size,c,count+pow(size,2)*2,size/2);
		
	if(r>=size&&c>=size)//4사분면 
		return function(r-size,c-size,count+pow(size,2)*3,size/2);
	
}