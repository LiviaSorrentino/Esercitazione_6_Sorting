#include <iostream>
#include <chrono> //libreria chrono
#include "SortingAlgorithm.hpp"
#include <unistd.h>
#include <numeric> //include iota
#include <algorithm> //include generate
#include <vector>
#include <string>

using namespace std;
int main(int argc, char **argv)

{
    unsigned int size = stoi(argv[1]);
    unsigned int n = 10000;

    //confronto su vettore randomico
    double S1 = 0;
    double S2 = 0;
    for (unsigned int i=0; i<n; ++i){

        vector<int>v1(size);//creo vettore randomico
        for (unsigned int i= 0; i < size; i++){
            v1[i] = rand()%1000;

        }

        chrono::steady_clock::time_point t_begin1 = chrono::steady_clock::now();
        SortLibrary::BubbleSort(v1);
        chrono::steady_clock::time_point t_end1 = chrono:: steady_clock :: now();

        double timeElapsed1 = std::chrono::duration_cast<std::chrono::microseconds>(t_end1- t_begin1).count();
        S1 += timeElapsed1;

        chrono::steady_clock::time_point t_begin2 = chrono::steady_clock::now();
        SortLibrary::BubbleSort(v1);
        chrono::steady_clock::time_point t_end2 = chrono:: steady_clock :: now();

        double timeElapsed2 = std::chrono::duration_cast<std::chrono::microseconds>(t_end2- t_begin2).count();
        S2 += timeElapsed2;}

    double MediaBubble = S1/n;
    cout<<"Bubblesort ha impiegato mediamente "<<MediaBubble<<" ms a ordinare il vettore randomico"<<endl;
    double MediaMerge = S2/n;
    cout<<"Mergesort ha impiegato mediamente "<<MediaMerge<<" ms a ordinare il vettore randomico"<<endl;

//vettore ordinato in ordine crescente
    double S3 = 0;
    double S4 = 0;
    for (unsigned int i=0; i<n; ++i){
        vector<int>v1(size);
        for (unsigned int i = 0; i < size; ++i) {
            v1[i] = i+1;
        }
        chrono::steady_clock::time_point t_begin1 = chrono::steady_clock::now();
        SortLibrary::BubbleSort(v1);
        chrono::steady_clock::time_point t_end1 = chrono:: steady_clock :: now();

        double timeElapsed1 = std::chrono::duration_cast<std::chrono::microseconds>(t_end1- t_begin1).count();
        S3 += timeElapsed1;

        chrono::steady_clock::time_point t_begin2 = chrono::steady_clock::now();
        SortLibrary::BubbleSort(v1);
        chrono::steady_clock::time_point t_end2 = chrono:: steady_clock :: now();

        double timeElapsed2 = std::chrono::duration_cast<std::chrono::microseconds>(t_end2- t_begin2).count();
        S4 += timeElapsed2;}
    double MediaBubble1 = S3/n;
    cout<<"Bubblesort ha impiegato mediamente "<<MediaBubble1<<" ms a ordinare il vettore ordinato in ordine crescente"<<endl;

    double MediaMerge1 = S4/n;
    cout<<"Mergesort ha impiegato mediamente "<<MediaMerge1<<" ms a ordinare il vettore ordinato in ordine crescente"<<endl;

//vettore ordinato in ordine decrescente
    double S5 = 0;
    double S6 = 0;
    for (unsigned int i=0; i<n; ++i){
        vector<int>v1;
        for (unsigned int i = size; i > 0; --i){
            v1.push_back(i);
        }

        chrono::steady_clock::time_point t_begin1 = chrono::steady_clock::now();
        SortLibrary::BubbleSort(v1);
        chrono::steady_clock::time_point t_end1 = chrono:: steady_clock :: now();

        double timeElapsed1 = std::chrono::duration_cast<std::chrono::microseconds>(t_end1- t_begin1).count();
        S5 += timeElapsed1;
        chrono::steady_clock::time_point t_begin2 = chrono::steady_clock::now();
        SortLibrary::BubbleSort(v1);
        chrono::steady_clock::time_point t_end2 = chrono:: steady_clock :: now();

        double timeElapsed2 = std::chrono::duration_cast<std::chrono::microseconds>(t_end2- t_begin2).count();
        S6 += timeElapsed2;}
    double MediaBubble2 = S5/n;
    cout<<"Bubblesort ha impiegato mediamente "<<MediaBubble2<<" ms a ordinare il vettore ordinato in ordine decrescente"<<endl;

    double MediaMerge2 = S6/n;
    cout<<"Mergesort ha impiegato mediamente "<<MediaMerge2<<" ms a ordinare il vettore ordinato in ordine decrescente"<<endl;


    //vettore ordinato in ordine crescente a metà
    double S7 = 0;
    double S8 = 0;
    for (unsigned int i=0; i<n; ++i){
        vector<int>v1(size);
        iota(v1.begin(),v1.end(), 0);
        for (unsigned int i=0; i<v1.size()/2;i++){
            v1[i] = rand() % (v1.size()/2);
        }
        chrono::steady_clock::time_point t_begin1 = chrono::steady_clock::now();
        SortLibrary::BubbleSort(v1);
        chrono::steady_clock::time_point t_end1 = chrono:: steady_clock :: now();

        double timeElapsed1 = std::chrono::duration_cast<std::chrono::microseconds>(t_end1- t_begin1).count();
        S7 += timeElapsed1;

        chrono::steady_clock::time_point t_begin2 = chrono::steady_clock::now();
        SortLibrary::BubbleSort(v1);
        chrono::steady_clock::time_point t_end2 = chrono:: steady_clock :: now();

        double timeElapsed2 = std::chrono::duration_cast<std::chrono::microseconds>(t_end2- t_begin2).count();
        S8 += timeElapsed2;}
    double MediaBubble3 = S7/n;
    cout<<"Bubblesort ha impiegato mediamente "<<MediaBubble3<<" ms a ordinare il vettore ordinato in ordine crescente dalla seconda metà"<<endl;

    double MediaMerge3 = S8/n;
    cout<<"Mergesort ha impiegato mediamente "<<MediaMerge3<<" ms a ordinare il vettore ordinato in ordine crescente dalla seconda metà"<<endl;


    return 0;
}

