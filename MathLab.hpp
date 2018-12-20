//
//  MathLab.hpp
//  StoryRoom
//
//  Created by 威化饼干 on 6/12/2018.
//  Copyright © 2018 威化饼干. All rights reserved.
//

#ifndef MathLab_hpp
#define MathLab_hpp

#include <stdio.h>
#include <vector>
namespace MathLab {
    template<typename T>
    class LabArray{

        int CAPACITY = 4 ;
        int length = 0 ;
        T* m_sort;


    public:

        LabArray();
        LabArray(int count);

        void Swap(int i, int j);
        void Add(const T& t);
        inline bool IsLess(const T& source, const T& target) const;
//        inline int Length()const;

        void SortSelection();
        void SortInsertion();
        void SortShell();

        void Traversal(void( *callback)(const T & ))const;

        static void SortSelection(T* array);

        ~LabArray();
    };


    template <typename T>
    MathLab::LabArray<T>::LabArray() {
        m_sort = nullptr;
    }

    template <typename T>
    MathLab::LabArray<T>::LabArray(int count) {
        m_sort = new T[count];
    }

    //template <typename T>
    //inline int MathLab::LabArray<T>::Length() const {
    //    if (m_sort == nullptr) {
    //        return 0;
    //    }
    //    int size = sizeof(m_sort);
    //    return size;
    //}

    //a class must implement copy constructor
    template <typename T>
    void MathLab::LabArray<T>::Swap(int i, int j){
        T temp = m_sort[i];
        m_sort[i] = m_sort[j];
        m_sort[j] = temp;
    }

    template <typename T>
    void MathLab::LabArray<T>::Add(const T& t){
        if(length == 0){
            m_sort = new T[CAPACITY];
        }
        if (length == CAPACITY) {
            T* temp = m_sort;
            CAPACITY *= 2;
            m_sort = new T[CAPACITY];

            for (int i = 0 ; i < length; i++) {
                m_sort[i] = temp[i];
            }
        }
        m_sort[length] = t ;
        length++;
    }

    template<typename T>
    inline bool MathLab::LabArray<T>::IsLess(const T& source, const T& target) const{
        if (source < target) {
            return true;
        }else{
            return false;
        }
    }

    template <typename T>
    void MathLab::LabArray<T>::SortSelection() {
        for (int i = 0 ; i < length ; i++) {
            unsigned int min = i ;
            for (int j = i+1 ; j < length; j++) {
                if (m_sort[j] < m_sort[min]) {
                    min = j;
                }
            }
            Swap(i, min);
        }
    }

    template <typename T>
    void MathLab::LabArray<T>::SortInsertion() {

        for (int i = 1 ; i < length ; i++) {
            for (int j = i ; j > 0 && IsLess(m_sort[ j ], m_sort[ j - 1 ]) ; j--) {
                Swap(j-1, j);
            }
        }
    }

    template <typename T>
    void MathLab::LabArray<T>::SortShell() {
        int interval = 1;
        while (interval < length / 3) {
            interval = interval * 3 + 1;
        }

        while(interval > 0 ){

            for (int i = interval ; i < length; i += interval) {
                for (int j = i; j >= 0 && IsLess(m_sort[ j ], m_sort[ j - interval ]) ; j -= interval) {
                    Swap(j - interval, j);
                }
            }
            interval /= 3 ;
        }
    }

    template <typename T>
    void MathLab::LabArray<T>::Traversal(void( *callback)(const T & ))const {

        for (int i = 0 ; i < length; i++) {
            callback(m_sort[i]);
        }
    }

    template <typename T>
    MathLab::LabArray<T>::~LabArray() {
        if (m_sort != nullptr) {
            delete [] m_sort;
        }
    }
}


#endif /* MathLab_hpp */
