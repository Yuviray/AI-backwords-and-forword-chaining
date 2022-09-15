
//
// Created by maldo on 9/11/2022.
//
#include "bc.h"
#include "fc.h"
#include <iostream>

using namespace std;

int main(){
    string problem;
    string solution;

    cout << "Starting backwards chaining code....\n" << endl;

    bc backwards;
    problem.assign(backwards.start());

    cout << "Done with backwards chaining, your problem is : \n" << problem << endl;
    cout << "Starting forwards chaining code....\n" << endl ;

    fc forwards(problem);
    solution.assign(forwards.start());

    cout << "To fix you need to " << solution << " " << problem << endl;

}
