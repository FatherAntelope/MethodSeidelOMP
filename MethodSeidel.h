//
// Created by gorbu on 12.09.2020.
//
#include <iostream>
#include <cmath>
#include "omp.h"


using namespace std;

#ifndef LR2_METHODSEIDEL_H
#define LR2_METHODSEIDEL_H


class MethodSeidel {
public: double time = 0;
public: unsigned int countIterations = 0;


public: MethodSeidel() {

}

//Не используется
public: double Sum1(int i, double ** A, double * X) {
        double sum = 0;
        for(int j = 1; j < i - 1; j++)
            sum += (A[i][j] / A[i][i]) * X[j]; //n+1 для x
        return sum;
}

//Не используется
public: double Sum2(int m, int i, double ** A, double * X) {
        double sum = 0;
        for(int j = i + 1; j < m; j++)
            sum += (A[i][j] / A[i][i]) * X[j];
        return sum;
    }

    //Не используется
public: double * initial(int N, double **A, double *B) {
        double * X = new double [N] ;
        for (int i = 0; i < N; ++i) {
            X[i] = (B[i] / A[i][i]) - Sum1(i, A, X) - Sum2(N, i, A, X);
        }
        return X;
}


//Алгоритм
public: double * buildingInitialSystemX(double** A, double* B, double epsilon, int N, int countThreads) {
        double norm = 0.0;
        countIterations = 0;
        double * X = new double[N];
        for (int i = 0; i < N; i++) {
            X[i] = 1;
        }

        time = omp_get_wtime();
        do
        {
            countIterations++;
            norm = 0.0;
            for (int i = 0; i < N; i++)
            {
                double diff = -X[i];
                double sum = 0;
#pragma omp parallel for shared(X, A, N, i) reduction(+:sum) num_threads(countThreads)
                for (int j = 0; j < N; j++)
                    if (j != i) sum += A[i][j] * X[j];
                X[i] = (B[i] - sum) / A[i][i];
                diff += X[i];
                norm += diff * diff;
            }

        } while (sqrt(norm) >= epsilon);
        time = omp_get_wtime() - time;
        return X;
    }



//Не используется
public: int partition(double* arr, int start, int end) {
        double pivot = arr[end];
        int pIndex = start;
        for (int i = start; i < end; i++) {
            if(arr[i] <= pivot) {
                swap(arr[i], arr[pIndex]);
                pIndex++;
            }
        }
        swap(arr[pIndex], arr[end]);
        return pIndex;
    }

// don't used
public: double * quicksort(double* arr, int low_index, int high_index) {
        int j;

        if (low_index < high_index) {
            j = partition(arr, low_index, high_index);
            quicksort(arr, low_index, j - 1);
            quicksort(arr, j + 1, high_index);
        }

        return arr;
    }


};


#endif //LR2_METHODSEIDEL_H
