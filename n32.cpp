#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int num1, int num2) // компаратор, для сортировки по убыванию
{
	return num1 > num2;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int a, b;
	fin >> a >> b;

	bool a_sign, b_sign; // true -- '+'; false -- '-'
	if (a < 0)
		a_sign = false;
	else
		a_sign = true;
	if (b < 0)
		b_sign = false;
	else
		b_sign = true;

	int n_a = 0, n_b = 0; // для определения кол-ва цифр в числе
	int temp_a = a, temp_b = b;
	for (int i = 0; temp_a != 0; i++)
	{
		temp_a = temp_a / 10;
		n_a++;
	}
	for (int i = 0; temp_b != 0; i++)
	{
		temp_b = temp_b / 10;
		n_b++;
	}

	vector<int> numbers_of_a(n_a);// векторы цифр в числах
	vector<int> numbers_of_b(n_b);

	for (int i = 0; i < n_a; i++)
	{
		numbers_of_a[i] = abs(a % 10);
		a = a / 10;
	}
	for (int i = 0; i < n_b; i++)
	{
		numbers_of_b[i] = abs(b % 10);
		b = b / 10;
	}

	if (a_sign)
		sort(numbers_of_a.begin(), numbers_of_a.end(), cmp);
	else
	{
		sort(numbers_of_a.begin(), numbers_of_a.end());

		if (numbers_of_a[0] == 0)
			for (int i = 0; i < n_a; i++)
				if (numbers_of_a[i] != 0)
				{
					swap(numbers_of_a[0], numbers_of_a[i]);
					break;
				}
	}

	if (b_sign)
	{
		sort(numbers_of_b.begin(), numbers_of_b.end());

		if (numbers_of_b[0] == 0)
			for (int i = 0; i < n_b; i++)
				if (numbers_of_b[i] != 0)
				{
					swap(numbers_of_b[0], numbers_of_b[i]);
					break;
				}
	}
	else
		sort(numbers_of_b.begin(), numbers_of_b.end(), cmp);

	int temp = 1;
	for (int i = n_a - 1; i >= 0; i--)
	{
		a += numbers_of_a[i] * temp;
		temp *= 10;
	}
	temp = 1;
	for (int i = n_b - 1; i >= 0; i--)
	{
		b += numbers_of_b[i] * temp;
		temp *= 10;
	}

	if (!a_sign)
		a = 0 - a;
	if (!b_sign)
		b = 0 - b;

	fout << a - b;
}