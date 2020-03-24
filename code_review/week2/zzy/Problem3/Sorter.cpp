#include<iostream>
#include<time.h>
#include<stdlib.h>
#include"Sorter.h"
using namespace std;

void Sorter::generate(){
	srand(time(0));
	int t=rand()%5001+5000;      //5000<=t<=10000
	int r=rand()%11+10;          //0<=r<=10
	size=t*10+r;                 //size is a random number between 50000 and 100000
	for(int i=0;i<size;i++){
		array[i]=rand();
	}
}

void Sorter::quicksort(int*p,int num){
	if(num<=1){
		return;
	}
	int l=0;int r=num-2;int com=p[num-1];
	while(l<r){
		while(p[l]<=com&&l<r){
			l++;	
		}
		while(p[r]>=com&&l<r){
			r--;
		}
		if(l<r){
			int t=p[l];p[l]=p[r];p[r]=t;
		}
	}
	if(p[l]<=com){
		for(int i=num-1;i>l+1;i--){
			p[i]=p[i-1];
		}
		p[l+1]=com;
		quicksort(p,l+1);quicksort(p+l+2,num-l-2);
	}
	else{
		for(int i=num-1;i>l;i--){
			p[i]=p[i-1];
		}
		p[l]=com;
		quicksort(p,l);quicksort(p+l+1,num-l-1);
	}
}

void Sorter::msort(int*p,int num){
	if(num<=1) return;
	else{
		int midleft=num/2;int midright=num-midleft;
		msort(p,midleft);msort(p+midleft,midright);
		int*now=new int[num];int l=0,r=midleft,nowleft=0;  
		while(l<midleft&&r<num){
			if(p[l]<p[r]){
				now[nowleft]=p[l];nowleft++;l++;
			}
			else{
				now[nowleft]=p[r];nowleft++;r++;
			}
		}
		
		for(;l<midleft;l++){
			now[nowleft]=p[l];nowleft++;
		}
		for(;r<num;r++){
			now[nowleft]=p[r];nowleft++;
		}
		
		for(int i=0;i<num;i++) p[i]=now[i];
		delete[]now;
	}
}

void Sorter::bubblesort(int*p,int num){
	for(int i=1;i<num;i++){
		for(int j=i-1;j>=0;j--){
			if(p[j]>p[j+1]){
				int t=p[j];
				p[j]=p[j+1];
				p[j+1]=t;
			}
			else{
				break;
			}
		}
	}
}
