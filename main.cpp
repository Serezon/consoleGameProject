#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
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
    /*person **people = new person* [100];
    for (int i=0; i<100; i++) {
        *people[i] = person( randomTypeOfCharacter(), rand()%2 );
    }*/
    return 0;
}
