#include <iostream>

using namespace std;

int main()
{
	cout << "�� ������ ���� �Է�" << endl;

	int count = 0;
	cin >> count;
	double* arr = new double[count];

	double totalNum = 0;

	for (int i = 0; i < count; i++)
	{
		cout << count << "���� ���� �� " << i + 1 << "/" << count <<"��° ���� �Է�" << endl;
		cin >> arr[i];
		totalNum += arr[i];
	}

	cout << "���� : " << totalNum << endl;
	cout << "��� : " << totalNum / count << endl;

	return 0;
}