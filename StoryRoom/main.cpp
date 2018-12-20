//
//  main.cpp
//  StoryRoom
//
//  Created by 威化饼干 on 6/12/2018.
//  Copyright © 2018 威化饼干. All rights reserved.
//

#include <iostream>
#include "../SortCampare.hpp"
using namespace MathLab;
void print(const int&);
int main(int argc, const char * argv[]) {

    SortCompare::Compare(Shell, Selection, 200);

    return 0;
}
void print(const int& value){
    printf("%d ", value);
}
