#include <iostream>
#include <string>
#include "FileTransfer.h"
#include "MethodSeidel.h"
#include <cmath>
#include <Windows.h>
#include "omp.h"

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
    //Отправляем директорию на считывание
    stringstream strNumberFile;
    strNumberFile << numberFile;
    FileTransfer* fileTransfer = new FileTransfer("D:\\cpp\\lr2\\");

    //Инициализирует переменные из файла(по номеру, переданной в функции) заданной директории
    fileTransfer->initData(N, epsilon, A, B, "input2_" + strNumberFile.str() + ".txt");


    MethodSeidel* methodSeidel = new MethodSeidel();


    cout << "N: " << N << endl;
    cout << "Epsilon: " << epsilon << endl;

    //Вся прелесть здесь (можно и без Sleep)
    int i = 0;
    X = methodSeidel->buildingInitialSystemX(A, B, epsilon, N, pow(2, i));
    cout <<"Time(" << pow(2, i) <<  "): " << methodSeidel->time << "s" << endl;
    times[i] = methodSeidel->time;
    methodSeidel->time = 0;
    Sleep(1000);
    i++;

    X = methodSeidel->buildingInitialSystemX(A, B, epsilon, N, pow(2, i));
    cout <<"Time(" << pow(2, i) <<  "): " << methodSeidel->time << "s" << endl;
    times[i] = methodSeidel->time;
    methodSeidel->time = 0;
    Sleep(1000);
    i++;


    X = methodSeidel->buildingInitialSystemX(A, B, epsilon, N, pow(2, i));
    cout <<"Time(" << pow(2, i) <<  "): " << methodSeidel->time << "s" << endl;
    times[i] = methodSeidel->time;
    methodSeidel->time = 0;
    Sleep(1000);
    i++;


    X = methodSeidel->buildingInitialSystemX(A, B, epsilon, N, pow(2, i));
    cout <<"Time(" << pow(2, i) <<  "): " << methodSeidel->time << "s" << endl;
    times[i] = methodSeidel->time;
    methodSeidel->time = 0;

    //Запись результатов в файл
    fileTransfer->outData(X, N,  methodSeidel->countIterations, times, "output2_" + strNumberFile.str() + ".txt");
}

int main() {
    N = 0;
    epsilon = 0.0;
    A = nullptr;
    X = nullptr;
    B = nullptr;
    times = new double[4];

    result(8);




    return 0;
}
