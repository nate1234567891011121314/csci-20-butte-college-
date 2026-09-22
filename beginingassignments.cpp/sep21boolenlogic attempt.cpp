#include <iostream>
//libaray needed so c++ knows where to grab stuff
int main() {
  //start opening the door to the code the integar () what is being held and werid squiggle what ists start starts reading the code 
    // so Bool is seting up variable and what they represent short for boolean data inorder to Set up our conditions (true or false) both have to be turn the switch is one
  //and thehas power and semi colen to show we finished this line
    bool isSwitchOn = true;
    bool hasPower = true;

    std::cout << "Light Bulb Simulation ";
//std::cout the letters being output from the code  and pretty much what i hope to accomplish the << point at what the meesage i want to show and the semihicomine ends the sentence
    // 2. The AND operator (&&) requires BOTH to be true
    bool isLightBulbShining = isSwitchOn && hasPower;
// a third Boolen vairbale has to be made for when "isStichOn" and "hasPower" are ture and the computer has a the knowlege of what happens when both are true and sets them equall and && represents AND 
  // so the sentence is Boolean variable isLightBulbShining equalviant to when isSitchON and Has power are true end sentence

  // if represents a question statment so when IslightBublbShing is true  werid bracket / squggle bracket is holder  outputs the the light is on the room is bright end 
  //if not then send this text the light bulb is off the room is dark
  //sentence is saying IF IS LIGHT BUBLB SHINING IS TRUE ENTER THIS TEXT POINTS AT TEXT THE LIGHTBULB IS ON THE ROOM IS BRIGHT IF ANYHTING ELSE THE LIGHTBULB IS OFF THE ROOM IS DARK END SENTECNE AND END PARAGRPAH 
  //IF ZERO ERRORS CLOSE DOOR THAT MAIN LEFT OPEN
    if (isLightBulbShining) {
        std::cout << " The light bulb is on The room is bright. ;
    } else {
        std::cout << " The light bulb is off The room is dark. ;
    }

    return 0;
}
