#include <fstream>
#include <iostream>
#include <ostream>
#include <format>
#include <chrono>
#include "patient.h"


using namespace std;

string patient::Patient_Status() {
    if (diagnosis.find("critical") != std::string::npos) {
        return "Critical";
    }
    if (diagnosis.find("moderate") != std::string::npos) {
        return "Moderate";
    }
    else {
        return "Stable";
    }
}

void patient::Print_Patient_Info() {
    cout<<"Patient Name: "<<firstName <<" "<< lastName << endl;
    cout<<"ID: "<<patientID<< endl;
    if (assignedDoctorID <= 0) {
        cout<<"Assigned doctor: No doctor assigned"<< endl;
    }
    else {
        cout<<"Assigned doctor: ["<<assignedDoctorID<<"]"<< endl;
    }
    cout<<"Date of birth: "<<DOB<< endl;
    cout<<"Blood type: "<<bloodType<< endl;
    cout<<"Diagnosis: "<<diagnosis<< endl;
    cout<<"Date of Admission: "<<admitDate<< endl;
    cout<<"Discharge date: "<<dischargeDate<< endl;
}

double patient::calculateAge() {
    auto now = chrono::system_clock::now();

    int currentDateYYYYMMDD=stoi(format("{:%Y%m%d}", now));

    // Convert the DOB string to an integer
    double dobInt = std::stoi(DOB);

    // Calculate and return the age
    return (currentDateYYYYMMDD - dobInt) / 10000;
}

patient::patient(std::string buildFirstName,std::string buildLastName,long int buildPatientID,long int buildAssignedDoctorID,
    std::string buildDOB,std::string buildBloodType,std::string buildDiagnosis,std::string buildAdmitDate,
    std::string buildDischargeDate) {
    firstName = buildFirstName;
    lastName = buildLastName;
    patientID = buildPatientID;
    assignedDoctorID = buildAssignedDoctorID;
    DOB = buildDOB;
    bloodType = buildBloodType;
    diagnosis = buildDiagnosis;
    admitDate = buildAdmitDate;
    dischargeDate = buildDischargeDate;
}

patient::patient() {
    firstName = "";
    lastName = "";
    patientID = 0;
    assignedDoctorID = 0;
    DOB = "";
    bloodType = "";
    diagnosis = "";
    admitDate = "";
    dischargeDate = "";
}


string patient::getFirstName() {
    return firstName;
}
string patient::getLastName() {
    return lastName;
}
long int patient::getPatientID() {
    return patientID;
}
long int patient::getAssignedDoctorID() {
    return assignedDoctorID;
}
string patient::getDOB() {
    return DOB;
}
string patient::getBloodType() {
    return bloodType;
}
string patient::getDiagnosis() {
    return diagnosis;
}
string patient::getAdmitDate() {
    return admitDate;
}
string patient::getDischargeDate() {
    return dischargeDate;
}

void patient::setFirstName(string firstName) {
    this->firstName = firstName;
}
void patient::setLastName(string lastName) {
    this->lastName = lastName;
}
void patient::setPatientID(long int patientID) {
    this->patientID = patientID;
}
void patient::setAssignedDoctorID(long int assignedDoctorID) {
    this->assignedDoctorID = assignedDoctorID;
}
void patient::setDOB(string DOB) {
    this->DOB = DOB;
}
void patient::setBloodType(string bloodType) {
    this->bloodType = bloodType;
}
void patient::setDiagnosis(string diagnosis) {
    this->diagnosis = diagnosis;
}

void patient::setAdmitDate(string admitDate) {
    this->admitDate = admitDate;
}

void patient::setDischargeDate(string dischargeDate) {
    this->dischargeDate = dischargeDate;
}
