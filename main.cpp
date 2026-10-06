#include <iostream>
#include <cmath>
#include "ttestTable.h"

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
//@param1 arr - array
//@param2 size - size of the array
//@return - variance of the array
//@brief -  Calculates the variance of the array
double variance(const double* arr, int size, int PoS = 0);

//@param1 arr - array
//@param2 size - size of the array
//@return - Std. Deviation of the array
//@brief -  Calculates the Std dev of the array, prompting the user whether they want sample
//          or population
double stdev(const double* arr, int size, int PoS = 0);

//@param1 arr - array
//@param2 size - size of the array
//@return - Average of the array
//@brief -  Calculates the average of the array
double average(const double* arr, int size);

//@param1 arr - array
//@param2 size - size of the array
//@return - Sum of the array
//@brief -  Calculates the sum of the array
double sum(const double* arr, int size);

//@param1 arr - array
//@param2 size - size of the array
//@return - standard error of the mean  of the array
//@brief -  Calculates the standard error of the mean of the array
double std_error(const double *arr, int size);

//@param1 arr - array
//@param2 size - size of the array
//@return - Median of the array
//@brief -  Sorts the array using bubble sort (more on that later, I suppose) then returns the median of the array
double median(const double* arr, int size);

//@param1 arr - array
//@param2 size - size of the array
//@return - Minimum value of the array
//@brief -  Sorts through and finds the smallest value of the array
double MIN(const double* arr, int size);

//@param1 arr - array
//@param2 size - size of the array
//@return - Maximum value of the array
//@brief -  Sorts through and finds the largest value of the array
double MAX(const double* arr, int size);

//@param1 arr - array
//@param2 size - size of the array
//@return - Position of the largest value of the array
//@brief -  Sorts through and finds the index of the largest value of the array
int Max_index(const double* arr, int size);

//@param1 arr - array
//@param2 size - size of the array
//@return - Position of the smallest value of the array
//@brief -  Sorts through and finds the index of the smallest value of the array
int Min_index(const double* arr, int size);

//@param1 arr - array
//@param2 size - size of the array
//@param3 val - the value in question
//@return - index of the speficied value
//@brief -  Sifts through the array, and finds the index of the value in question. Returns -1 if it's not in there.
int spec_index(const double* arr, int size, double val);

//@param1 arr - array
//@param2 size - size of the array
//@param3 ddx - blank array
//@return - none
//@brief -  Calculates the difference between each term and the next in the input array.
//          Writes the result to the ddx array
void calcDerivative(const double arr[], const int samples, double ddx[]);

//@param1 arr - array
//@param2 size - size of the array
//@return - Peak to peak value
//@brief -  Returns the range (max-min)
double peak_2_peak(const double* arr, int size);

//@param1 arr - array
//@param2 samples - size of the array
//@param3 time step - Width of the rectangles. Defaults to 1 if unspecified
//@return - Approximate area under the curve
//@brief -  Uses the sum of rectangles to approximate the area under the curve
double calculateIntegral(const double arr[], const int samples, float time_step = 1);

//@param1 arr1 - the first array
//@param2 arr2 - the second array
//@param3 size1 - the size of the first array
//@param4 size2 - the size of the second array
//@return - True or false- significant or not significant
//@brief -  Performs a paired t-test by calculating the T-statistic, DOF, and consulting the ttestTable.h library.
bool ttest(const double arr1[], const double arr2[], const int size1, const int size2);

//@param1 arr - array
//@param2 samples - size of the array
//@return - Root mean square of the samples
//@brief -  Calculates the root mean square of the samples
double rootmeansquare(const double arr[], const int samples);

double ddx[10]={};
double ans = 0;
double arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
double arr2[10] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
double arr3[10] = {1.1, 1.8, 3.2, 4.1, 4.9, 6.2, 6.8, 8.3, 9.1, 10.2};

int main() {
    //Sum
    cout<<"Sum: "<<sum(arr,10)<<endl;
    //Average
    cout<<"Average: "<<average(arr,10)<<endl;
    //St.dev
    cout<<"Standard Deviation (Population): "<<stdev(arr,10,0)<<endl;
    cout<<"Standard Deviation (Sample): "<<stdev(arr,10,1)<<endl;
    //Variance
    cout<<"Variation (Population): "<<variance(arr,10,0)<<endl;
    cout<<"Variation (Sample): "<<variance(arr,10,1)<<endl;
    //SEM
    cout<<"Standard Error of the Mean: "<<std_error(arr,10)<<endl;
    //Median
    cout<<"Median: "<<median(arr,10)<<endl;
    //Max
    cout<<"Maximum: "<<MAX(arr,10)<<endl;
    //Min
    cout<<"Minimum: "<<MIN(arr,10)<<endl;
    //Max Index
    cout<<"Index of Max: "<<Max_index(arr,10)<<endl;
    //Min Index
    cout<<"Index of Min: "<<Min_index(arr,10)<<endl;
    //Specific Index
    cout<<"Specific index (of 5, for this demo): "<<spec_index(arr,10,5)<<endl;
    //Peak-to-Peak
    cout<<"Peak-to-Peak Value: "<<peak_2_peak(arr,10)<<endl;
    //Derivative
    cout<<"Derivatives: ";
    calcDerivative(arr,10,ddx);
    for (int i = 0; i < 10; i++) {
        cout<<ddx[i]<<" ";
    }
    cout<<endl;
    //Integral
    cout<<"Integral: "<<calculateIntegral(arr,10,1)<<endl;
    //Root Mean Square
    cout<<"Root Mean: "<<rootmeansquare(arr,10)<<endl;
    //T-Test:
    cout<<"First Comparison: ";
    for (int i = 0; i < 10; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"vs.";
    for (int i = 0; i < 10; i++) {
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    if (ttest(arr, arr2, 10, 10) == 1)
        cout<<"Significantly different";
    else {
        cout<<"No significant difference";
    }
    cout<<"Second Comparison: ";
    for (int i = 0; i < 10; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"vs. ";
    for (int i = 0; i < 10; i++) {
        cout<<arr3[i]<<" ";
    }
    cout<<endl;
    if (ttest(arr, arr3, 10, 10) == 1)
        cout<<"Significantly different";
    else {
        cout<<"No significant difference";
    }
    // bool first_comp = true;
    // bool second_comp = false;
    // first_comp = ttest(arr, arr2, 10, 10);
    // second_comp = ttest(arr, arr3, 10, 10);
    // cout << first_comp << endl;
    // cout << second_comp << endl;
    return 0;
}


double average(const double* arr, int size) {
    double total = sum(arr, size);
    return total / size;
}

double stdev(const double* arr, int size, int PoS) {
    double sos = 0;
    double st_dev;
    double mean = average(arr, size);
    int type;
    for (int i = 0; i < size; i++) {
        sos +=( (arr[i] - mean) * (arr[i] - mean));
    }
    if (PoS == 0)
        st_dev = sqrt(sos / size);
    else
        st_dev = sqrt(sos / (size-1));

    return st_dev;
}

double variance(const double* arr, int size, int PoS) {
    double sos = 0;
    double variance = 0;
    double mean = average(arr, size);
    int type;
    for (int i = 0; i < size; i++) {
        sos +=( (arr[i] - mean) * (arr[i] - mean));
    }
    if (PoS == 0)
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
    }
    return Maximum;
}
double MIN(const double* arr, int size) {
    double Minimum = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i-1])
            Minimum = arr[i];
    }
    return Minimum;
}
int Max_index(const double* arr, int size) {
  int index = 0;
   for (int i = 1; i < size; i++) {
         if (arr[i] > arr[i-1])
            index = i;
    }
    return index;
}
int Min_index(const double* arr, int size) {
    int index = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i-1])
            index = i;
    }
    return index;
}
int spec_index(const double* arr, int size, double val) {
    int index = 0;
    bool FOUND = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == val)
        index = i;
        FOUND = true;
    }
    if (FOUND!=true) {
        index = -1;
    }
    return index;
}
double peak_2_peak(const double* arr, int size) {
    return MAX(arr, size) - MIN(arr, size);
}
void calcDerivative(const double arr[], const int samples, double ddx[]){
    ddx[0]=0;
    for (int i = 1; i < samples; i++) {
        ddx[i]=arr[i]-arr[i-1];
    }
}
double calculateIntegral(const double arr[], const int samples, float time_step) {
    double sum = 0;
    for (int i = 1; i < samples; i++) {
        sum += (arr[i] - arr[i-1])*time_step;
    }
    return sum;
}

double rootmeansquare(const double arr[], const int samples) {
    double sos = 0;
    for (int i = 0; i < samples; i++) {
        sos += (arr[i])*arr[i];
    }
    return sqrt((1/samples)*sos);
}

bool ttest(const double arr1[], const double arr2[], const int size1, const int size2) {
    bool signif;
    double diffs[size1] = {0};
    int DOF = size1-1;
    double difftotal = 0;
    for (int i = 0; i < size1; i++) {
        diffs[i] = arr2[i] - arr1[i];
        difftotal += diffs[i];
    }
    double diffmean = difftotal / (size1);
    double diff_sos = 0;
    for (int i = 0; i < size1; i++) {
         diff_sos += (diffs[i] - diffmean) * (diffs[i] - diffmean);
    }
    double diffstd = sqrt(diff_sos / (size1-1));
    double SE_d = diffstd/sqrt(size1);
    double t_stat = diffmean/SE_d;
    if (t_stat > alpha95[DOF])
        signif = true;
    else
        signif = false;
    return signif;
}