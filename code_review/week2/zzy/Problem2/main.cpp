#include<iostream>
#include"RA.h"
using namespace std;
int main(){
	int m=0;
	cin>>m;
	ReviewerAssigner me{m};
	me.load();
	me.choose();
	me.output();
	cout<<"done"<<endl;
	return 0;
}
