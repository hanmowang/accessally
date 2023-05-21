#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;
int main() {
    /*
    Index : Blood Type
        0 : O-
        1 : O+
        2 : A-
        3 : A+
        4 : B-
        5 : B+
        6 : AB-
        7 : AB+
    */

    int blood_storage[8];
    int patients[8];
    int count = 0;

    for (int i = 0; i < 8; i++) {
        cin >> blood_storage[i];
    }
    for (int i = 0; i < 8; i++) {
        cin >> patients[i];
    }

    for (int i = 0; i < 8; i++) {
        int blood_desired[i + 1];
        int num_blood_desired = 0;
        // if requires negative blood
        if (i % 2 == 0) {
            // if patient is B- we need to only look for B- and O-
            if (i == 4) {
                blood_desired[0] = 0;
                blood_desired[1] = 4;
                num_blood_desired = 2;
            }
            // otherwise, we can simply look for bloods that has lower index.
            else {
                for (int j = 0; j <= i + 1; j += 2) {
                    blood_desired[j/2] = j;
                    num_blood_desired++;
                }
            }            
        }
        // if require positive blood
        else {
            // if patient is B+ we need to only look for B-, B+, O- and O+
            if (i == 5) {
                blood_desired[0] = 1;
                blood_desired[1] = 5;
                blood_desired[2] = 0;
                blood_desired[3] = 4;
                num_blood_desired = 4;
            }
            // otherwise, we can simply look for bloods that has lower index.
            else {
                // prioritize the positive bloods first.
                int temp = 0;
                for (int j = 1; j <= i; j += 2) {
                    blood_desired[temp++] = j;
                    num_blood_desired++;
                }
                for (int j = 0; j <= i; j += 2) {
                    blood_desired[temp++] = j;
                    num_blood_desired++;
                }
            }
        }

        for (int j = 0; j < num_blood_desired; j++) {
            if (patients[i] <= blood_storage[blood_desired[j]]) {
                count += patients[i];
                blood_storage[blood_desired[j]] -= patients[i];
                patients[i] = 0;
            }
            else {
                count += blood_storage[blood_desired[j]];
                patients[i] -= blood_storage[blood_desired[j]];
                blood_storage[blood_desired[j]] = 0;
            }
        }
    }
    cout << count << endl;
    return 0;
}