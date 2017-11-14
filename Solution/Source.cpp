#include <vector>

using namespace std;

vector<int> mergeSort(vector<int> intList)
{
	if (intList.size() == 1)
		return intList;

	vector<int>::iterator iterMiddle = intList.begin() + (intList.size() / 2);

	vector<int> intLeft(intList.begin(), iterMiddle);
	vector<int> intRight(iterMiddle, intList.end());

	intLeft = mergeSort(intLeft);
	intRight = mergeSort(intRight);

	return merge(intLeft, intRight);
}

vector<int> merge(const vector<int>& intLeft, const vector<int>& intRight)
{

}

int main(void)
{
	return 0;
}