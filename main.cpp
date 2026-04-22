#include <iostream>
#include "hospital.h"


int main() {

    hospital hospital_central;

    while (true) {
        cout << "\nPlease select an option: [1-7]" << endl;
        cout <<"1. Find oldest patient\n2. Count critical patients\n3. Show patient by ID\n4. Show doctor by ID\n5. Show assigned doctor\n6. Show assigned patients\n7. Exit\n";
        int menuSelector;
        cin >> menuSelector;
        switch (menuSelector) {
            case 1: { //Find oldest patient
                hospital_central.FindOldestPatient();
                break;
            }

            case 2: { //Count critical patients
                cout <<"There are currently " << hospital_central.CountCriticalPatients() << " critical patients\n";
                break;
            }

            case 3: {
                cout<<"Patient Search by ID"<<endl;
                cout<<"ID to search: ";
                long int IDToSearch;
                cin >> IDToSearch;
                hospital_central.Show_Patient_by_ID(IDToSearch);
                break;
            }

            case 4: {
                cout<<"Doctor Search by ID"<<endl;
                cout<<"ID to search: ";
                long int IDToSearch;
                cin >> IDToSearch;
                hospital_central.Show_Doctor_by_ID(IDToSearch);
                break;
            }

            case 5: {
                cout<<"Show assigned doctor"<<endl;
                cout<<"Patent ID to search: ";
                long int IDToSearch;
                cin >> IDToSearch;
                hospital_central.Show_Assigned_Doctor(IDToSearch);
                break;

            }

            case 6: {
                cout<<"Show assigned patients"<<endl;
                cout<<"Doctor ID to search: ";
                long int IDToSearch;
                cin >> IDToSearch;
                hospital_central.Show_Assigned_Patients(IDToSearch);
                break;
            }

            case 7: { //Exit
                cout<<"Goodbye"<<endl;
                cout<<"Shutting down"<<endl;
                return false;
            }

            case 8: { //Count critical patients
                hospital_central.DoctorsBySpecialty("Diagnostics");
                break;
            }

            default: {
                cout<<"Invalid option!"<<endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }

        }
    }
    return 0;
}