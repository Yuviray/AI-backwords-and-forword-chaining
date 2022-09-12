//
// Created by maldo on 9/11/2022.
//
#include "bc.h"
#include <iostream>

using namespace std;

int main(){
    string problem;
    cout << "Starting backwards chaining code...." << endl;
    bc backwards(false);
    problem.assign(backwards.start());
    cout << "Done with backwards chaining, your problem is : " << problem << endl;
    cout << endl;
    cout << "Starting forwards chaining code...." << endl;

}