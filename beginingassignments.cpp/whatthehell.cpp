#include <iostream>

using std::abs;
using std::cin;
using std::cout;
using std::endl;

int main() {
    const int GRID_SIZE = 8;

    // 1. Print the top margin spacing
    std::cout << "   ";
    
    // 2. Print X-axis labels (1 to 8)
    for (int x = 1; x <= GRID_SIZE; ++x) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    // 3. Print the top bounding divider line
    std::cout << "  +----------------\n";

    // 4. Print Y-axis rows (H down to A)
    // Starting at 'H' down to 'A' places the origin (1, A) at the bottom-left
    for (char y = 'A' + GRID_SIZE - 1; y >= 'A'; --y) {
        std::cout << y << " | "; // Y-axis label and side border
        
        for (int x = 1; x <= GRID_SIZE; ++x) {
            std::cout << ". ";  // Grid point marker
        }
        std::cout << "\n";
    }

    return 0;
}