#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "FileTransfer.h"
#include "MethodSeidel.h"

using namespace std;
/**
 * critical
 * atomic как и critical, но выполняет только 1 команду
 * lock() позволяет составлять закрытые области
 * flush позволяет переписывать общие переменные и их передавать
 */






int main() {
    int N = 0;
    double epsilon = 0.0;
    double ** A = nullptr;
    double * B = nullptr;
    cout.setf(ios::fixed);

    FileTransfer * fileTransfer = new FileTransfer("D:\\cpp\\lr2\\input2_00.txt");
    fileTransfer->initData(N, epsilon, A, B);

    MethodSeidel * methodSeidel = new MethodSeidel(A, B, epsilon, N);




    cout << "N: " << N << endl;
    cout << "Epsilon: " << epsilon << endl;
    cout << "B: ";
    for(int i = 0; i < N; i++) {
        cout << B[i] << " ";
    }

    cout << endl << "A: ";
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
