/**
*

* Solution to homework task 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Zahari Zvezdomirov
* @idnumber 62216
* @task 2
* @compiler vc
*
*/

#include <iostream>
#include <climits>
#include <cmath>

int main()
{
	long long input = 0, temp = 0;
	short int containedDigit = 0, occurenceCount = 0;
	bool inputIsCorrect = false;

	do
	{
		std::cout << "Enter a number and a digit you are looking for: " << std::endl;
		std::cin >> input;
		std::cin >> containedDigit;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Don't play with me! This input is invalid and you know it." << std::endl;
		} 
		else inputIsCorrect = true;

	} while (!inputIsCorrect);

	containedDigit = abs(containedDigit);
	temp = abs(input);
	while (temp > 0)
	{
		if (temp % 10 == containedDigit) occurenceCount++;

		temp /= 10;
	}

	std::cout << "The digit " << containedDigit << " occurs " <<
		occurenceCount << " times in " << input << ", nigga!";

	return 0;
}
