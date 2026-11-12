#include<iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Pet {
/* 
-boundary int allows for 2 billion grams 2100  tons
-pets eats more than 2100 metric tons  per week 
-name is over 10 charaters 
*/
private:
    int size;// weight in grams ,
    string name;//we make array of amount of letters that can be used. name = 10 charaters 
    int food; // kg food per week
public:
 bool samesizePet(Pet a ,Pet b);
    bool samenamePet(Pet a ,Pet b);
    Pet();
    Pet(int s,int f, string n);


    //a class defination isnt accompishing data multipacation a class is defination the structure of sdta. 
    //the structure of data is a type. its must be known before your program is written 
};
// defination f fog is dependent on pet 
class Dog: Pet {
    private:
    //2 data
    int coat_length ;//inches 
    public:
    bool Do_YOU_NEED_HAIRCUT(int d);//does the dog need a hair cut 
    
    Dog();
    Dog(int s, int f, string n,int c);
};

Dog::Dog(int s, int f, string n,int c) {
    Pet(s,f,n);
    coat_length= c;
}

Dog :: Dog(){
    Pet();
    coat_length= 0;
}

Pet::Pet() { //defualt
    size = 0;
    food = 0;
    name = "";
    //string of charaters is if 50 charaters then 50 charaters dynaimcily sized to what you need. con if its a big project and takes alot mememory
    // charater arrays harder to use but lesss memory
}

Pet::Pet( int s, int f, string n) {
    size= s;
    food= f;
    name =n;

}
