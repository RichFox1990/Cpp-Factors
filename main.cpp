#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

long long GatherNumber();

void SolveFactors(const long long&, vector<long long>&);


// Factors of any given number
int main()
{
	long long solve = GatherNumber();

	vector<long long> factors{};

	SolveFactors(solve, factors);

	string again = "y";

	do
	{
		cout << "\nDo you want to get the factors of another number? y/n: ";
		cin >> again;
		cout << endl;
		if (again == "y")
		{
			solve = GatherNumber();
			factors = {};
			SolveFactors(solve, factors);
		}
		
	} while (again != "n");

	return 0;
}


long long GatherNumber()
/* Gathers input and checks the validity
   Returns a long long */
{
	long double number;
	cout << "Please enter the number you want the factors of: ";
	cin >> number;
	cout << endl;

	while (!(floor(number) == number))
	{
		cout << "you didn't declare a whole number\n\n" << "Try again: " << endl;
		cin >> number;
	}
	//cout << (long long)number;
	return (long long)number;
}



void SolveFactors(const long long &num, vector<long long> &NameOfVector)
/* Takes a reference to a long long "num" and a reference to a vector of long longs "NameOfVector" :
   With the "num" it finds all the factors of this number and adds them to the vector before sorting and printing them in the terminal */
{
	for (long long x = 1; x <= sqrt(num); x++)
	{

		long long answer = num / x;
		if (num % x == 0)
		{
			NameOfVector.push_back(x);

			if (!(answer == x))
				NameOfVector.push_back(answer);
		}
	}

	sort(NameOfVector.begin(), NameOfVector.end());

	cout << "These are the factors of " << num << "\n";

	cout << "[ ";

	for (long long i = 0; i < NameOfVector.size(); i++)
	{
		// if its the last number in the vector
		if (i == (NameOfVector.size() - 1))
		{
			cout << NameOfVector[i] << " ]" << endl;
		}
		else
		{
			cout << NameOfVector[i] << ", ";
		}
	}

	return;
}