#include <vector>
#include <iostream>

using namespace std;

class List
{
private:
	int intSize;
	int* intArray;
public:
	List() {};
	List(const int intSIZE) { intSize = intSIZE; intArray = new int[intSIZE]; };
	~List() { delete intArray; }

	void set(int intIndex, int intValue) { intArray[intIndex] = intValue; }
	int get(int intIndex) { return intArray[intIndex]; };
	int size() { return intSize; };
};

List merge(List& lstLeft, List& lstRight)
{
	List lstResult(lstLeft.size() * 2);
	int intCount = 0, intLeft = 0, intRight = 0;

	while (intLeft < lstLeft.size() && intRight < lstRight.size())
	{
		if (lstLeft.get(intLeft) < lstRight.get(intRight))
		{
			lstResult.set(intCount, lstLeft.get(intLeft));
			intCount++;
			intLeft++;
		}
		else
		{
			lstResult.set(intCount, lstRight.get(intRight));
			intCount++;
			intRight++;
		}
	}

	while (intLeft < lstLeft.size())
	{
		lstResult.set(intCount, lstLeft.get(intLeft));
		intCount++;
		intLeft++;
	}

	while (intRight < lstRight.size())
	{
		lstResult.set(intCount, lstRight.get(intRight));
		intCount++;
		intRight++;
	}

	return lstResult;
}
List mergeSort(List lstNumbers)
{
	if (lstNumbers.size() == 1)
		return lstNumbers;

	int intMiddle = lstNumbers.size() / 2;

	List lstLeft(intMiddle), lstRight(intMiddle);

	for (int intIndex = 0; intIndex < intMiddle; intIndex++)
	{
		lstLeft.set(intIndex, lstNumbers.get(intIndex));
		lstRight.set(intIndex, lstNumbers.get(intIndex + intMiddle));
	}

	lstLeft = mergeSort(lstLeft);
	lstRight = mergeSort(lstRight);

	return merge(lstLeft, lstRight);
}

bool program()
{

	List lstNumbers(8);
	lstNumbers.set(0, 9);
	lstNumbers.set(1, 2);
	lstNumbers.set(2, 7);
	lstNumbers.set(4, 1);
	lstNumbers.set(5, 4);
	lstNumbers.set(6, 5);
	lstNumbers.set(7, 8);

	lstNumbers = mergeSort(lstNumbers);
	for (int intIndex = 0; intIndex < 8; intIndex++)
		cout << lstNumbers.get(intIndex) << " ";

	char charInput;
	do
	{
		cout << "Continue (y/n)? ";
		cin >> charInput;
	} while (charInput != 'y' || charInput != 'n');

	if (charInput == 'y')
		return false;
	else if (charInput == 'n')
		return true;
}
int main(void)
{
	while (program());
	return 0;
}