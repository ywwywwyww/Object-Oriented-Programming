#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
#include"RA.h"
using namespace std;

//constructor
ReviewerAssigner::ReviewerAssigner(int num){
	myNum=num;
	total=0;
	chosen[0]=-1;
	chosen[1]=-1;
	chosen[2]=-1;
	for(int i=0;i<100;i++){
		stuNum[i]=0;
		email[i][0]='\0';
	}
}

void ReviewerAssigner::load(){
	ifstream loadin("ContactEmail.txt");
	char a[20],b[20];
	loadin>>a>>b;      //don't need the first line 
	total=0;
	while(!loadin.eof()){
		loadin>>stuNum[total]>>email[total];
		total++;
	}
	loadin.close();
}

void ReviewerAssigner::choose(){
	srand(time(0));
	int done=0;
	while(done<3){
		int choice=rand()%total;   //random number 0 ~ total-1
		bool repeat=false;
		for(int i=0;i<done;i++){
			if(choice==chosen[i]||choice==myNum-1){   //myNum starts from 1,choice from 0
				repeat=true;
				break;
			}
		}
		if(!repeat){
			chosen[done]=choice;
			done++;
		}
	}
}

void ReviewerAssigner::output(){
	ofstream fout("reviewer.txt");
	fout<<"   StudentNo.            Email   "<<endl;
	for(int i=0;i<3;i++){
		fout<<stuNum[chosen[i]]<<"             "<<email[chosen[i]]<<endl;
	}
	fout.close();
}
