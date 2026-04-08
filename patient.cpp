#include <iostream>
#include <limits>
using namespace std;

const int MAX_PATIENTS = 100;

class Patient
{ 
private:
    string name;
    int age;
    string gender;
    string village;
    int severity;
    string hospital;

public:

    void registerPatient()
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nEnter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Gender: ";
        getline(cin, gender);

        cout << "Enter Village: ";
        getline(cin, village);

        cout << "Enter Severity (1-5): ";
        cin >> severity;

        assignHospital();
    }

    void assignHospital()
    {
        if(village == "Taradevi" || village == "Jubbarhatti")
            hospital = "IGMC Shimla";

        else if(village == "Barog" || village == "Nagaun" || village == "Tanaji")
            hospital = "Civil Hospital Kandaghat";

        else if(village == "Dera" || village == "Kaithlighat" || village == "Kiarighat")
            hospital = "Civil Hospital Kandaghat";

        else if(village == "Rachhana")
            hospital = "Regional Hospital Solan";

        else
            hospital = "Regional Hospital Solan";
    }

    void display()
    {
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nGender: " << gender;
        cout << "\nVillage: " << village;
        cout << "\nSeverity: " << severity;
        cout << "\nAssigned Hospital: " << hospital;
        cout << "\n------------------------\n";
    }

    string getName()
    {
        return name;
    }
};

Patient patients[MAX_PATIENTS];
int patientCount = 0;

void addPatient()
{
    if(patientCount >= MAX_PATIENTS)
    {
        cout << "Patient storage full!\n";
        return;
    }

    patients[patientCount].registerPatient();
    patientCount++;

    cout << "\nPatient Registered Successfully!\n";
}

void showPatients()
{
    if(patientCount == 0)
    {
        cout << "No patients registered.\n";
        return;
    }

    for(int i = 0; i < patientCount; i++)
    {
        patients[i].display();
    }
}

void searchPatient()
{
    string name;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter patient name: ";
    getline(cin, name);

    for(int i = 0; i < patientCount; i++)
    {
        if(patients[i].getName() == name)
        {
            patients[i].display();
            return;
        }
    }

    cout << "Patient not found.\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n Welcome to Rural Healthcare Allocation System! We offer you local healthcare access service. Please select your command:\n";
        cout << "1. Register Patient\n";
        cout << "2. Show All Patients\n";
        cout << "3. Search Patient\n";
        cout << "4. Exit\n";
        cout << "Enter choice:\n";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addPatient();
                break;

            case 2:
                showPatients();
                break;

            case 3:
                searchPatient();
                break;

            case 4:
                cout << "\nSystem Closed.\n";
                break;

            default:
                cout << "Invalid choice! Please selected another option.\n";
        }

    } while(choice != 4);

    return 0;
}
