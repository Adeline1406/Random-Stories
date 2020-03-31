//Header file for Assignment 1
//Guards
#ifndef HEADER_H
#define HEADER_H

//Declaration
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>
using namespace std;
void main();
int runMenu();
void displayInfo(string filename);
void createLists(string fileName);
void generateStoryLine();
int saveStoryData();
void loadStoryData();

#endif // !HEADER_H