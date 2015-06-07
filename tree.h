//Huy Yang (Huy Yanhs), Professor Karla Fant, Computer Science 163, 11/20/2014

//tree.h

//assignment #4

//This is our tree.h. It is connected to our song class and we want to 
//pass our song class into our node because one song class is basically a node.
//This is where we will be making our binary tree. Each node will be a node
//for a binary search tree (inorder) in which will display all of the binary
//search tree, will display one node from the binary search tree, will delete
//one from the binary search tree, and will delete all along with assigning
//all the variables from the constructor and destructor of the binary search
//tree 

//we need to be able to include our fileExtract file because that is where
//our song class is. Our song class contains 5 variables which is our songName,
//artist name, album name, minutes and extractions in which we need to
//display and store into our class, and that class is stored into our node
#include "fileExtract.h"

//a struct node in which we need to store our values in. I passed the song
//class into my node so we can store our data into it. I made a char pointer
//in the node also because I want to be able to store each song title in
//every one of my node. We automatically make this our binary tree because
//we have two pointers 
struct node
{
	//passes in a songObject by pointer so we can store each song
	//variables into our class, in which is stored into our node
	song * songObject;

	//holds the title of each song section
	char * title;

	//a right pointer in our binary tree
	node * right;

	//a left pointer in our binary tree
	node * left;
};

//a class for our binary search tree in which will store the node
//into our binary tree class which is why the "root pointer" is in
//our private section of the class. That "root pointer" represents
//ONE node from our struct node class
class tree
{
	public:
		//constructor: allocates each memory
		tree();

		//deallocates: deletes all of the memory at the end
		//of the program
		~tree(); 

		//inserts a node into our binary search tree at the
		//end of our leaves having each of the children leaf
		//now become a subtree, making them have a child
		int insert(node *& root, song * adding, char * title); 
	
		//a wrapper function for the insert function in which
		//takes in 3 arguments. One of the reasons why I have a 
		//wrapper function is because I cannot define root in main
		int insert(song * add);		
	
		//will display all of our binary tree
		int display(node * root); 

		//A wrapper function for our function display(node * root).
		//One of the reasons why I have a wrapper function is because
		//I cannot define root in main
		int display(); 

		//removes our selected tree
		int remove(node * & root);

		//the user will delete a song from their input from main
		int deleteChosenMatch(node *& root, char * songFinder);

		//this is the wrapper function to delete the match
		int deleteChosenMatch(char * songFinder);

		//the user will display a song from their input from main
		int displayChosen(node * root, char * userResponse);
		
		//this is the wrapper function to display the match
		int displayChosen(char * userResponse);
		
		//removes all of our binary search tree. This function
		//is for our destructor. We will get a segfault
		//if just call it now
		int removeAll(node * & root);

	private:
		//its like our head pointer but it is
		//starting at the top, but the head 
		//pointer will point at one node. instead
		//the root will point at 2 nodes. and those
		//2 nodes will point at another 2 nodes
		//and so on
		node * root;
};
