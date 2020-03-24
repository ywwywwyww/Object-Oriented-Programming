#include"func.h"
#include<iostream>
using namespace std;

//direct computation of polynomial
double Dpoly(double*a,int n,double x){ 
	double res=a[0];
	for(int k=1;k<=10000000;k++){
		res=a[0];
		for(int i=1;i<n;i++){
			double term=a[i];
			for(int j=1;j<=i;j++){
				term*=x;
			}
			res+=term;
		}
	}
	return res;
}

//using Qinjiushao's algorithm
double Qpoly(double*a,int n,double x){
	double res=a[n-1];
	for(int k=1;k<=10000000;k++){
		res=a[n-1];
		for(int i=n-2;i>=0;i--){		
			res*=x;
			res+=a[i];
		}
	}
	return res;
}
