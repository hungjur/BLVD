#pragma once
#include <string>
#include <vector>
struct FIO {
	std::string f, i, o;
};
struct Date {
	int y, m, d;
};
struct Key {
	Date date;
	FIO fio;
	int No;
};
bool Bigger(Key k1, Key k2);
