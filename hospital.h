/*
Name: Nicolas Carigi
Student ID: 40303463
Course: COEN 243
Assignment: Final Project
 */

#ifndef FINALPROJECT_HOSPITAL_H
#define FINALPROJECT_HOSPITAL_H
#include <vector>
#include "doctor.h"
#include "patient.h"

class hospital {

    public:
    hospital();
    ~hospital();

    void Find_Oldest_Patient();
    int Count_Critical_Patients();
    void DoctorsBySpecialty(const string& specialty);
    void Show_Patient_by_ID(long int ID);
    void Show_Doctor_by_ID(long int ID);
    void Show_Assigned_Doctor(long int PatientID);
    void Show_Assigned_Patients(long int DoctorID);


    private:
    patient Get_Patient_Object_By_ID(long int ID);
    doctor Get_Doctor_Object_By_ID(long int ID);

    vector<patient>* patients;
    vector<doctor>* doctors;
};


#endif //FINALPROJECT_HOSPITAL_H