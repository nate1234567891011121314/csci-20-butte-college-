#include "Pet2.hpp"

int main() {
    Dog bob (2000,1000, "bob",10);
    Dog bill (200, 5, "bill",5);
    
    cout << bob.samesizePet (bob, bill) << endl;

    return 0;
}

bool Dog ::Do_YOU_NEED_HAIRCUT{
    if (c>20) {
        return true;
    } else {
        return false;
    }
}

bool Pet::samesizePet(Pet a ,Pet b) {
    if (a.size == b.size) {
        return true; 
        } else {
            return true;
    }
}

bool Pet::samenamePet(Pet a ,Pet b) {
    if (a.name == b.name) {
        return true; 
        } else {
            return true;
    }
