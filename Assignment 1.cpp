/*
Full Name		: Adeline Soerjonoto
Student ID		: 30849756
Units			: MCD4720 - Fundamentals of C++
Date Created	: 10 / 7 / 2019
Last Updated	: 24 / 7 / 2019
Lecturer Name	: Haidar AL-Khalidi
Lab Teacher Name: Mehran Vahid
Lab No.			: MCD4720 Laboratory 07-P1
Lab Time		: Wednesday, 1:00pm - 3:30pm
Desciption		:
This program is for Assignment 1 MCD4720 (Due Date 24 July 2019)
It displays information, creates a random story then saves and loads it.
*/

// Include all the header from file Header.h
#include "Header.h"

// Declaration for vector and string in global scope
vector <string> settings;
vector <string> characters;
vector <string> situations;
string storySetting, storyCharacter, storySituation;

//main
/*
Function Name	= main()
Input(s)		= none
Output(s)		= none
Descriptions	=
To run the runMenu()
*/
void main() {
	// the main fuction will run the runMenu and display the menu 
	runMenu();
}

//Menu
/*
Function Name	= runMenu()
Input(s)		= user option (opt)
Output(s)		= none
Descriptions	=
Function for displaying the Menu for the user to choose an option and run a function
*/
int runMenu() {
	char opt;
	
	while (true) {
		system("CLS"); // Clear the screen

		//The Menu Display 
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" << endl;
		cout << "	    The Amazing Story Generator			     \n" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" << endl;
		cout << "    [0] End Tasting Program" << endl;
		cout << "    [1] Display About Information" << endl;
		cout << "    [2] Read and store data from file" << endl;
		cout << "    [3] Generate a random story line " << endl;
		cout << "    [4] Save a story line to file " << endl;
		cout << "    [5] Load saved story lines from lines \n" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" << endl;
		cout << "  Which option would you like (0-5) : ";
		cin >> opt; // user choose an option
		cout << endl;

		//Option Result
		switch (opt) {
			case '0': return 0; break;  // option [0] The program will End
			case '1': displayInfo("StoryAbout.txt"); break; // option [1] The About Information will be displayed
			case '2': 
				createLists("SettingsData.txt"); 
				createLists("CharactersData.txt");
				createLists("SituationsData.txt");
				system("pause");
				break; // option [2] The data from each text file will put into a vector
			case '3': generateStoryLine(); break; // option [3]
			case '4': saveStoryData(); break; // option [4]
			case '5': loadStoryData(); break; // option [5]
			default: cout << "    Invalid option, choose between 0 until 5 \n"<<endl; system("pause");// If the option is not between 0-5
		}
	}
	return 0;
}

//Option [1]
/*
Function Name	= displayInfo()
Input(s)		= none
Output(s)		= Information from filename (StoryAbout.txt)
Descriptions	=
Function for displaying about the information from StoryAbout.txt
*/
void displayInfo(string filename) {
	ifstream storyText;
	string story;

	//Open the file and display
	storyText.open(filename);
	while (!storyText.eof()) {
		getline(storyText, story);
		cout << story << endl;
	}
	storyText.close();

	system("pause");
}

//Option [2]
/*
Function Name	= createLists()
Input(s)		= 3 vector (settings, characters, situations)
Output(s)		= none
Descriptions	=
Function for storing the data from text file (filename) into vector.
Stored data from SettingsData.txt into settings
Stored data from CharactersData.txt into characters
Stored data from SituationsData.txt into situations
*/
void createLists(string fileName) {
	ifstream storyFile;
	string line;
	cout << "     Data loading from " << fileName << "\n";
	cout << "     Data stored in variable. \n" << endl;

	//Input the data from each file into a vector
	storyFile.open(fileName);
	while (!storyFile.eof()) {
		getline(storyFile, line);
		if (fileName == "SettingsData.txt") {
			settings.push_back(line); // putting the data from SettingsData.txt to vector -> vSettings
		}
		else if (fileName == "CharactersData.txt") {
			characters.push_back(line); // putting the data from CharactersData.txt to vector -> vCharacters
		}
		else if (fileName == "SituationsData.txt") {
			situations.push_back(line); // putting the data from SituationsData.txt to vector -> vSituations
		}
		else {
			cout << "Error" << endl;
		}
	}
	storyFile.close();

	//To check if the vector is filled or empty
	/*for (int i = 0; i < settings.size(); i++)
	{
		cout << settings[i]<< endl;
	}
	*/
}

//Option [3]
/*
Function Name	= generateStoryLine()
Input(s)		= none
Output(s)		= a story by picking a random line from each 3 vector 
Descriptions	=
Function to generate and display a story by randomly pick a line from each vector.
The randomly line from settings is put into storySetting.
The randomly line from characters is put into storyCharacter.
The randomly line from situations is put into storySituation.
*/
void generateStoryLine() {
	int randSet, randChr, randSit;
	srand(time(0));
	
	if (settings.empty() && characters.empty() && situations.empty()) {
		// The vector is empty, to fill it the createLists function is needed to be run first by pressing option 2
		cout << "  You need to press option 2 first" <<endl; 
		cout << endl; 
	}
	else {
		//Choose random number to get a random line from vector
		randSet = rand() % 20;
		randChr = rand() % 25;
		randSit = rand() % 24;
		cout << "   " << settings[randSet] << endl;
		cout << "   " << characters[randChr] << endl;
		cout << "   " << situations[randSit] << endl;
		cout << endl;
		storySetting = settings[randSet];
		storyCharacter = characters[randChr];
		storySituation = situations[randSit];
	}
	
	system("pause");
}

//Option [4]
/*
Function Name	= saveStoryData()
Input(s)		= save the random story into a file
Output(s)		= none
Descriptions	=
Function to save the story that generate randoml.
The random story from generateStoryLine() is displayed and saved into SavedStories.txt
*/
int saveStoryData() {
	char ans;
	ofstream storySave;

	if (storySetting == ""  && storyCharacter == "" && storySituation == "" ) {
		// The story has not been generated yet, to fill it press option 2 and 3 to start the function to generate a random story
		cout << "    You have not generate a random story, " << endl;
		cout << "    press option 2 and 3 to generate a story \n" << endl;
	}
	else {
		//The story from random generator 
		cout << "   " << storySetting << endl;
		cout << "   " << storyCharacter << endl;
		cout << "   " << storySituation << endl;

		cout << "\n  Do you want to save this story ? (y/n) : ";
		cin >> ans;

		//To save or not save the story into the file
		if (ans == 'y' || ans == 'Y') {//The story from will be saved in SavedStories.txt 
			storySave.open("SavedStories.txt", ios::app);
			storySave << storySetting << endl;
			storySave << storyCharacter << endl;
			storySave << storySituation << endl;
			storySave <<endl;
			storySave.close();
			cout << "\n       This story is saved \n " << endl;
			
		}
		else if (ans == 'n' || ans == 'N') {//The story from will not be saved in SavedStories.txt 
			cout << "\n     This story is not saved, you  can choose other option \n "<<endl;
		}
		else {//The user does not input y , Y, n, or N
			cout << "\n      Choose between (y/n)  \n "<<endl;
		}
	}
	system("pause");
	return 0;
}

//Option [5]
/*
Function Name	= loadStoryData()
Input(s)		= none
Output(s)		= the story that have been save in text file
Descriptions	=
Function to load the all data (story) from SavedStories.txt and display it.
*/
void  loadStoryData() {
	ifstream storyLoad;
	string load;
	cout << "   The saved stories from file : \n "<<endl;

	//Load all the data in SavedStories.txt
	storyLoad.open("SavedStories.txt");
	while (!storyLoad.eof()) {
		getline(storyLoad, load);
		cout << "   " << load << endl;
	}
	storyLoad.close();
	 
	system("pause");
}

//End of the project