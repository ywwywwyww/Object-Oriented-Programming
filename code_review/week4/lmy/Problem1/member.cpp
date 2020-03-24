#include "member.h"

#include <cstring>
#include <iostream>
#include <string>

Member::Member(const std::string &name_,const int &age_): name{name_}, age{age_} {}

void Member::printInfo() const {
	std::cout<<name<<" "<<age<<std::endl;//Output the name and age
}
