#ifndef RA_h__
#define RA_h__

class ReviewerAssigner{
private:
	int myNum;       //position of my number in the list
	int total;       //number of students
	int stuNum[100];
	char email[100][100];
	int chosen[3];   //positions in the list
public:
	ReviewerAssigner()=default;
	ReviewerAssigner(int num);
	
	void load();
	void choose();
	void output();	
};

#endif
