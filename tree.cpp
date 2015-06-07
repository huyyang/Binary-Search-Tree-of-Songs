
//tree.cpp

//This whole file contains the functions that will add into a tree, delete a 
//single node in a tree, display the whole tree, and will delete the whole
//tree. From what I've been experiencing, we HAVE to use wrapper functions 
//for all of our functions that are in this file because we cannot access
//the functions that are in our main without root. 

#include "tree.h"

using namespace std;

//constructor: initializing our root to NULL.
//initializing our starting tree to NULL
tree::tree()
{
	//allocates root to NULL
	//just so there are no segmentation
	//faults. Just like how you would
	//set head to NULL;
	root = NULL;
}

//destructor: deallocate ALL of our data after
//we are finished with it. This function will
//delete ALL of our data when we are finished
tree::~tree()
{
	//a function that removes all of the nodes in the tree
	//the function is made from the function called 
	//removeAll
	removeAll(root);
}

//this function removes all nodes from the tree
int tree::removeAll(node * & root)
{
	//if the tree is empty then just exit the program
	if(!root)
		return 0;

	//traverses all the way to the left and whatever
	//points to the left
	removeAll(root -> left);

	//traverses all the way to the right and whatever
	//points to the right
	removeAll(root -> right);

	//deletes the root
	delete root;

	//root has to be NULL every single time something
	//is deleted.
	root = NULL;

	//everything is recalled again because we are calling
	//the recursive call 
}

//the wrapper function that will delete the user's chosen
//song and will delete the whole song in the binary
//search tree
int tree::deleteChosenMatch(char * songFinder)
{
	//the recursive function call that will
	//delete the user's decided song title and that
	//will delete all of the song's artist, album.
	//minutes and number of extractions
	deleteChosenMatch(root, songFinder);
}

//the user is going to input a song title and if the song
//title exists in the song class, it will return true
//if not, it will return false which is 0;
int tree::deleteChosenMatch(node *& root, char * songFinder)
{
	//if root is empty, then just leave the program
	if(!root)
		return 0;

	//if this match exists, then it will go onto the
	//next step in the code
	if(strcmp(songFinder, root -> title) == 0)
	{
		//calls the function remove match
		//in which removes a match the 
		//character chooses
		remove(root);
		
		//will leave the program because you don't 
		//want to be going in a loop of recursive
		//calls in which is not needed
		return 1;
	}
	//if the user comparison is not the same as the title
	//we will recall the recursive traversal
	else 
	{
		//recursive call that will check the right
		deleteChosenMatch(root -> right, songFinder);

		//recursive call that will check the left	
		deleteChosenMatch(root -> left, songFinder);
	}
}


//remove whatever match the user wants to remove
int tree::remove(node * & root)
{
	//if the tree is empty
	//if root is equal to NULL
	//then exit the program
	if(!root)
		return 0;

	//if the item we want to delete is a node with no parents
	//as in a leaf. Leaf: The ones at the end, has no children
	if(root -> left == NULL && root -> right == NULL)
	{
		//deletes the root that we are at 
		//according to where we are due to our
		//condition
		delete root;

		//we have to set root back to NULL or else
		//we will have a segfault. It will be unconnected
		//if root is not NULL
		root = NULL;
	}

	//if an inside node (not a leaf) has only 1 child pointer
	//and one pointer is NULL
	else if(root -> left != NULL && root -> right == NULL)
	{
		//we make a temporary pointer to point to the
		//next left node from where we are at due to our
		//if condition. We want to hold on to the node
		//so we can connect back up later
		node * temp = root -> left;

		//deletes the root that we are at according
		//to where we are due to our condition
		delete root;

		//we are connecting back up at the node that we
		//set temp to so we can connect back up to our 
		//tree. Otherwise we will segfault
		//1) because there is no NULL pointer
		//2) because it won't be a full tree and there
		//will be no NULL pointer
		root = temp;
	}

	//if the root left is pointing to NULL and our root right
	//is NOT null, this if statement occurs
	else if(root -> left == NULL && root -> right != NULL)
	{
		//have a temporary pointer point to the next
		//right node from where we are at due to our
		//if condition. We want to hold on to the node
		//so we can connect back up later
		node * temp = root -> right;

		//deletes the root that we are ataccording to
		//where we are due to our condition
		delete root;

		//we are connecting back up at the node that
		//we set temp to so we can connect back up to our
		//tree. Otherwise we will segfault
		//1) because sthere is no NULL pointer
		//2) because it wont be a full tree and there
		//will be no NULL pointer
		root = temp;
	}
	
	//this is the condition where when we're deleting a node
	//from our tree, the node has both the left child and 
	//the right child in which we have to use traversal 
	//iteratively to grab the next ordder successor node,
	//grab that and copy that into our node we want to delete.
	//So technically we don't want to delete our node we
	//just want to switch the nodes with each other
	else if(root -> left != NULL && root -> right != NULL)
	{
		//we make a temporary pointer that will point to
		//the right of the node we want to delete 	
		node * current = root -> right; 

		//make a previous pointer in which will later
		//follow temp and will stray behind it
		node * previous = root;

		//we traverse down the tree all the way down to
		//the next inoder successor
		while(current -> left)
		{
			//have previous be equal to temp while
			//traversal because we want it to stray
			//behind temp
			previous = current;

			//we traverse all the way down to the left
			//inorder successor
			current = current -> left;
		}
		//if there are no left pointers in our current
		//so that means if previous is AT root or if
		//we aren't even traversing the tree then the
		//condition will change
		if(previous == root)
		{
			//make a temp equal current right
			node * temp = current -> right;

			//have the previous right be equal to temp
			previous -> right = temp;
		}
		//or else
		else
		{
			//have the temp be equal to the current right
			node * temp = current -> right;

			//have the previous left be equal to temp so 
			//that they will connect
			previous -> left = temp;
		}

		//copies the current to our root instead of deleting it
		root -> songObject = current -> songObject;

		//also copies in the key in which is the title
		root -> title = current -> title;

		//we need to delete the current because it is the inorder
		//successor
		delete current;
	}
}

//This is the wrapper function to insert a node into
//the binary search tree
int tree::insert(song * add)
{
	//recalls the function again because we cannot
	//call root in main
	insert(root, add, add -> copySongName());
}

//The insert function for our binary search tree. A song title is
//passed in and it returns our character. That character will be
//compared with the current character in the node. 
int tree::insert(node *& root, song * adding, char * title)
{
	//if the root is NULL. This is the recursive call
	//that we will actually use to actually add to our
	//binary search tree
	if(!root)
	{
		//have root be a new node
		root = new node;

		//add our class variables from our private section
		//into this new node
		root -> songObject = adding;

		//have root left and root right
		//both point to NULL
		root -> left = root -> right = NULL;

		//adds the title name into our node in which holds 
		//a title
		root -> title = new char[strlen(adding -> copySongName()) + 1];

		//string copies the passed in songName into our struct node
		//in this case we can compare to the other nodes later
		//through string compare. Because string compare will return
		//an integer, and that integer determines where that node
		//will be placed
		strcpy(root -> title, adding -> copySongName());
			
		//we return 1 because we want to continue with the program
		return 1;
	}
	else
	{

		//We string compare our passed in song name, with our
		//current title that is inside our node and we see if
		//the returned value when string comparing the two
		//song titles is bigger or equal to 0
		if(strcmp(adding -> copySongName(), root -> title) >= 0)
		{
			//we call the recursive call to go back up to our 
			//tree and the condition for (!root) occurs again
			insert(root -> right, adding, title);
		}

		//We string compare our passed in song name, with our current
		//title that is inside our node and we see if the returned
		//value when string comparing the two song titles is less
		//than or equal to 9
		else if(strcmp(adding -> copySongName(), root -> title) < 0)
		{
			//we call the recursive call to go back up to our tree
			//and the condition for (!root) occurs again when
			//you hit the left null pointer
			insert(root -> left, adding, title);
		}			
	}
}



//the wrapper function for the display chosen whatever the user wants
int tree::displayChosen(char * userResponse)
{
	//calling the display function 
	displayChosen(root, userResponse);
}

//will display whatever the user wants. This is similar to the
//retrieve function in which will display true if it is a 
//match or will display false if it isnt a match but in this
//case, if the match is true, we will actually display the ONE
//node in which the root is pointing to using recursion
int tree::displayChosen(node * root, char * userResponse)
{
	//if the root is NULL we will leave the program
	if(!root)
		return 0;

	//if the user Response and the key is proven to
	//be true then we will display that node. If it 
	//is equal to 0 then that means it is a match
	if(strcmp(userResponse, root -> title) == 0)
	{
		//root will be pointing to the display
		//using recursion and will display
		//whatever the userResponse and the key
		//is equal
		root -> songObject -> display();

		//will return true and leave just the function
		//when we display 
		return 1;
	}
	//if it is not true we will traverse
	else
	{
		//we will traverse to the right using recursion
		displayChosen(root -> right, userResponse);

		//we will traverse to the left using recursion
		displayChosen(root -> left, userResponse);
	}
}

//the wrapper function that is apart of our display function
//in which doesn't take any arguments.
int tree::display()
{
	//calls the function to display 
	//this is a wrapper function
	display(root);
}

//displays our whole binary tree in recursion
int tree::display(node * root)
{
	//if the binary tree is empty, then just exit the program
	if(!root)
		return 0;

	//if the binary tree is NOT empty, then we will display all
	//of our WHOLE binary tree through recursion
	else
	{
		//Displays inorder, not postorder, not preorder
		//traverses to the left and will keep on traverseing
		//to the left until it reaches NULL to all of the left
		display(root -> left);

		//displays just ONE node of our song class but that's
		//what traversing through the nodes recursively is for.
		//it wont just display JUST this one node. Because we 
		//are travering through every node, we will display 
		//evverytime a node is being touched (true).
		root -> songObject -> display();
	
		//it will traverse to the right and will keep on traversing
		//to the right until it reaches NULL to all of the right
		//nodes from the subtrees and also the leaves
		display(root -> right);
	}
}


