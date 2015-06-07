
//assignment #4

//fileExtract.cpp

//This file is the .cpp that is related to the fileExtract.h
//file. This file contains the constructor, destructor and 
//a txt file read in function. The readIn function will read
//in from a .txt file and will also display the text in the
//the .txt file. The readIn function will NOW save our data
//in which that was not saved from assignment #3 because last
//time we couldn't save our data. Now that ive made a temporary
//pointer in my main function we are now saving our data

//we include our .h file that is where our class is
#include "fileExtract.h"

//the constructor. We initialize each variable from our class
//to anything we want. Just variables
song::song()
{
	//initializes songName to a new char array
	songName = new char[SIZE];
		
	//initializes artist to a new char array
	artist = new char[SIZE];
	
	//initializes album to a new char array
	album = new char[SIZE];	

	//initializes intiger minutes to 0
	minutes = 0;
	
	//initializes integer extractions to 0
	extractions = 0;

	//we need the words in the title to start at 0
	wordsInTitle = 0;
}

//the destructor for the file extracting
//class. Deallocate all the data members
//in the class
song::~song()
{
	//deallocate the char * songName
	delete [] songName;
			
	//deallocate the char * artist
	delete [] artist;

	//deallocate the char * album
	delete [] album;

	//we initialize minutes to 0
	minutes = 0;

	//we initialize the number of extractions 
	//to 0
	extractions = 0;

	//we initialize the words in the title to 0
	wordsInTitle = 0;		
}

//reads in from the file called song.txt 
//in the song.txt there is a list of songs,
//artist, album numbs, minutes and 
//number of extractions that the user has 
//made
int song::readIn(ifstream &file)
{
	
	//gets the song name in which is a pointer
	//to a pointer. We are doing arrays of arrays
	//for just the song title
	file.get(songName, (SIZE - 1), ';');
	file.ignore(100, ';');	
	
	//we get the artist name
	file.get(artist, (SIZE - 1), ';');
	file.ignore(100, ';');

	//gets the album name
	file.get(album,(SIZE - 1), ';');
	file.ignore(100, ';');

	//gets the number of minutes
	file >> minutes;
	file.ignore(100, ';');

	//gets the number of extractions that the user has made
	file >> extractions;
	file.ignore(100, '\n');

	//returns 1 because we dont want to quit yet
	return 1;
		
}

//displays the song name, artist, album, minutes and extractions
//for each of the songs that have been asked and for how many
//songs there are in the list. 
char song::display()
{
	cout << '\n' << endl;
	//displays the song name through a for
	//loop because this is a character of arrays
	//in which we have made to look for each of the song
	//class data members
	cout << "Song name: " << songName << endl;
	
	//display the artist, album, minutes and extracitons
	cout << "Artist : " << artist << endl;
	cout << "Album : " << album << endl;
	cout << "Minutes: " << minutes << endl;
	cout << "Extractions: " << extractions << endl;
}

//a double character function that correcsponds to the 
//index of one of the 10 song names in our songs.txt
//this function was here just to pass in the songName
//so I could get the size of it. The reason why I want
//to return the songName was because I could not grab it
//due to the fact that it was a private data member. Returned
//the songName so we can use it in our global functions
char * song::copySongName()
{
	//returns the songName so I could get the size
	//if it for the hashTable
	return songName;
}

//an integer function that will return how many words
//were in the song title. This was needed for the 
//data member wordsInTitle because since it was a private
//data member, I could not access it through main,
//and now I can
int song::displayWordsInTitle()
{
	//return the number of the words in the title
	return wordsInTitle; 
}
