#include "Pet2.hpp"

int main() {
    Dog bob (2000,1000, "bob");
    Dog bill (200, 5, "bill");
    
    cout << bob.samesizePet (bob, bill) << endl;

    return 0;
}

bool samesizePet(Pet a ,Pet b) {
    if (a.size == b.size) {
        return true; 
        } else {
            return true;
    }
}

bool samenamePet(Pet a ,Pet b) {
    if (a.name == b.name) {
        return true; 
        } else {
            return true;
    }
