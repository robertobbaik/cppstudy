#include <iostream>

using namespace std;

int main()
{
	cout << "총 숫자의 개수 입력" << endl;

	int count = 0;
	cin >> count;
	double* arr = new double[count];

	double totalNum = 0;

	for (int i = 0; i < count; i++)
	{
		cout << count << "개의 숫자 중 " << i + 1 << "/" << count <<"번째 숫자 입력" << endl;
		cin >> arr[i];
		totalNum += arr[i];
	}

	cout << "총점 : " << totalNum << endl;
	cout << "평균 : " << totalNum / count << endl;

	return 0;
}