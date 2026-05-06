#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "entity.h"
#include <string>
using namespace std;

//exceptions

class BedUnavailableException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: No available beds at this hospital.";
    }
};

class InvalidHospitalDataException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Invalid hospital data encountered.";
    }
};

// ============================================================
//  Hospital — Derived from Entity
//  Stores hospital data loaded from hospitals.txt
//  Overrides display() and getID() from Entity
// ============================================================

class Hospital : public Entity {
private:
    string location;
    int availableBeds;
    int totalBeds;
    string phone;
    bool emergency;

    // Distance (km) from each hub town
    int distWaknaghat;
    int distKandaghat;
    int distSolan;
    int distShimla;
    int distChail;

public:
    // Constructor
    Hospital(const string& id,
             const string& name,
             const string& location,
             int availableBeds,
             int totalBeds,
             const string& phone,
             bool emergency,
             int distWaknaghat,
             int distKandaghat,
             int distSolan,
             int distShimla,
             int distChail);

    // Overridden from Entity
    void display() const override;
    string getID() const override;

    // Getters
    string getLocation() const;
    int getAvailableBeds() const;
    int getTotalBeds() const;
    string getPhone() const;
    bool isEmergency() const;
    int getDistanceFromHub(const string& hub) const;

    // Bed management
    void decrementBed();

    // Eligibility check
    bool isEligible(int severity) const;
};

#endif // HOSPITAL_H
