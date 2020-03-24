#ifndef PROBLEM1_MEMBER_H_
#define PROBLEM1_MEMBER_H_

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

class Member {
	const std::string name;
	const int age;
	public:
		Member(const std::string &name_="???",const int &age=0);//The default name is "???" and default age is 0
		void printInfo() const;
		~Member()=default;
};

#endif
