#include<iostream>

int substrOccurrences(char*, char*, int&);
int myStrLen(char*);

int main()
{
	char* str = new char[100];
	char* substr = new char[100];
	int maxIndex = -1;

	std::cout << "Enter a string: ";
	std::cin.getline(str, 100);
	std::cout << "Enter a substring you are looking for: ";
	std::cin.getline(substr, 100);

	int occurences = substrOccurrences(str, substr, maxIndex);
	std::cout << "Index: " << maxIndex << std::endl;
	std::cout << "Length: " << occurences << std::endl;
}

int substrOccurrences(char* str, char* substr, int& maxIndex)
{
	if (str == nullptr || substr == nullptr)
	{
		return -1;
	}

	int strLength = myStrLen(str);
	int substrLength = myStrLen(substr);
	
	int i = 0, j = 0;
	int occurrenceCount = 0, maxOccurrence = 0;
	int tempCount = 0;

	while (i < strLength)
	{
		while (str[i++] == substr[j++])
		{
			tempCount++;
			if (tempCount == substrLength)
			{
				occurrenceCount++;
				tempCount = 0;
				j = 0;
			}
		}
		if (occurrenceCount > maxOccurrence)
		{
			maxOccurrence = occurrenceCount;
			maxIndex = i - (substrLength * maxOccurrence) - 1;
		}
		j = 0, tempCount = 0, occurrenceCount = 0;
	}
	return maxOccurrence * substrLength;
}

int myStrLen(char* str)
{
	if (str == nullptr)
	{
		return -1;
	}

	int count = 0;
	while (*str++)
	{
		count++;
	}
	return count;
}