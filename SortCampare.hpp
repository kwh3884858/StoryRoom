//
//  SortCampare.hpp
//  StoryRoom
//
//  Created by 威化饼干 on 19/12/2018.
//  Copyright © 2018 威化饼干. All rights reserved.
//

#ifndef SortCampare_hpp
#define SortCampare_hpp

#include <stdio.h>
#include <string>
#include "MathLab.hpp"
#include "time.h"
//using namespace std;
namespace MathLab {
    const char Insertion[] = "Insertion";
    const char Selection[] = "Selection";
    const char Shell[] = "Shell";

    class SortCompare{

    public:
        SortCompare();
        ~SortCompare();
        static void Compare (const char source[] ,const char target[], int count);
        static clock_t CalculateTime(const char algorithm[],int count);
        static void GenerateRandomNum( MathLab::LabArray<int> * array, int count);
    };
}


#endif /* SortCampare_hpp */
