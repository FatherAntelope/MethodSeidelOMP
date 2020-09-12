//
// Created by gorbu on 12.09.2020.
//
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#ifndef LR2_FILETRANSFER_H
#define LR2_FILETRANSFER_H

using namespace std;

class FileTransfer {
    private: string filePath;

    public:FileTransfer(string filePath) {
        this->filePath = filePath;
    }

    public: void initData(int & N, double & epsilon, double ** &A, double * &B) {
        string textLine;
        ifstream init(filePath);

        if (init.is_open()) {
            int lineNumber = 0;
            while (getline(init, textLine)) {
                lineNumber++;
                stringstream textPiece(textLine);
                if (lineNumber == 1) {
                    textPiece >> N;
                    textPiece >> epsilon;
                    A = new double *[N];
                    B = new double[N];
                } else if (lineNumber == 2) {
                    int i = 0;
                    while (!textPiece.eof()) {
                        textPiece >> B[i++];
                    }
                } else {
                    int i = 0;
                    A[lineNumber - 3] = new double[N];
                    double number = 0;
                    while (!textPiece.eof()) {
                        textPiece >> number;
                        A[lineNumber - 3][i] = number;
                        i++;
                    }
                }
            }
        }
    }

    public: void outData(string nameFileOut, double * numberIterations, double solutionApproximate, time_t timeJob) {

    }
};


#endif //LR2_FILETRANSFER_H
