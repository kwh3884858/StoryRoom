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
    MathLab::LabArray<int>* array = new LabArray<int>();
    SortCompare::GenerateRandomNum(array, 5);
    SortCompare::Print(array);
    array->SortMerge();
    std::cout << "\n";
    SortCompare::Print(array);
//    SortCompare::Compare(Shell, Selection, 200);

    return 0;
}
