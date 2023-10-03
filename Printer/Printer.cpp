#include "Printer.h"

Printer::Printer(int m) {
	maxQueueLength = m;
	wait = new string[maxQueueLength];
	pri = new int[maxQueueLength];
	queueLength = 0;
}

Printer::~Printer()
{
	delete[]wait;
	delete[]pri;
}

void Printer::Add(string c, int p)
{
	if (!IsFull()) {
		wait[queueLength] = c;
		pri[queueLength] = p;
		queueLength++;


	}
}

void Printer::Show()
{
	for (int i = 0; i < queueLength; i++) {
		cout << wait[i] << " - " << pri[i] << endl << endl;;
	}

}

string Printer::Extract()
{
	if (!IsEmpty()) {
		int maxPriInd = 0;
		for (int i = 1; i < queueLength; i++) {
			if (pri[i] > pri[maxPriInd]) {
				maxPriInd = i;
			}
		}

		string tmp = wait[maxPriInd];

		for (int i = maxPriInd; i < queueLength - 1; i++) {
			wait[i] = wait[i + 1];
			pri[i] = pri[i + 1];
		}
		queueLength--;

		return tmp;
	}
	return "Error!";
}

void Printer::Clear()
{
	queueLength = 0;
}

bool Printer::IsEmpty()
{
	return queueLength == 0;;
}

bool Printer::IsFull()
{
	return queueLength == maxQueueLength;
}

int Printer::GetCount()
{
	return queueLength;
}