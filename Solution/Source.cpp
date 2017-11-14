#include <vector>
#include <iostream>

using namespace std;

class List
{
private:
	int intSize;
	int* intArray = nullptr;
public:
	List() {};
	List(const int intSIZE) { intSize = intSIZE; if (intSIZE > 0) intArray = new int[intSIZE]; };
	~List() { if (intArray != nullptr) delete[ ]intArray; }

	void set(int intIndex, int intValue) { intArray[intIndex] = intValue; }
	int get(int intIndex) { return intArray[intIndex]; };
	int size() { return intSize; };
};

List* merge(List* lstLeft, List* lstRight)
{
	List* lstResult = new List(lstLeft->size() * 2);
	int intCount = 0, intLeft = 0, intRight = 0;

	while (intLeft < lstLeft->size() && intRight < lstRight->size())
	{
		if (lstLeft->get(intLeft) < lstRight->get(intRight))
		{
			lstResult->set(intCount, lstLeft->get(intLeft));
			intCount++;
			intLeft++;
		}
		else
		{
			lstResult->set(intCount, lstRight->get(intRight));
			intCount++;
			intRight++;
		}
	}

	while (intLeft < lstLeft->size())
	{
		lstResult->set(intCount, lstLeft->get(intLeft));
		intCount++;
		intLeft++;
	}

	while (intRight < lstRight->size())
	{
		lstResult->set(intCount, lstRight->get(intRight));
		intCount++;
		intRight++;
	}

	return lstResult;
}
List* mergeSort(List* lstNumbers)
{
	if (lstNumbers->size() == 1)
		return lstNumbers;

	int intMiddle = lstNumbers->size() / 2;

	List* lstLeft = new List(intMiddle);
	List* lstRight = new List(intMiddle);

	for (int intIndex = 0; intIndex < intMiddle; intIndex++)
	{
		lstLeft->set(intIndex, lstNumbers->get(intIndex));
		lstRight->set(intIndex, lstNumbers->get(intIndex + intMiddle));
	}

	lstLeft = mergeSort(lstLeft);
	lstRight = mergeSort(lstRight);

	return merge(lstLeft, lstRight);
}

bool program()
{
	//input size of list
	int intInput = 0;
	cout << "MergeSort Test | Khalid Ali" << endl;
	do
	{
		cout << "Enter amount of items in list (limited 2 to 10): ";
		cin >> intInput;
	} while (intInput < 2 || intInput > 10);

	//input unordered values
	List* lstNumbers = new List(intInput);
	intInput = 0;
	for (int intIndex = 0; intIndex < lstNumbers->size(); intIndex++)
	{
		do
		{
			cout << "Enter unique value for number " << intIndex + 1 << " (0 to 10): ";
			cin >> intInput;
		} while (intInput < 0 && intInput > 10);
		lstNumbers->set(intIndex, intInput);
	}
	lstNumbers = mergeSort(lstNumbers);

	//print results
	cout << endl << "Results: ";
	for (int intIndex = 0; intIndex < lstNumbers->size(); intIndex++)
		cout << lstNumbers->get(intIndex) << " ";
	delete lstNumbers;

	//ask for loop
	char charInput;
	do
	{
		cout << endl << endl << "Continue (y/n)? ";
		cin >> charInput;
	} while (charInput != 'y' && charInput != 'n');

	if (charInput == 'y')
		return true;
	else if (charInput == 'n')
		return false;
}
int main(void)
{
	while (program());
	return 0;
}