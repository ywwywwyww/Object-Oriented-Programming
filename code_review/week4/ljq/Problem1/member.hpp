//
//  member.hpp
//  test for C++
//
//  Created by 罗家琦 on 2020/3/16.
//  Copyright © 2020 罗家琦. All rights reserved.
//

#ifndef member_hpp
#define member_hpp

#include <iostream>
#include <string>
using namespace std;

class Member{
private:
    const string name;
    const int age;
public:
    Member(string _name="???", int _age=0):name(_name), age(_age){};
    void printInfo()const;
};

#endif /* member_hpp */
