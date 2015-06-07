//Huy Yang (Huy Yanhs, Computer Science 163, Karla Fant

//assignment #4

//main.cpp

//This file is supposed to ask the user whether they
//want to look at all the songs, delete any of the songs and
//display just one song according to their response

//we want to include our tree file. That is where all our
//nodes are stored and we would want to be able to call
//the functions in our main function
#include "tree.h"

using namespace std;

//prototypes
//ReadSong reads in from our tree class and will readin
//from our songs.txt file in which will store each of
//the artist, album, minutes, extractions, and song names
//into our song class. Each song class is a node and that
//node will be set into our tree in the tree class in whic
//that is in our tree.cpp file
void readSong(tree & addTree, song *& temp);

//we will call each and every function in this main function
//will return 0 when we want to leave
int main()
{
	//makes a song instance of 10 songs.This is our
	//first step to adding into our binary tree
	song * temp = new song[10];

	//make an instance of a class so we can call the
	//function from the tree class
	tree treeFunctionCall;

	//variables only for user responses
	int response;
	char response2 = 'Y';
	
	//we will read in from the song class file
	//and we will store each song variable in our 
	//song class and that is from the songs.txt file
	readSong(treeFunctionCall, temp);
	
	//a do while is added so we can ask the user if
	//they want to redo this whole program again and that
	//is from the character response2 variable
	do
	{
		cout << '\n' << endl;
		cout << "You have the option to display all the songs" << endl;
		cout << "display a single song, delete a single song," << endl;
		cout << "or exit the program" << endl;
		cout << '\n' << endl;
		cout << "You can pick your response through the" << endl;
		cout << "corresponding numbers" << endl;
		cout << '\n' << endl;
		cout << "(1) Display all songs" << endl;
		cout << "(2) Display a single song" << endl;
		cout << "(3) Delete a single song" << endl;
		cout << "(4) Exit the program" << endl;
		cout << '\n' << endl;
		cin >> response;
		cin.ignore(100, '\n');

		//readSong(treeFunctionCall, temp);

		//if the user response is 1 we will display all of our data
		//in our binary search tree
		if(response == 1)
		{
			//char variable for the user response
			char response = 'Y';
			
			cout << "Here are your songs by alphabetical title order" << endl;

			cout << '\n' << endl;

			//displays from our binary search tree in alphabetical order
			treeFunctionCall.display();
			
			cout << '\n' << endl;
		}	
		//if the user response is 2 we will display a single song
		//as requested by the user
		else if(response == 2)
		{
			//we make a dynamically allocated array to ask the user what they want
			//to display from our binary search tree
			char * response = new char[50];

			cout << "Type in a song title that you want to singly display" << endl;
			cout << "The song title that you pick will be singly displayed" << endl;
			cout << "along with the rest of its contents such as artist name" << endl;
			cout << "album name, number of minutes and number of extractions" << endl; 
			cout << "Ex: The Cool Song" << endl;
			cout << '\n' << endl; 
			cout << "Remember to capitalize the first letters of the song title" << endl; 
			cout << '\n' << endl;
			cout << "Note: You have to display all first in order to display singly" << endl;
			cout << "because when you display all you are also importing your songs" << endl;
			cout << "so display all first before you display singly or else nothing" << endl;
			cout << "will display" << endl;
			cout << '\n' << endl;
			cin.get(response, 50, '\n');
			cin.ignore(100, '\n');

			//The user will enter in a song title and we will pass that in into our 
			//displayChosen function in which will retrieve our song and the rest of
			//our items in our binary search tree 
			cout << '\n' << endl;
			cout << "Here is the song that you have chosen" << endl;
			treeFunctionCall.displayChosen(response);
			cout << '\n' << endl; 

		}

		//If the user response is 3, we will delete a single song
		//as requested by the user
		else if(response == 3)
		{
			//makes a dynamically allocated array in which will ask the user for 
			//a song title in which wiill be retrieved from our binary search tree
			char * res = new char[50];

			cout << "Type in the song song title that you want to singly delete" << endl;
			cout << "Warning: the song title that you pick will be deleted" << endl;
			cout << "Ex: The Cool Song" << endl;
			cout << '\n' << endl;
			cout << "Remember to capitalize the first letters of the song title" << endl;
			cout << '\n' << endl;
			cout << "Note: you have to display all first in order to display singly" << endl;
			cout << "because when you display all you are also importing your songs" << endl;
			cout << "so display all first before you delete singly or else nothing" << endl;
			cout << "will be deleted" << endl;
			cout << '\n' << endl;
			cin.get(res, 50, '\n');
			cin.ignore(100, '\n');

			//calls the retrieve function that will delete the chosen match
			//calling from the user
			treeFunctionCall.deleteChosenMatch(res);

			cout << '\n' << endl;
			cout << "Your song has been deleted" << endl;
			cout << "Go check by displaying over again" << endl;
			cout << '\n' << endl; 
		}
		//if the user response is 4, we will end our program
		//and leave our program with a goodbye
		else if(response == 4)
		{
			//will return 0 which will mean the code is done
			cout << "Goodbye" << endl;
			return 0;
		}
		//asks the user if they want to redo this whole program again
		//asking them if they want to select some more options
		cout << "Would you like to select some more options?" << endl;
		cout << "Type in (y) for yes, or (n) for no" << endl;
		cin >> response2;
		cin.ignore(100, '\n');

	//while the response2 is y, we will continue our flow of the program
	//but if the user types in anything else, we will exit our program
	}while(toupper(response2) == 'Y');

	//we exit our program through returning false
	return 0;
}

//a global function that reads in from the song class file
//and also passes in the private values into a new node
//and also calls the tree class function and passes that
//node and adds them up into a data tree
void readSong(tree & addTree, song *& temp)
{
	

	//ifstream calls an instance of the file
	ifstream file;

	//opens up the file in the song.txt
	file.open("songs.txt");

	//makes a space in terminal
	cout << '\n' << endl;

	//uses a for loop to go through 
	for(int i = 0; i < 10; ++i)
	{
		//calls the readIn file from the song class
		//and will read in from the songs.txt file
		//in which will 
		temp -> readIn(file);
	
		//Each temporary pointer that is passed in, will be
		//passed into our insert function, and that will
		//insert each song object, into a node, and each
		//node will be inserted into our binary search tree
		addTree.insert(temp);

		//increments temp each time because we need it to
		//go to the next temporary pointer
		++temp;

		cout << '\n' << endl;
	}
	//closes our file because we will get a segmentation fault
	file.close();

}
