//
// Created by Nicolas Carigi on 2026-04-18.
//

#include "doctor.h"

#include <iostream>

double doctor::Calculate_Salary() {
    return baseSalary+baseSalary*performanceBonus;
}

void doctor::Print_Doctor_Info() {
    cout<<"Doctor Name: "<<docFirstName <<" "<< docLastName << endl;
    cout<<"ID: "<<docID<< endl;
    cout<<"Specialty: "<<specialty<< endl;
    cout<<"Years of experience: "<<yearsExp<< endl;
    cout<<"Base Salary:  "<<baseSalary<< endl;
    cout<<"Performance bonus: "<<performanceBonus <<"% ["<<Calculate_Salary()<<"$]"<<endl;
}

doctor::doctor(string buildDocFirstName, string buildDocLastName, long int buildDocID, string buildSpecialty, int buildYearsExp, double buildBaseSalary, double buildPerformanceBonus) {
    docFirstName=buildDocFirstName;
    docLastName=buildDocLastName;
    docID=buildDocID;
    specialty=buildSpecialty;
    yearsExp=buildYearsExp;
    baseSalary=buildBaseSalary;
    performanceBonus=buildPerformanceBonus;
}

doctor::doctor(){
    docFirstName="";
    docLastName="";
    docID=0;
    specialty="";
    yearsExp=0;
    baseSalary=0;
    performanceBonus=0;
}

// --- Getters ---
std::string doctor::getDocFirstName() {
    return docFirstName;
}

std::string doctor::getDocLastName() {
    return docLastName;
}

long int doctor::getDocID() {
    return docID;
}

std::string doctor::getSpecialty() {
    return specialty;
}

int doctor::getYearsExp() {
    return yearsExp;
}

double doctor::getBaseSalary() {
    return baseSalary;
}

double doctor::getPerformanceBonus() {
    return performanceBonus;
}

// --- Setters ---
void doctor::setDocFirstName(std::string firstName) {
    docFirstName = firstName;
}

void doctor::setDocLastName(std::string lastName) {
    docLastName = lastName;
}

void doctor::setDocID(long int id) {
    docID = id;
}

void doctor::setSpecialty(std::string spec) {
    specialty = spec;
}

void doctor::setYearsExp(int years) {
    yearsExp = years;
}

void doctor::setBaseSalary(double salary) {
    baseSalary = salary;
}

void doctor::setPerformanceBonus(double bonus) {
    performanceBonus = bonus;
}