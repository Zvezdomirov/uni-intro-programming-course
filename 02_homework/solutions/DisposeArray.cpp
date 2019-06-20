#include <iostream>

void disposeArray(int*, int, int);

int main()
{
	int Arr[] = { 6, 5, 6, 0, 3 };
	int Length = 5;
	int M;
	std::cout << "Enter disposition count:" << std::endl;
	std::cin >> M;
	disposeArray(Arr, Length, M);
	for (int i = 0; i < Length; i++)
	{
		std::cout << Arr[i] << " ";
	}
	std::cout << std::endl;
}

void disposeArray(int* arr, int arrLength, int dispositionCount)
{
	if (arr == nullptr)
	{
		return;
	}

	if (abs(dispositionCount) > abs(arrLength))
	{
		std::cout << "Error!" << std::endl;
		return;
	}

	/*Create a temporary array, the same as the input one and then
	use it to modify the original one*/
	int* tempArr = new int[arrLength];
	int currentDisposition;
	for (int i = 0; i < arrLength; i++)
	{
		currentDisposition = i - dispositionCount;
		if (currentDisposition > arrLength - 1)
		{
			currentDisposition -= arrLength;
		}
		else if (currentDisposition < 0)
		{
			currentDisposition += arrLength;
		}
		tempArr[i] = arr[currentDisposition];
	}

	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = tempArr[i];
	}
	delete[] tempArr;
}