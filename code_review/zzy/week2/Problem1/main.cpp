#include<iostream>
#include"func.h"
#include"timer.h"
using namespace std;

int main(int argc,char**argv){   
	double*a=new double[argc-2];   //argc==n+2
	for(int i=0;i<argc-2;i++){
		a[i]=atof(argv[i+1]);
	}
	
	Timer t{};
	
	t.start();
	double result=Dpoly(a,argc-2,atof(argv[argc-1]));
	t.stop();
	cout<<endl<<"result of polynomial:"<<result<<endl<<endl;
	double oldt=t.time();
	cout<<"direct computation runtime(10^8 times):"<<oldt<<endl;	
	t.reset();
	
	t.start();
	result=Qpoly(a,argc-2,atof(argv[argc-1]));
	t.stop();
	double newt=t.time();
	cout<<"runtime using Qinjiushao's algorithm(10^8 times):"<<newt<<endl;	
	t.reset();
	cout<<"improvement:"<<(oldt-newt)*100/oldt<<"%"<<endl<<endl;
	
	t.start();
	result=Dposy(a,argc-2,atof(argv[argc-1]));
	t.stop();
	cout<<"result of posynomial:"<<result<<endl<<endl;	
	oldt=t.time();
	cout<<"direct computation runtime(10^8 times):"<<oldt<<endl;
	t.reset();
	
	t.start();
	result=Qposy(a,argc-2,atof(argv[argc-1]));
	t.stop();
	newt=t.time();
	cout<<"runtime using Qinjiushao's algorithm(10^8 times):"<<newt<<endl<<endl;
	t.reset();
	cout<<"improvement:"<<(oldt-newt)*100/oldt<<"%"<<endl<<endl;
	
	delete []a;
	return 0;
}
