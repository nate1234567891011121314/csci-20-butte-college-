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
bool onBoard(int x, int y) {
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
    // Give true and false names 
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

// today i learned that theres a reason why print isnt always used can void can be used gives meaning to the word examineThisPiece
// pretty much like most usefull thing ever because it gives meaning to the text and we describe what is going on inside this
//ext pretty much making the text into a function 
void examineThisPiece(int x, int y) {
    /*• board[y][x]: This is super duper important its able to point and look at your grid array correctly (captures all of the spaces)becauase
     you index(the bars [y][x]) the row tracker variable (y) first to select the correct horizontal row vector line, then apply the column tracker variable (x) to pinpoint the precise cell grid space.
• char piece =: Stores the character found at those coordinates inside a local variable called piece.*/
    char piece = board[x][y]; 
    int  team  = player(piece);
    
    if (team == 0) return; 

    int directions[4][2] = { {-1, -1}, {1, -1}, {-1, 1}, {1, 1} };

    for (int i = 0; i < 4; i++) {
        int dx = directions[i][0]; 
        int dy = directions[i][1]; 

        // 1st Condition: Check if it can move diagonally left or right (Always true / Team check)
        if (Yeahcomethisway(piece, dy) == false) {
            continue; // Wrong vertical direction -> Blocked
        }

        int nx = x + dx;          
        int ny = y + dy;

        // 2nd Condition: "there's a wall?"
        if (onBoard(nx, ny) == false) {               
            // True: consequence direction blocked
            continue; 
        } 
        // False: move to next condition

        int neighbourplayer = player(board[ny][nx]);

        // 3rd Condition: "there's a teammate?"
        if (neighbourplayer == team) {         
            // True: direction blocked
            continue; 
        }
        // False: move to next condition

        // 4th Condition: check if there is empty space
        if (neighbourplayer == 0) {            
            // True: direction step
            cout << "  STEP  " << char('A' + x) << (y + 1) << " → " << char('A' + nx) << (ny + 1) << endl;
            continue; 
        }
        // False: move to next condition

        // 5th Condition: "is the diagonal space of an opponent"
        // (Since it's not a wall, not a teammate, and not empty, it MUST be an opponent!)
        int bx = x + (2 * dx); 
        int by = y + (2 * dy);

        // 5thA Condition: "is the space behind the diagonal space of an opponent empty?"
        if (onBoard(bx, by) == true && board[by][bx] == '.') {
            // True: direction jump
            cout << "  JUMP  " << char('A' + x) << (y + 1) << " → " << char('A' + bx) << (by + 1) << endl;
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

