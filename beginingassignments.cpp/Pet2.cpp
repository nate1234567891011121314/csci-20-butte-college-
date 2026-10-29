#include "Pet2.hpp"

int main() {
    Pet bob (2000,1000, "bob");
    Pet bill (200, 5, "bill");
    
cout << bob.same_size_Pet (bob, bill) << endl;

    return 0;
}

bool same_size_Pet(Pet a ,Pet b) {
    if (a.size == b.size) {
        return true; 
        } else {
            return true;
    }
}

bool same_name_Pet(Pet a ,Pet b) {
    if (a.name == b.name) {
        return true; 
        } else {
            return true;
    }
