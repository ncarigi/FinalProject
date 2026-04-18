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
    void importPatients();

    private:
    vector<patient> patients;
    vector<doctor> doctors;
};


#endif //FINALPROJECT_HOSPITAL_H