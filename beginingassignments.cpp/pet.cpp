#include <iostream>

using std::cout;
using std::endl;

class pet{
public:
    Pet();
    Pet(int size, int leg_length, char color);
    int accident (int n):
/* a class  makes a blue print for some object. instance of tha tobject in main a spefically constuctions for blue print. construvtor.
Dont change the sonstructor because that has happened ot changes all the childern.
when making a object having the object allow abstraction like in and char which can be changed. 
it can be changed by using it in a way and nto changed because you wan the outcome chnges by impolcation,
 THE POINT of object is to catergozing.To catergorzie and its to compare things. caparsion is the power of objects.
  AN object says there is a reason or not a reason to compare 
 ThE point of arrays is to store data arrays are all the same.you can compare tiger and fish.   */

private:
    int size;
    int leg_length;
    char color;
    
};

//1 nuke 2 train 3 drown 
int pet :: accident(int n) 
//{if(int ==1 ) {} else {if (int == 2) { } else { } {if (int ==3 ) { } else { } }}}
{switch(n) {
    case 1: //n ==1
        size=0;
        leg_length=0:
        color="-"
        return 0;
    case 2; //n==2
        size=size-2:
        leg_length= leg_length -2 
        return 0;
    case 3:/// n==3
        size=size+1:
        return 0;
    default:
    cout << "n is not 123" << endl;
    return 0;
}
return 1;

} 
pet::pet(int s,int l, char c) { 
     size = s;
     leg_length = l
    Char = c }
  
int main(){
    return 0;

}