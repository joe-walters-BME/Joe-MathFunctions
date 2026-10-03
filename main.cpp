#include <iostream>
#include <cmath>
//File name: main.cpp
//Author: Joe Walters
//6+2: waltejp
//Email: waltejp@mail.uc.edu
//Class: BME 5102/6002
//Date: 10/1/2026
//Link to GitHub Repository:
//Honor statement: I certify that I have neither given nor received
// unauthorized aid on this assignment and will not
// share my code with anyone after this semester. I
// certify that I did not use ChatGPT, BearcatGPT
// Gemini, JetBrains AI, or any other AI, LLM, etc.
// to complete any part of this assignment.
//
//Description: //

using namespace std;
double arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

double variance(double* arr, int size);

double stdev(double* arr, int size);

double average(double* arr, int size);

double sum(const double* arr, int size);

double ans = 0;

int main() {
    ans = variance(arr,10);
    cout << ans << endl;
    return 0;
}


double average(double* arr, int size) {
    double total = sum(arr, size);
    return total / size;
}

double stdev(double* arr, int size) {
    double sos = 0;
    double st_dev;
    double mean = average(arr, size);
    int type;
    for (int i = 0; i < size; i++) {
        sos +=( (arr[i] - mean) * (arr[i] - mean));
    cout << "Which type, Population (0) or Sample (1)?";
    cin >> type;
    if (type == 0)
        st_dev = sqrt(sos / size);
    else
        st_dev = sqrt(sos / (size-1));
    }
    return st_dev;
}

double variance(double* arr, int size) {
    double sos = 0;
    double variance;
    double mean = average(arr, size);
    int type;
    for (int i = 0; i < size; i++) {
        sos +=( (arr[i] - mean) * (arr[i] - mean));
        cout << "Which type, Population (0) or Sample (1)?";
        cin >> type;
        if (type == 0)
            variance = (sos / size);
        else
            variance = (sos / (size-1));
    }
    return variance;
}

double sum(const double* arr, int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}
