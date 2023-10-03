#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Printer
{
	string* wait;
	int* pri;

	int maxQueueLength;
	int queueLength;

public:
	Printer(int);
	~Printer();

	void Add(string, int);
	void Show();


	string Extract();

	void Clear();

	bool IsEmpty();
	bool IsFull();

	int GetCount();
};