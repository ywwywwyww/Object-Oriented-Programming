#ifndef Sorter_h__
#define Sorter_h__

class Sorter{
private:
	int size;	
public:
	
	Sorter():size{0}{}
	
	int array[100000];
	
	int s(){
		return size;
	}
	
	void generate();
	void msort(int*p,int num);
	void quicksort(int*p,int num);
	void bubblesort(int*p,int num);
};

#endif
