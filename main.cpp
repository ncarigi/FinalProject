#include <iostream>
#include "hospital.h"

// Main function with menu
int main() {
    // Create a hospital object
    hospital hospital_central;

    // Main menu loop
    while (true) {
        // Display menu options
        cout << "\nPlease select an option: [1-7]" << endl;
        cout <<"1. Find oldest patient\n2. Count critical patients\n3. Show patient by ID\n4. Show doctor by ID\n5. Show assigned doctor\n6. Show assigned patients\n7. Exit\n8. Doctors by specialty (missing sample menu)\n";

        // Input validation for menu selection
        int menuSelector=0;
        if (!(cin >> menuSelector)) {
            cout << "Invalid input! Please enter a number" << endl;
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            continue;
        }

        // Handle menu selection
        switch (menuSelector) {
            case 1: { //Find the oldest patient
                hospital_central.Find_Oldest_Patient();
                break;
            }

            case 2: { //Count critical patients
                cout <<"There are currently " << hospital_central.Count_Critical_Patients() << " critical patients\n";
                break;
            }

            case 3: { //Show patient by ID
                cout<<"Patient Search by ID"<<endl;
                cout<<"ID to search: ";
                long int IDToSearch;
                cin >> IDToSearch;
                hospital_central.Show_Patient_by_ID(IDToSearch);
                break;
            }

            case 4: { //Show doctor by ID
                cout<<"Doctor Search by ID"<<endl;
                cout<<"ID to search: ";
                long int IDToSearch;
                cin >> IDToSearch;
                hospital_central.Show_Doctor_by_ID(IDToSearch);
                break;
            }

            case 5: { //Show assigned doctor
                cout<<"Show assigned doctor"<<endl;
                cout<<"Patent ID to search: ";
                long int IDToSearch;
                cin >> IDToSearch;
                hospital_central.Show_Assigned_Doctor(IDToSearch);
                break;

            }

            case 6: { //Show assigned patients
                cout<<"Show assigned patients"<<endl;
                cout<<"Doctor ID to search: ";
                long int IDToSearch;
                cin >> IDToSearch;
                hospital_central.Show_Assigned_Patients(IDToSearch);
                break;
            }

            case 7: { //Exit
                cout<<"Goodbye"<<endl;
                return 0;
            }

            case 8: { //Show doctors by specialty (wasn't in the sample menu, but I added it because it was in the hospital class)
                cout<<"Search by specialty"<<endl;
                cout<<"Specialty to search: ";
                string specialty;
                cin >> specialty;
                hospital_central.DoctorsBySpecialty(specialty);
                break;
            }


            default: { //Invalid option handler
                cout<<"Invalid option!"<<endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }

        }
    }

}