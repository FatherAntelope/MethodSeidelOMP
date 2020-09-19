#include <iostream>
#include <string>
#include "FileTransfer.h"
#include "MethodSeidel.h"
#include <cmath>

using namespace std;
/**
 * critical
 * atomic как и critical, но выполняет только 1 команду
 * lock() позволяет составлять закрытые области
 * flush позволяет переписывать общие переменные и их передавать
 */

int N;
double epsilon;
double** A;
double *X;
double * B;
double * times;


void result(int numberFile) {
    stringstream strNumberFile;
    strNumberFile << numberFile;

    FileTransfer* fileTransfer = new FileTransfer("D:\\cpp\\lr2\\");
    fileTransfer->initData(N, epsilon, A, B, "input2_" + strNumberFile.str() + ".txt");

    MethodSeidel* methodSeidel = new MethodSeidel();


    cout << "N: " << N << endl;
    cout << "Epsilon: " << epsilon << endl;
    int i = 0;
    X = methodSeidel->buildingInitialSystemX(A, B, epsilon, N, pow(2, i));
    cout <<"Time(" << pow(2, i) <<  "): " << methodSeidel->time << "s" << endl;

    i = 1;
    X = methodSeidel->buildingInitialSystemX(A, B, epsilon, N, pow(2, i));
    cout <<"Time(" << pow(2, i) <<  "): " << methodSeidel->time << "s" << endl;

    i = 2;
    X = methodSeidel->buildingInitialSystemX(A, B, epsilon, N, pow(2, i));
    cout <<"Time(" << pow(2, i) <<  "): " << methodSeidel->time << "s" << endl;

    i = 3;
    X = methodSeidel->buildingInitialSystemX(A, B, epsilon, N, pow(2, i));
    cout <<"Time(" << pow(2, i) <<  "): " << methodSeidel->time << "s" << endl;


    fileTransfer->outData(X, N,  methodSeidel->countIterations, times, "output2_" + strNumberFile.str() + ".txt");
}

int main() {
    N = 0;
    epsilon = 0.0;
    A = nullptr;
    X = nullptr;
    B = nullptr;
    times = new double[4];
    //cout.setf(ios::fixed);

    result(6);






/*
    cout << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
     */



    return 0;
}
