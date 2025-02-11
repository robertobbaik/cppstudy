#include <iostream>

using namespace std;

int getTotalNum(int count, double* arr)
{
	double totalNum = 0;
	for (int i = 0; i < count; i++)
	{
		totalNum += arr[i];
	}
	return totalNum;
}

double getAverage(int count, double* arr)
{
	return getTotalNum(count, arr) / count;
}

int main()
{
	//cout << "총 숫자의 개수 입력" << endl;

	int count = 5;
	//cin >> count;
	double* arr = new double[count];

	//double totalNum = 0;

	for (int i = 0; i < count; i++)
	{
		cout << count << "개의 숫자 중 " << i + 1 << "/" << count <<"번째 숫자 입력" << endl;
		cin >> arr[i];
		//totalNum += arr[i];
	}

	int totalNum = getTotalNum(count, arr);
	double average = getAverage(count, arr);

	cout << "총점 : " << totalNum << endl;
	cout << "평균 : " << average << endl;

	return 0;
}

