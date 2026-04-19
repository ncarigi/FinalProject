//
// Created by Nicolas Carigi on 2026-04-18.
//

#ifndef FINALPROJECT_HOSPITAL_H
#define FINALPROJECT_HOSPITAL_H
#include <vector>
#include "doctor.h"
#include "patient.h"

class hospital {

    public:
    hospital();

    void FindOldestPatient();
    int CountCriticalPatients();
    void DoctorsBySpecialty(string specialty);
    void Show_Patient_by_ID(long int ID);
    void Show_Doctor_by_ID(long int ID);
    void Show_Assigned_Doctor(long int PatientID);
    void Show_Assigned_Patients(long int DoctorID);

    private:
    vector<patient> patients;
    vector<doctor> doctors;
};


#endif //FINALPROJECT_HOSPITAL_H