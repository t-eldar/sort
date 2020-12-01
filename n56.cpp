#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int n;
	fin >> n;

	vector<string> friends(n);
	for (int i = 0; i < n; i++)
		fin >> friends[i];

	int m;
	fin >> m;

	vector<string> users(m);
	for (int i = 0; i < m; i++)
		fin >> users[i];

	vector<string> mutual_friends;

	sort(friends.begin(), friends.end());
	
	fout << "Friends: ";
	for (int i = 0; i < friends.size() - 1 && friends.size() != 0; i++)
		fout << friends[i] << ", ";
	if (friends.size() != 0)
		fout << friends[n - 1];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (friends[i] == users[j])
			{
				mutual_friends.push_back(users[j]);
				users[j] = "0";
			}
	
	sort(mutual_friends.begin(), mutual_friends.end());

	fout << "\nMutual Friends: ";
	for (int i = 0; i < mutual_friends.size() - 1 && mutual_friends.size() != 0; i++)
		fout << mutual_friends[i] << ", ";
	if (mutual_friends.size() != 0)
		fout << mutual_friends[mutual_friends.size() - 1];

	fout << "\nAlso Friend of: ";
	for (int i = 0; i < users.size() - 1 && users.size() != 0; i++)
	{
		if (users[i] != "0")
			fout << users[i];
	}
	if (users.size() != 0)
		fout << users[users.size() - 1];
}