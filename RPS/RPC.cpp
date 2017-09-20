#include <iostream>
#include <ctime>
using namespace std;

const int MAX_ROUNDS = 20;  // max rounds per game

enum Player { HUMAN, COMPUTER, TIE };   // players and winners
enum Thing  { ROCK, PAPER, SCISSORS };  // what each player chooses

void record_win( /***** Complete this declaration. *****/ );

/***** Add more function declarations. *****/

/**
 * The main. Play a game consisting of MAX_ROUNDS.
 * Print the number of human player wins, computer wins, and ties.
 */
int main()
{
    int human_wins = 0;
    int computer_wins = 0;
    int ties = 0;

    srand(time(NULL));  // seed the random number generator

    /***** Complete this main. *****/

    return 0;
}

void record_win( /***** Complete this function. *****/ )
{
	int RECORD_WIN_FUNCTION(int human_wins, int computer_wins, int ties)
	{
		cout<<"SUMMERY"<<endl;
		cout<<"-------"<<endl;
		cout<<"Human Wins: "<<human_wins<<endl;
		cout<<"Computer wins :"<<computer_wins<<endl;
		cout<<"Ties: "<<ties<<endl;

		return 0;
	}




}

/***** Define more functions. *****/

















// Name : Avadh Boriya
// SID  : 011487242


#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>


using namespace std;

int HUMAN_CHOICE_FUNCTION(string Human_Choice);
string RANDOM_NUMBER_FUNCTION(int User_Input);
int WINNER_FUCTION(int User_Input, int Computer_Choice);
int RECORD_WIN_FUNCTION(int human_wins, int computer_wins, int ties );



int main()

{



				string Input;
				cin>>Input;
			HUMAN_CHOICE_FUNCTION(Input);




	return 0;

}


// TO GET USER INPUT

int HUMAN_CHOICE_FUNCTION(string Human_Choice)
{

	int User_Input;

	cout<<"YOUR CHOICE?"<<endl;



	if(Human_Choice == "R" || Human_Choice == "r")
	{
		cout<<"YOU CHOSE ROCK." << endl ;
		User_Input=1;
		RANDOM_NUMBER_FUNCTION(User_Input);


	}

	else if(Human_Choice == "P" || Human_Choice == "p")
		{
			cout<<"YOU CHOSE PAPER."<< endl ;
			User_Input=2;
			RANDOM_NUMBER_FUNCTION(User_Input);

		}

	else if(Human_Choice == "S" || Human_Choice == "s")
		{
			cout<<"YOU CHOSE SCISSOR." << endl ;
			User_Input=3;
			RANDOM_NUMBER_FUNCTION(User_Input);

		}

	else
	{
		cout<<"***ERROR : Valid Choices are R, P, or S ";
	}

	return User_Input;

}


//to generate computer choice

string RANDOM_NUMBER_FUNCTION(int User_Input)
{
	int Computer_Choice;

	srand(time(0));

	Computer_Choice=(rand()% 3) + 1; // generates random number


	switch(Computer_Choice)
	{

	case 1: cout<<"The Computer Chose ROCK."<<endl;
			WINNER_FUCTION(User_Input,Computer_Choice);
			break;

	case 2: cout<<"The Computer Chose PAPER."<<endl;
			WINNER_FUCTION(User_Input,Computer_Choice);
			break;

	case 3: cout<<"The Computer Chose SCISSOR."<<endl;
			WINNER_FUCTION(User_Input,Computer_Choice);
			break;


	}

	return NULL;

}


int WINNER_FUCTION(int User_Input, int Computer_Choice)
{
	int human_wins=0;
	int computer_wins=0;
	int ties=0;

	cout<<User_Input<<endl;
	cout<<Computer_Choice<<endl;

	if((User_Input==1 && Computer_Choice==3) || (User_Input == 2 && Computer_Choice == 1) || (User_Input == 3 && Computer_Choice == 2))
	{
		human_wins+=1;
		cout<<" The winner is you."<< endl;
		RECORD_WIN_FUNCTION(human_wins, computer_wins, ties);

	}

	else if((User_Input==1 && Computer_Choice==1) || (User_Input == 2 && Computer_Choice == 2) || (User_Input == 3 && Computer_Choice == 3))
	{
		ties+=1;
		cout<<"It's a Tie."<<endl;
		RECORD_WIN_FUNCTION(human_wins, computer_wins, ties);
	}

	else
	{
		computer_wins+=1;
		cout<<"The winner is the computer"<<endl;
		RECORD_WIN_FUNCTION(human_wins, computer_wins, ties);
	}
		return 0;
}


