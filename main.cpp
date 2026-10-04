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


double variance(double* arr, int size);

double stdev(double* arr, int size);

double average(double* arr, int size);

double sum(const double* arr, int size);

double std_error(const double *arr, int size);

double median(double* arr, int size);

double MIN(double* arr, int size);

double MAX(double* arr, int size);
double ans = 0;
double arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
double arr2[7] = {7, 3, 2, 1, 5, 6, 4};
int main() {
    ans = median(arr2,7);
    cout << ans << endl;
    return 0;
}


double average(const double* arr, int size) {
    double total = sum(arr, size);
    return total / size;
}

double stdev(const double* arr, int size) {
    double sos = 0;
    double st_dev;
    double mean = average(arr, size);
    int type;
    for (int i = 0; i < size; i++) {
        sos +=( (arr[i] - mean) * (arr[i] - mean));
    }
    cout << "Which type, Population (0) or Sample (1)?";
    cin >> type;
    if (type == 0)
        st_dev = sqrt(sos / size);
    else
        st_dev = sqrt(sos / (size-1));

    return st_dev;
}

double variance(const double* arr, int size) {
    double sos = 0;
    double variance = 0;
    double mean = average(arr, size);
    int type;
    for (int i = 0; i < size; i++) {
        sos +=( (arr[i] - mean) * (arr[i] - mean));
    }
    cout << "Which type, Population (0) or Sample (1)?";
    cin >> type;
    if (type == 0)
        variance = (sos / size);
    else
        variance = (sos / (size-1));
    return variance;
}

double sum(const double* arr, int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}
double std_error(const double* arr, int size) {
    double st_dev = stdev(arr, size);
    return st_dev/sqrt(size);
}
double median(const double* arr, int size) {
    double dummy[size];
    bool swapped;
    //Loading a dummy array so as not to touch the original
    for (int i = 0; i < size; i++) {
        dummy[i] = arr[i];
    }
    //bubble sorting algorithm; checks each number against each number after it).
    for (int i = 0; i < size; i++) {
        swapped = false;
        for (int i = 0; i < size; i++) {
            if (dummy[i] < dummy[i+1]) {
                swap(dummy[i], dummy[i+1]);
                swapped = true;
            }
        }
        if (!swapped)
        break;
    }
    if (size % 2 == 1)
         return double(dummy[(size-1)/2]);
    else
         return double(dummy[size/2] + dummy[(size - 2)/2])/ 2;
    }
double MAX(const double* arr, int size) {
    double Maximum = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[i-1])
            Maximum = arr[i];
    return Maximum;
    }
}
double MIN(const double* arr, int size) {
    double Minimum = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i-1])
            Minimum = arr[i];
        return Minimum;
    }
}
int Max_index(const double* arr, int size) {
    int index = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[i-1])
            index = i;
        return index;
    }
}
int Min_index(const double* arr, int size) {
    int index = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[i-1])
            index = i;
        return index;
    }
}
int spec_index(const double* arr, int size, double val) {
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == val)
        index = i;
    }
    return index;
}
double peak_2_peak(const double* arr, int size) {
    return MAX(arr, size) - MIN(arr, size);
}
double derivative(const double* arr, int size, double time_step) {
    
}