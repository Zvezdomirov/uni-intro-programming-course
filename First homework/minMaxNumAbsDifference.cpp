/**
*

* Solution to homework task 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Zahari Zvezdomirov
* @idnumber 62216
* @task 1
* @compiler vc
*
*/

#include <iostream>
#include <climits>
#include <limits>
#include <cmath>

int main()
{
	unsigned short minVal = USHRT_MAX, maxVal = 0, inputCount = 0;
	int currVal = 0;
	bool inputIsEmpty = true;
	std::cout << "Enter a sequence of non-negative integers: " << std::endl;

	while (true)
	{
		std::cin >> currVal;

		//check if input is correct
		while (std::cin.fail())
		{
			//clear the cin buffer
			std::cin.clear();
			//ignore the rest of the failed line
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "I'm idiot-proof, so don't even bother testing me!" << std::endl;
			std::cout << "Enter a non-negative integer: " << std::endl;
			std::cin >> currVal;
		}

		if (currVal < 0)
		{
			if (inputIsEmpty || inputCount < 2)
			{
				std::cout << "There is no valid input, so the program ends here." << std::endl;
			}
			break;
		}

		if (inputIsEmpty) inputIsEmpty = false;


		if (currVal > maxVal)
		{
			maxVal = currVal;
		}
		if (currVal < minVal)
		{
			minVal = currVal;
		}

		inputCount++;

		/*Writing only "if", instead of "else if", because we want to cover cases
		where the user enters a sequence of equal integers*/
		
	}
	if (!inputIsEmpty && inputCount >= 2)
	{
		std::cout << "Min number: " << minVal << std::endl;
		std::cout << "Max number: " << maxVal << std::endl;

		std::cout << "The difference between min and max number has absolute value of: "
			<< abs(maxVal - minVal) << std::endl;
	}
}
