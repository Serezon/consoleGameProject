#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
#include <iterator>
#include "pers.h"


using namespace std;

char randomTypeOfCharacter () {
    srand( (time(0)*1000) + (time(0)/1000) );
    if (rand()%3 == 0) {
        return 'm';
    } else {
        return 'l';
    }
}


int main() {
    int n;
    vector<person> firstCity;
    vector<person> secondCity;
    cout << "VVedit kilkist voiniv" << endl;
    cin >> n;
    for (int i=0; i<n; ++i) {
        firstCity.push_back(person(randomTypeOfCharacter(),1));
    }
    for (int i=0; i<n; ++i) {
        secondCity.push_back(person(randomTypeOfCharacter(),2));
    }

    while(true) {
        if (firstCity.size() == 0) {
            cout << "secondCity WIN" << endl;
            break;
        } else if (secondCity.size() == 0) {
            cout << "firstCity WIN" << endl;
            break;
        }
        for (int i=0; i<min(firstCity.size(),secondCity.size()); i++) {
            firstCity[i] + secondCity[i];
            if (firstCity[i].alive == 0) {
                firstCity.erase(firstCity.begin()+i);
                cout << "First died" << " ";
            }
            if (secondCity[i].alive == 0) {
                secondCity.erase(secondCity.begin()+i);
                cout << "Second died" << " ";


            }
        }


    }

    return 0;
}
