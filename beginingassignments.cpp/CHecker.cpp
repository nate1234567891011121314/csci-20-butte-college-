#include <iostream>
using std::cout;
using std::endl;
//GOALS:we have to define the BOARD- TEAMS BREACKDOWN- WHERE BEGIN PIECES - WHAT MOVES ARE LEGAL- HOW THE PLAYER INPUTS - PLAYERS INPUTS ARE LEGAL- 
// Board is the same 8×8 array used by the rest of the program
char board[8][8];
/*which creates 
 1 2 3 4 5 6 7 8
1
2
3
4
5
6
7
8
thats really something right there 
*/ 
// Define and assign who owns the piece?  (1 = team1, 2 = team2, 0 = empty)
int player(char piece) 
//this says integar player because computers dont know jack so they know symbols we assign meaning to the collection of symbols player by saying int
// if the piece is "&" return 1 and "*" return 2 so i had to spefically say a piece can mean on of these two possiblitlys of teams but these symbols already have meaning 
// so they have to return different numbers. Example dog has a inhert meaning but we changed meaning of dog to mean stinky.
// Kinda srewed my self esppically sinces i know & means and * means multiply choose they because out of all the symbols that are made with (shit any numbers) 
// & and *  looked the most distanctly different
{
    if (piece == '&' ) return 1;
    if (piece == '*' ) return 2;
    return 0;
}

// so bool means this "ITEM" has to be either true or false player
// we assign meaning to onboard. onbaord holds interagar x, integar y 
// x = x axis y = y axis 
//bool (true or false) onBoard (intager x axis,inteagar y axis) 
// SIDE NOTE:so TODAY i learned & doesnt always mean "and" because i used a boolens i need to use a spefic type of "and" &&
// & is used for "and" for int while && is used for "and" for booleans(t or f)
//this is very important to know when i am using booleans >:(
//so when i am looking at the code and cant figure out what the bug is rememeber am i using the correct notation;
//WHAT DIS MEAN:for this to be true all of these conditions of x axis being greater than 0 and(for booleans) x axis is less than 8 
//and(for booleans)y axis is ggreater than or equal to 0 and (for booleans) y axis is greater than 8.
//before i put the and(for boolean) was doing 

/*bool onBoard(int x, int y) {
    if (x >= 0) {
        if (x < 8) {
            if (y >= 0) {
                if (y < 8) {
                    return true;
                }
            }
        }
    }
    return false;
}*/
// c++ is cool in the fact the archetics have thought threw everything like multiple if statements i just had to look up how to combine them into one condirional rule
bool onboard(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}
// i know that i could have "and"(for booleans)in the code below but idk how so we could so we taking the long route
//we create a boolean to assign true and false meaning we call this boolean Yeahcomethisway which caries(charater piece(* or &),inteager Y_direction(how far up or down))
bool Yeahcomethisway(char piece, int Y_direction) {
// we have to create the condtions of how the team can move.
// i was struggling with how the movement was worng becuase orginally i had & +1 y movement and * -1 y movement because the graph looked 
/* 1 2 3 4 5 6 7 8
1* * *  * * * *  going down * -1
2*  * * ***  *
3
4
5
6 &   &   &   &
7   &   &  &     going up & +1
8 &   &   &    &
in my head 

What actually happening 
 1 2 3 4 5 6 7 8
1* * *  * * * *  the as the pieces move forward the numbers are increasing * +1
2*  * * ***  *
3* * * *  **  *
4
5
6 &   &   &   &
7   &   &  &     as the pieces move forward the numbers are decreasing & -1
8 &   &   &    &


*/ 
    // IF the piece is the Team 1 symbol ('&')
    // Give true and false names just like my automaton 
    bool direction_ALLOWED = true;
    bool direction_BLOCKED = false;
//this saying if piece"&" is only allow to decrease the space of the number on the grid in order to move forward that statement is true anthing else is flase and blocked
    if (piece == '&') {
        if (Y_direction == -1) {
            return direction_ALLOWED; // Instead of true
        } else {
            return direction_BLOCKED;  // Instead of false
        }
    }
// this saying if piece "*" is only allowed to increase the pace of the number the piece is on the 2d grid in order to move forawrd that statemnt is true firection allowed
//anything else flase (blocked)
    if (piece == '*') {
        if (Y_direction == +1) {
            return direction_ALLOWED; 
        } else {
            return direction_BLOCKED; 
        }
    }

    return direction_BLOCKED; 
}

// today i learned that theres a reason why print isnt always used can void can be used gives meaning to the word examineThisPiece and making ti into a function 
// pretty much like most usefull thing ever because it gives meaning to the text and we describe what is going on inside this
//ext pretty much making the text into a function 
void examineThisPiece(int x, int y) {
    /*• board[y][x]: This is super duper important its able to point and look at your grid array correctly (captures all of the spaces)becauase
     you index(the bars [y][x]) the row tracker variable (y) first to select the correct horizontal row vector line, then apply the column tracker variable (x) to pinpoint the precise cell grid space.
• char piece =: Stores the character found at those coordinates inside a local variable called piece.*/
    char piece = board[x][y]; 
      // pretty much identifies the team of the piece
    int  team  = player(piece);
  //if the team is neither 1 & or 2 (*) the team is 0 being empty of any piece. if the space is 0(empty) than return meanin skip this jit and move on to the nxt
    if (team == 0) return; 
// pretty much making listing how there are 4 sets (how many items pretty much saying there are 1set(-1,1) 2set{}3set{}4set{}) and 2 is how many numbers in the set 
/* 
 {-1, -1}: Up Left
 {1, -1}: Up Right
 {-1, 1}: Down left
 {1, 1}: Down Right 
 its harder to visualize bc the grpah is weird
 12345678
 1
 2
 3
 4
 5
 6
 7
 8
 A visual to help understand 

          x's
      x - 1      x      x + 1
     .────────────────────────.
y - 1│  [0]     │      │  [1]     │  <- y'S above
     │ Up-Left  │      │ Up-Right │
     ├──────────┼──────┼──────────┤
  y  │          │ me   │          │  <- Current y's
     │          │Piece │          │
     ├──────────┼──────┼──────────┤
y + 1│  [2]     │      │  [3]     │  <- y's below
     │Down-Left │      │Down-Right│
      ────────────────────────────────────

 pretty much the diragonlly moves that both teams can make */
    int directional_possiblities[4][2] = { {-1, -1}, {1, -1}, {-1, 1}, {1, 1} };
//declare loop within this brackets(starting value ;(end setence) when to stop;(end sentenece) records howmany rounds ) side note 4 sets but the count 0 1 2 3
/*

has a loop names the loop variable "bounds" starts at 0, then checks if its less than four because there are 4 sets therefore 4 possibliltys for movement
(if less than four hasnt checked every movement keep checking,if has checked 4 then done) starts the checks 
after every round of the loop it records the loop variable counter "bounds". bounds= bounds+1 

basically saying after first set is checked 0 bound; 0<4 yup
to next second set checks add 0bound+1= 1; 1<4 yup
to next third set 1bound+1=2; 2<4 yup
to next fourth set 2+1=3; 3<4 yup
to next fifth set 3+1=4; 4<4 nope
stop all sets have been checked

round 1 look at Set 1 = (grab -1x,then grab -1y) 0 bound
round 2 look at Set 2 = (grab 1x,then grab-1y) 1 bound
round 3 look at Set 3 = (grab-1x,then grab 1y) 2 bound
round 4 look at Set 4 = (grab 1x,then grab 1y) 3 bound

 [0] looking for data of x's and [1] is looking for data of y's
the bounds represents the round(set of data)
all of and that data(weather is (what set it is, x's) or (what set it is, y's) is called directional possibilities 

 saysto computer where  (0-3 set) (all x's)
 directional_possiblities[bounds][0]; 

 saysto computer where  (0-3 set) (all y's)
 directional_possiblities[bounds][1]; 
*/

    for (int bounds = 0; bounds < 4; bounds=bounds+1) {
        
    // 1st Condition: Check if the piece is physically allowed to move in this vertical direction.
    // Team 1 (&) can only move diagonally forward-up: left (-1, -1) or right (1, -1).
    // Team 2 (*) can only move diagonally forward-down: left (-1, 1) or right (1, 1).
    // The computer checks the Yeahcomethisway function and if finds this direction is not possible, 
    // it blocks the path, skips the rest of this round's conditions, and moves to the next direction set for this piece.
    // It will not bother checking walls or teammates for this direction. If it is true, it advances to the next condition.

         if (Yeahcomethisway(piece, directional_possiblities[bounds][1]) == false) {
            continue; 
        }

/*

Round 1 (bounds = 0)

What it grabs directly: Column 0 is -1, Column 1 is -1
The Math:
Target_x = x + directional_possiblities[0][0] → x + (-1)
Target_y = y + directional_possiblities[0][1] → y + (-1)
Visual Target: The computer directly targets Up and Left at square.

Round 2 (bounds = 1)

What it grabs directly: Column 0 is 1, Column 1 is -1
The Math:
Target_x = x + directional_possiblities[1][0] → x + 1
Target_y = y + directional_possiblities[1][1] → y + (-1)
Visual Target: The computer directly targets Up and Right at square.

Round 3 (bounds = 2)

What it grabs directly: Column 0 is -1, Column 1 is 1
The Math:
Target_x = x + directional_possiblities[2][0] → x + (-1)
Target_y = y + directional_possiblities[2][1] → y + 1
Visual Target: The computer directly targets Down and Left at square.

Round 4 (bounds = 3)

What it grabs directly: Column 0 is 1, Column 1 is 1
The Math:
Target_x = x + directional_possiblities[3][0] → x + 1
Target_y = y + directional_possiblities[3][1] → y + 1
Visual Target: The computer directly targets Down and Right at square.


*/
        int Target_x = x + directional_possiblities[bounds][0];          
        int Target_y = y + directional_possiblities[bounds][1];
/*
2 condition
asks if funtion onboard (checks if the piece is actually on the board) 
we checked if the piece is moving diagnally so we move diagnolly left or right, if that move made is the piece going to be on the board?
if true that this data of the piece future space is off the board then blocked 
if false that this data of piece future space is on the board move to the next condition 
*/
        
        if (onboard(Target_x, Target_y) == false) {               
            // True: consequence direction blocked
            continue; 
        } 
        // False: move to next condition
/**/

        int neighbourplayer = player(board[Target_y][Target_x]);

        // 3rd Condition: "there's a teammate?"
        if (neighbourplayer == team) {         
            // True: direction blocked
            continue; 
        }
        // False: move to next condition

        // 4th Condition: check if there is empty space
        if (neighbourplayer == 0) {            
            // True: direction step
            cout << "  STEP  " << char('A' + x) << (y + 1) << " → " << char('A' + Target_x) << (Target_y + 1) << endl;
            continue; 
        }
        // False: move to next condition

        // 5th Condition: "is the diagonal space of an opponent"
        // (Since it's not a wall, not a teammate, and not empty, it MUST be an opponent!)
        int Actualization_x = x + (2 * directional_possiblities[bounds][0]); 
        int Actualization_y = y + (2 * directional_possiblities[bounds][1]);

        // 5thA Condition: "is the space behind the diagonal space of an opponent empty?"
        if (onboard(Actualization_x, Actualization_y) == true && board[Actualization_y][Actualization_x] == '.') {
            // True: direction jump
            cout << "  JUMP  " << char('A' + x) << (y + 1) << " → " << char('A' + Actualization_x) << (Actualization_y + 1) << endl;
        } else {
            // False: direction blocked
            continue; 
        }


}
//-------------------------------------------
// Example: scan the whole board and examine every piece of a team
// ------------------------------------------------------------
void scanAllPieces(int team); 
{
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            if (player(board[r][c]) == team) 
                examineThisPiece(r, c);   // ← EXAMINE_THIS_PIECE
            }
            // SCAN_NEXT_PIECE is just the next iteration of the loops
        }
    }
}  

