#include <iostream>
#include <string.h>
#include "Printer.h"

using namespace std;


int main() {

	Printer printer(10);

	printer.Add("ExamExample.pdf", 4);
	printer.Add("AccOfCivilServants.doc",2);
	printer.Add("Family.jpg", 3);
	printer.Add("Password.txt", 10);
	printer.Add("1.txt", 6);

	cout << endl;

	cout << "Current Queue Status:" << endl;
	printer.Show();

	cout << endl;

	cout << "Priority statistics:" << endl;
	while (!printer.IsEmpty()) {
		string printInfo = printer.Extract();
		if (printInfo != "Queue is empty!") {
			cout << printInfo << endl;
		}
	}
	return 0;
}