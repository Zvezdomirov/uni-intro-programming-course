/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Zahari Zvezdomirov
* @idnumber 62216
* @task 1
* @compiler VC
*
*/

#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>

int main()
{
	const int letterHeight = 5;
	const int letterWidth = 5;
	const int wordLength = 5;
	const int verticalEmptyRows = 25 - (letterHeight * 2);
	const char* spaceBetweenLetters = "   ";
	
	const char* hLetter[] = {	"H   H",
								"H   H",
								"HHHHH",
								"H   H",
								"H   H" };
	const char* eLetter[] = {	"EEEEE",
								"E    ",
								"EEEEE",
								"E    ",
								"EEEEE" };
	const char* lLetter[] = {	"L    ",
								"L    ",
								"L    ",
								"L    ",
								"LLLLL" };
	const char* oLetter[] = {	"  O  ",
								" O O ",
								"O   O",
								" O O ",
								"  O  " };
	const char* sp[] = {		"     ",
								"     ",
								"     ",
								"     ",
								"     " };

	const char** helloWord[] = { sp, sp, sp, sp, sp, 
								hLetter, eLetter, lLetter,
								lLetter, oLetter, sp };

	int m, printCount;
	for (int i = (wordLength * 2); i >= 0; i--)
	{
		for (int p = 0; p <= verticalEmptyRows; p++)
		{
			std::cout << "\n";
		}
		m = i;
		for (int j = 0; j < letterHeight; j++, m = i)
			{
			printCount = 0;
			while (m < wordLength * 2 && printCount < wordLength)
			{
				for (int k = 0; k < letterWidth; k++)
				{
					std::cout << helloWord[m][j][k];
				}
				m++;
				printCount++;

				std::cout << spaceBetweenLetters;
			}
				std::cout << std::endl;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(800));
		std::system("CLS");
	}

}
