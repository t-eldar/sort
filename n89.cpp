#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct train
{
	string name;
	int time = 0;
	double speed = 0;
};

int time_to_minute(string time)
{
	int minute_i, hour_i;
	string minute_s, hour_s;

	hour_s.append(time, 0, 2);
	hour_i = stoi(hour_s);

	minute_s.append(time, 3, 2);
	minute_i= stoi(minute_s);
	minute_i += hour_i * 60;

	return minute_i;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	const int DISTANCE = 650;

	int n;
	fin >> n;

	vector <train> trains(n);
	for (int i = 0; i < n; i++)
	{
		string temp_str;

		char t;
		fin >> t;

		getline(fin, temp_str);
		temp_str.insert(0, 1, t);

		int j = 0;

		for (j = 1; j < temp_str.size() && temp_str[j] != '\"'; j++)
			trains[i].name.push_back(temp_str[j]);

		string time1, time2;
		for (j = j + 2; j < temp_str.size() && temp_str[j] != ' '; j++)
			time1.push_back(temp_str[j]);
		for (j = j + 1; j < temp_str.size() && temp_str[j] != ' '; j++)
			time2.push_back(temp_str[j]);

		if (time2 < time1)
			trains[i].time = 24 * 60 - time_to_minute(time1) + time_to_minute(time2);
		else
			trains[i].time = time_to_minute(time2) - time_to_minute(time1);

		if (trains[i].time == 0)
			trains[i].time = 24 * 60;

		trains[i].speed = (double)DISTANCE / trains[i].time;
	}
	train fastest_train = trains[0];
	
	for (int i = 1; i < n; i++)
	{
		if (trains[i].speed > fastest_train.speed)
			fastest_train = trains[i];
	}
	
	fastest_train.speed = fastest_train.speed * 60;
	
	fout << "The fastest train is \"" << fastest_train.name << "\".";
	fout << "\nIts speed is " << round(fastest_train.speed) << " km/h, approximately.";
}