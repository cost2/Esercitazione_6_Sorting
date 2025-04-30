#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {
	template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> std::convertible_to<bool>;
};


template <Sortable T>
void BubbleSort(std::vector<T>& v)
{
    unsigned int n = v.size();

    bool scambio = true;   

    while (scambio){
        scambio = false;   
        for(unsigned int i = 0; i < n-1; i++)
        {
            // swap
            if(v[i]>v[i+1]) {
                scambio = true;   
                T tmp = v[i];
                v[i] = v[i+1];
                v[i+1] = tmp;
                
            }

        }
        n--;   
    }
};



template<typename T>
void heapify(std::vector<T>& v, unsigned int n, unsigned int i) {
    unsigned int mag_index = i;     
    unsigned int sin_index = 2*i+1;   
    unsigned int des_index = 2*i+2;   

    
    if (sin_index < n && v[sin_index]>v[mag_index])
	{
        mag_index = sin_index;
    }

 
    if(des_index <n && v[des_index]>v[mag_index]){
        mag_index = des_index;
    }

  
    if(mag_index != i) {
        T tmp = v[i];
        v[i] = v[mag_index];
        v[mag_index] = tmp;
        heapify(v, n, mag_index);   
    }
};



template<Sortable T>
void HeapSort(std::vector<T>& v)
{

    const unsigned int n = v.size();

    
    for (int i= n/2 -1 ; i >= 0 ; i--){
        heapify(v,n,i);
    }

    for (unsigned int i = n - 1; i > 0; i--)
    {
        
        T tmp = v[i];
        v[i] = v[0];
        v[0] = tmp;

        heapify(v, i, 0);    
    }

};

}


