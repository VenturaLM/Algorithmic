/*
*	File:	heapsort.cpp
*	Author:	Ventura Lucena Martínez
*	Email:	i72lumav@uco.es
*/

#include <ctime>
#include <algorithm>

#include "heapsort.hpp"
#include "ClaseTiempo.cpp"
#include "statisticsFunctions.hpp"
#include "filesFunctions.hpp"

using namespace std;

void fillVector(vector<int> &v)
{
	for (auto i = 0; i < v.size(); i++)
		v[i] = rand() % 9999999;
}

bool isSorted(const vector<int> &v)
{
	return is_sorted(v.begin(), v.end());
}

void heapSort(vector<int> &v)
{
	make_heap(v.begin(), v.end());
	sort_heap(v.begin(), v.end());
}

void HeapSort_()
{
	srand(time(NULL));
	Clock time;

	vector<int> v;
	vector<double> realTimes;
	vector<double> nElements;

	int nMin, nMax, increase, repetitions;
	double sum = 0.0;

	cout << "\nIntroduce nMin values:\n> ";
	cin >> nMin;
	cout << "\nIntroduce nMax values:\n> ";
	cin >> nMax;
	cout << "\nIntroduce the increase:\n> ";
	cin >> increase;
	cout << "\nIntroduce repetitions:\n> ";
	cin >> repetitions;
	cout << endl;

	for (auto n = nMin; n <= nMax; n += increase)
	{
		sum = 0.0;
		for (auto i = 0; i < repetitions; i++)
		{
			v.resize(n);
			fillVector(v);
			time.start();
			heapSort(v);

			if (time.isStarted())
			{
				time.stop();
				sum = sum + time.elapsed();
			}
		}

		double mean = sum / repetitions;
		realTimes.push_back(mean);
		nElements.push_back(n);

		cout << "n = <" << n << "> time: " << mean << " microseconds." << endl;
		v.clear();
	}

	vector<double> a;
	for (auto i = 0; i < 2; i++)
		a.push_back(0.0);

	NlogNAdjustment(nElements, realTimes, a);

	vector<double> estimatedTimes;
	calculateEstimatedTimesNlogN(nElements, a, estimatedTimes);
	saveToFile(nElements, realTimes, estimatedTimes, "heapsort_data.txt");
	cout << "\nCoefficient of Determination:\n" << coefficientOfDetermination(realTimes, estimatedTimes) << endl;

	cout << "\nDo you want to calculate an estimation for n?\n1. Yes.\n2. No.\n> ";
	int option;
	cin >> option;
	switch(option)
	{
		case 1:
			cout << "\nn value:\n> ";
			double n_value;
			cin >> n_value;
			cout << "\nEstimated time:" << endl;
			calculateEstimatedTimeNlogN(n_value, a);
		break;

		default:
		break;
	}
}