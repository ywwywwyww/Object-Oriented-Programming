#include<iostream>
#include"timer.h"
#include"Sorter.h"
using namespace std;
int main(){
	Sorter s{};
	Timer clock{};
	s.generate();
	int num=s.s();
	cout<<endl<<"sorting size:"<<num<<endl<<endl;
	
	int*t=new int[num];
	for(int i=0;i<num;i++){
		t[i]=s.array[i];
	}
	clock.start();
	s.bubblesort(t,num);
	clock.stop();
	double b_runtime=clock.time();
	cout<<"bubblesort runtime:"<<b_runtime<<endl;
	clock.reset();
	
	for(int i=0;i<num;i++){
		t[i]=s.array[i];
	}
	clock.start();
	s.msort(t,num);
	clock.stop();
	double m_runtime=clock.time();
	cout<<"mergesort runtime:"<<m_runtime<<endl;
	clock.reset();
	
	for(int i=0;i<num;i++){
		t[i]=s.array[i];
	}
	clock.start();
	s.quicksort(t,num);
	clock.stop();
	double q_runtime=clock.time();
	cout<<"quicksort runtime:"<<q_runtime<<endl<<endl;
	clock.reset();
	
	//usually bubblesort is the slowest
	cout<<"quicksort improvement:"<<(b_runtime-q_runtime)*100/b_runtime<<"%"<<endl;
	cout<<"mergesort improvement:"<<(b_runtime-m_runtime)*100/b_runtime<<"%"<<endl;
	
	return 0;
	
}
