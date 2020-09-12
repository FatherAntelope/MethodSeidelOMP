//
// Created by gorbu on 12.09.2020.
//
#include <iostream>

using namespace std;

#ifndef LR2_METHODSEIDEL_H
#define LR2_METHODSEIDEL_H


class MethodSeidel {
    private: double ** A = nullptr;
    private: double * B = nullptr;
    private: double * X = nullptr;
    private: double epsilon;
    private: int N;

    public: MethodSeidel(double ** A, double * B, double epsilon, double  N) {
        this->A = A;
        this->B = B;
        this->epsilon = epsilon;
        this->N = N;
        X = new double[N] {0};
    }

    private: double sumOne(int i, int j) {
        double sum = 0.0f;

        for(; j < i - 1; j++) {
            sum += (A[i][j] / A[i][i]) / X[j];
        }
        
        return sum;
    }

    private: double sumTwo(int i, int j) {
        double sum = 0.0f;

        for(; j < N; j++) {
            sum += (A[i][j] / A[i][i]) / X[j];
        }

        return sum;
    }
};


#endif //LR2_METHODSEIDEL_H
