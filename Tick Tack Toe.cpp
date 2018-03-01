 #include <cstdlib>								 
 #include <iostream>
 #include <stdlib.h>		// thanks to cplusplus.com/reference for info on this useful libary!
 #include <ctime>			// thanks to stack overflow for this better random number generation
 
 
 
 
 using namespace std;								// wow, lot of functions needed for a simple tick tack toe game
 void printStage(int GameState[]); 
 void printStageStart();
 int checkWin(int GameState []);
 int gameOver(int xWins, int oWins, int draws);
 int nextTurn(int GameState[], int turn, int choice);
 int chooseFirst(int GameState[]);
 void startGame(int GameState[],int choice);
 int medComp(int GameState[]);
 int hardComp(int GameState[]);
 int check(int GameState[],int check);



int main(int argc, char * argv[]) {

	printStageStart(); 
	int GameState[10];			//this array stores x, o values in [1-9] stores who is going first in [0]
 	  for(int i=0; i<10;i++)	// make sure array is zeroed out before game
   		GameState[i]=0;
	int choice = 0;
	cout << "Enter game State" <<endl;
	cout << "Enter 1 for vs. computer(easy)" <<endl;
	cout << "Enter 2 for vs. human" << endl;	
	cout << "Enter 3 for vs. computer(Medium)" <<endl;
	cout << "Enter 4 for vs. computer(Hard)" <<endl;
	cin >> choice;				//Takes in number for selection of vs.

	if(choice !=2 && choice !=1&& choice !=3 && choice !=4)	// reject bad choice
		cout << "Bad input, sorry closing program" << endl;
	else
		startGame(GameState,choice);	//start game with good choice

	

  }
 
void printStageStart(){	// shows start of game, introduces how it works
 		
 	cout <<"For this tick tack toe game, random chance chooses who goes first" <<endl;
	cout <<"First team to 3 in a row wins, if no team gets 3 it is a draw"<<endl;	
	cout <<"Select a square by entering the corrisponding number below"<<endl;	
 	cout<<""<< endl;
 	cout << " 1 |  2  | 3 " << endl;
    cout << "----------------" << endl;
    cout << " 4 |  5  | 6 " << endl;
    cout << "---------------" << endl;
    cout << " 7 |  8  | 9 " << endl;
	   }

void startGame(int GameState[],int choice){		// starts the game, keeps game going until game is done
   int xWins =0;									// keep track of wins, losses, draws
   int oWins =0;
   int draws =0;   
   int input=0;
   if(choice==1)
   		cout << "You are X, computer is O" << endl;
   bool GameDone = false;	 //keeps game loop going until it is done
															 
	 int turn = chooseFirst(GameState);					// turn is guerenteed to be odd for x turns and even for o turns
 														// depending on who is first turn will start at 0 or 1		
	while(!GameDone){									//Using turn, we can guerentee who is next to play and whether the game is a draw.
	
	
 	turn +=nextTurn(GameState,turn,choice);				// will add to turn (therefore going to next turn) and update gamestate.
 	
if(checkWin(GameState) !=0 || turn == 10 || (GameState[0] == 0 && turn == 9) ){ 	// checks for winner and updates total count of winners
																					// draw number for turn is different if x or o goes first, 
																					//this is reflected in the if statement
 


if(checkWin(GameState)==1){		//fun fact: this block used to be a switch statement
xWins++;						// but for whatever reason, it didn't work
cout << "X Wins" << endl;}		//likely a sintax error somewhere, lol.
if(checkWin(GameState)==2){		// Instead of debuging, I said f--- it, I will just make 3 if statements, would be quicker
oWins++;						// and now this code updates the number of wins perfectly
cout << "o Wins" << endl;}		
if(checkWin(GameState)==0){		
draws++;
cout << "Draw" << endl;
}
 	
    input = gameOver(xWins, oWins, draws);	// starts gameOver sequence
	if(input == 3 || input == 4)	// clears number of wins if that was requested.
	{
	xWins = 0;
	oWins = 0;
	draws = 0;
	cout <<"Victory totals have been zeroed out, staring new game" <<endl;	
	}
	if(input == 2 || input == 4)		// gets out of current loop if current game will no longer be played
		GameDone = true;
	
	for(int i=0;i<10;i++)		// clear board after game
			GameState[i] = 0;		
 
if(input == 4)				// starts new game with different level 
{   int chocie =0;
	cout << "Select dificulity 1. easy 2. vs human 3. meduim 4. hard" << endl;
	cin >> choice;
	startGame(GameState,choice);
} 
if (input ==1 || input ==3)
turn = chooseFirst(GameState);			//select person to go first for next game

		}	
	}
}

int nextTurn(int GameState[],int turn,int choice){	// updates game state array with compter or player choice, depending on whose turn it is.
													// returns 1 if the choice is valid, 0 if it is not
int input=0;										// the turn in  startgame() will update based on return from this function 
int test =1;										// so turn will only move forward if a valid move is made

if(choice==1 && turn%2==0){		// chooses the first open square for computer
	cout<<"Computer is choosing as easy" <<endl;
	while (input==0)
		{
			if (GameState[test] ==0)
				input = test;
			test++;	
		}
	cout<< "Computer chose space " << input << endl;
 }




if(choice == 2 || turn%2 ==1){	//reads human choice for game
cout << "Please enter the number of the square you want to use" << endl;
cin >> input;
}

if(choice==3 && turn%2 ==0){ // computer selects random valid square
		input = medComp(GameState);
		cout<< " Medium computer chose space " << input << endl;
 
}

if(choice == 4&& turn%2==0){ // computer checks for victory, tries to win otherwise choses randomly
	
	input = hardComp(GameState);
	cout<< "Hard computer chose space " << input << endl;
 

}



if(GameState[input]==0){		// select to put down either x or o for move depending on whose turn it is
	if(turn%2==0)
	GameState[input] =2;
 else
	GameState[input] = 1;
	 

printStage(GameState);
return 1;	

}


else{					// prevent not allowed moves, does not move turn counter.
	
	cout << "Can't let you do that, illigal moves not allowed"<<endl;
printStage(GameState);
	return 0;
}

}
  	
void printStage(int GameState[]){	// prints out the stage with numbers in empty squraes,
										// x and o where they have been selected
 	string facing [10] = {"", "1","2","3","4","5","6","7","8","9",} ;
 	for (int i=0;i<10; i++)
 	{
 		if(GameState[i]==1)	//overwrite the values for the facing array with the relevent selection from the "real" game state
	 		facing[i] ="X";
 		if(GameState[i]==2)
	 		facing[i] ="O";
	}
 	
 	cout<<" " << facing[1] <<"  |  "<<facing[2]<<"  |  "<< facing[3] << endl; // print real state of the board
    cout << "---------------" << endl;
   cout<<" " << facing[4] <<"  |  "<<facing[5]<<"  |  "<< facing[6] << endl;
    cout << "---------------" << endl;
    cout<<" " << facing[7] <<"  |  "<<facing[8]<<"  |  "<< facing[9] << endl;
   
 	
 }
  
int checkWin(int GameState []){				// returns 1 if x win 2 if o win else 0
												// I am sure there is some fancy pants recursive statement that could do this in like 5 lines of code
												// It would be so beautiful it would make Alan Turing cry
												// If I was smart enough to see it, I wouldn't be in this class
												// I would be making 150 k a year working for microsoft :P
if( GameState[1]!=0 && GameState[2]==GameState[1] && GameState[3]==GameState[1])
{
	return GameState[1];
}
if(GameState[1]!=0 && GameState[4]==GameState[1] && GameState[7]==GameState[1])
{
	return GameState[1];
}
if(GameState[1]!=0 && GameState[5]==GameState[1] && GameState[9]==GameState[1])
{
	return GameState[1];
}

if(GameState[2]!=0 && GameState[5]==GameState[2] && GameState[8]==GameState[2])
{
	return GameState[2];
}
if(GameState[3]!=0 && GameState[6]==GameState[3] && GameState[9]==GameState[3])
{
	return GameState[3];
}

if(GameState[3]!=0 && GameState[5]==GameState[3] && GameState[7]==GameState[3])
{
	return GameState[3];
}
if(GameState[4]!=0 && GameState[5]==GameState[4] && GameState[6]==GameState[4])
{
	return GameState[4];
}
if(GameState[7]!=0 && GameState[8]==GameState[7] && GameState[9]==GameState[7])
{
	return GameState[4];
}

return 0;

}
  
int gameOver(int xWins, int oWins, int draws){	//desplays win count, returns selection for how to play next game or close out
	int input =0;
	cout<<"Game Over" <<endl;
	cout<<""<< endl;
	cout<<"Number of X wins:" << xWins << " Number of o Wins: " << oWins<< " Number of Draws:" <<draws<< endl;	
	cout << "Play Again? 1 = yes, 2 = no, 3 = clear wins record. 4= different opponent"<<endl;
	cin >> input;
	return input;
	
}	

int chooseFirst(int GameState[]){		// randomly selects what team will go first, sets GameState [0] to reflect choice. Returns update 
										//to turn so turn count is correct
			
	srand(time(NULL));
 	int chance = rand() %10  ;
 	while(chance>2)
 		chance/=2;
	if(chance == 2)
    {	GameState[0] =1;									// fun fact, this line used to be GameState[0]==1; caused so many bugs ;_;
    	cout << "For the next game, X will go first" << endl;
		return 1;
	}
    else{
	GameState[0] =0;
    cout<< "for the next game, O will go first" << endl;
   return 0;
   }

}
 
int medComp(int GameState []){				// returns random valid choice for computer move
 	int input =0;
 	int test = 0;
	 	srand(time(NULL));
	while(input == 0){
		test = (rand() %9) +1  ;
		if(GameState[test]==0)
			input= test;
		}
	return test;
}

int hardComp(int GameState[]){	// checks and tries to win if possible, otherwise tries to prevent loss, if not in danger of loosing, selects random
 int test;
 test = check(GameState, 2);	// ckecks to see if there are any winnning moves, returns that if there are.
 if (test ==0)
 	test = check(GameState,1); // if there are any moves that need to be made to avoid loss, selects them
	if(test == 0)
		test = medComp(GameState); // if no win or loss select randomly
	
	return test;
}

int check(int GameState [], int check){		// checks if game is near winstate for either sid, returns a winning or not loosing choice, otherwise returns 0
		int test = 0;
if( GameState[1]==0 && (( GameState[2] ==check && GameState[2]==GameState[3]) ||( GameState[4] ==check && GameState[4]==GameState[7]) ||( GameState[5] ==check && GameState[5]==GameState[9])))
	test = 1;
if( GameState[3]==0 && (( GameState[2] ==check &&GameState[2]==GameState[1])||( GameState[6] ==check && GameState[6]==GameState[9]) ||( GameState[5] ==check && GameState[5]==GameState[7])))
	test = 3;
if( GameState[7]==0 && (( GameState[8] ==check &&GameState[8]==GameState[9])||( GameState[4] ==check && GameState[4]==GameState[1]) ||( GameState[5] ==check && GameState[5]==GameState[3])))
	test = 7;
if( GameState[9]==0 && (( GameState[7] ==check &&GameState[7]==GameState[8])||( GameState[3] ==check && GameState[3]==GameState[6]) ||( GameState[5] ==check && GameState[5]==GameState[1])))
	test = 9;	
if(GameState[2]==0 && (( GameState[1] ==check &&GameState[1]==GameState[3] )||( GameState[5] ==check && GameState[5]== GameState[8])))
	test = 2;	
if(GameState[4]==0 && (( GameState[1] ==check &&GameState[1]==GameState[7] ) ||( GameState[5] ==check && GameState[5]== GameState[6])) )
	test = 4;	
if(GameState[6]==0 && (( GameState[9] ==check &&GameState[9]==GameState[3]) ||( GameState[5] ==check && GameState[5]== GameState[4])))
	test = 6;	
if(GameState[8]==0 && (( GameState[7] ==check &&GameState[7]==GameState[9]) ||( GameState[5] ==check && GameState[5]== GameState[2])))
	test = 8;	
if(GameState[5]==0 && (GameState[1]==GameState[9] || GameState[3]== GameState[7] || GameState[2]==GameState[8]|| GameState[4]==GameState[6]))
	test = 5;		
return test;	
	
}



