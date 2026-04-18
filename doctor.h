//
// Created by Nicolas Carigi on 2026-04-18.
//

#ifndef FINALPROJECT_DOCTOR_H
#define FINALPROJECT_DOCTOR_H
#include <string>
using namespace std;

class doctor {
    public:
    doctor();

    private:
    string docFirstName;
    string docLastName;
    long int docID;
    string specialty;
    int YearsExp;
    double BaseSalary;
    double performanceBonus;
};


#endif //FINALPROJECT_DOCTOR_H