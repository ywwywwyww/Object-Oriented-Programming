//
//  main.cpp
//  test for C++
//
//  Created by 罗家琦 on 2020/3/16.
//  Copyright © 2020 罗家琦. All rights reserved.
//


#include <iostream>
#include "member.hpp"
using namespace std;

int main()
{
    Member newMembers[5] = { Member{"Zhang San", 22}, Member{"Li Si", 19},
    Member{"Wang Wu", 18}, Member{"Zhao Liu", 24} };
    for (int i=0; i<5; i++)
        newMembers[i].printInfo();
    
    return 0;
}

