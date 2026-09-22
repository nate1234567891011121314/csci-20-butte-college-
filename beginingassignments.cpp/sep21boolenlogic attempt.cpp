#include <iostream>
//libaray needed so c++ knows where to grab stuff
int main() {
  //start opening the door to the code the integar () what is being held and werid squiggle what ists start starts reading the code 
    // so Bool is seting up variable and what they represent short for boolean data inorder to Set up our conditions (true or false) both have to be tur the switch is one
  //and thehas power and semi colen to show we finished this line
    bool isSwitchOn = true;
    bool hasPower = true;

    std::cout << "--- Light Bulb Simulation ---\n\n";
//std::cout the letters being output from the code  and pretty much what i hope tpo accomplish
    // 2. The AND operator (&&) requires BOTH to be true
    bool isLightBulbShining = isSwitchOn && hasPower;

    // 3. Make a decision based on the result
    if (isLightBulbShining) {
        std::cout << "💡 The light bulb is ON! The room is bright.\n";
    } else {
        std::cout << "🌑 The light bulb is OFF! The room is dark.\n";
    }

    return 0;
}
