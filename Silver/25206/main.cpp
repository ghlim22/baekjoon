#include <iostream>
#include <sstream>
int main(void)
{
	double ans = 0.0;
	double creditSum = 0;
	double curCredit;
	double curGrade;
	std::string subject;
	std::string credit;
	std::string grade;

	for (int i = 0; i < 20; ++i)
	{
		std::cin >> subject >> credit >> grade;
		std::stringstream ss1(credit);

		ss1 >> curCredit;

		if (grade == "P")
		{
			continue;
		}
		else if (grade == "A+")
			curGrade = 4.5;
		else if (grade == "A0")
			curGrade = 4.0;
		else if (grade == "B+")
			curGrade = 3.5;
		else if (grade == "B0")
			curGrade = 3.0;
		else if (grade == "C+")
			curGrade = 2.5;
		else if (grade == "C0")
			curGrade = 2.0;
		else if (grade == "D+")
			curGrade = 1.5;
		else if (grade == "D0")
			curGrade = 1.0;
		else
			curGrade = 0.0;

		creditSum += curCredit;
		ans += curGrade * curCredit;
	}

	std::cout << ans / creditSum << '\n';

	return 0;
}

