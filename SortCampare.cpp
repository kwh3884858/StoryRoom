//
//  SortCampare.cpp
//  StoryRoom
//
//  Created by 威化饼干 on 19/12/2018.
//  Copyright © 2018 威化饼干. All rights reserved.
//

#include "SortCampare.hpp"
namespace MathLab {
    void SortCompare::Compare(const char source[],const char target[],int count){
        clock_t sTime = CalculateTime(source, count);
        clock_t tTime = CalculateTime(target, count);
        if (sTime == 0 || tTime == 0) {
            printf("Error algorithm name!");
        }
        printf("%s is %f times than %s", source,(double) sTime / tTime, target);
    }

    clock_t SortCompare::CalculateTime(const char algorithm[],int count){
        MathLab::LabArray<int> array;
        GenerateRandomNum(&array, count);

        clock_t m_startTime, m_endTime ;
        m_startTime = 0;
        m_endTime = 0;
        if(!strcmp( algorithm , "Insertion") ){
            m_startTime = clock();
            array.SortInsertion();
            m_endTime = clock();
        }
        if (!strcmp( algorithm, "Selection") ) {
            m_startTime = clock();
            array.SortSelection();
            m_endTime = clock();
        }
        if (!strcmp(algorithm, "Shell")) {
            m_startTime = clock();
            array.SortShell();
            m_endTime = clock();
        }
        if (!strcmp(algorithm, "Merge")) {
            m_startTime =clock();
            array.SortMerge();
            m_endTime = clock();
        }
        return m_endTime - m_startTime;

    }

    void SortCompare::GenerateRandomNum(MathLab::LabArray<int> * array, int count){
        srand((int)time(0));
        for (int i = 0 ; i < count; i++) {
            array->Add(rand());
        }
    }

    void SortCompare::Print(MathLab::LabArray<int> * array){
        array->Traversal(Print);
    }

    void SortCompare::Print(const int& value){
        printf("%d ", value);
    }


}

