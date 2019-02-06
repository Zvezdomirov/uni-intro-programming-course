#include <iostream>

int main()
{
	int arr[] = {1,2,3,3,3,3,2,2,1,1,1,1,4,5};
	int length = 13;
	int count = 1, maxCount = 1;
	int maxIndex = -1;

	for (int i = 0; i < length - 1; i++)
	{
		for (i; arr[i] == arr[i + 1]; i++)
		{
			count++;
		}
		if (count > maxCount)
		{
			maxCount = count;
			maxIndex = i - (maxCount - 1);
		}
		count = 1;

	}

	for (int i = 0; i < maxCount; i++)
	{
		std::cout << arr[maxIndex + i];
	}

}
