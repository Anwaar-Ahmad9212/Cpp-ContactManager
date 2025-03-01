
#pragma once
#include <iostream>
#include <string>
#include "HistoryObjects.h"
//#include"ListGeneric.h"
using namespace std;
class SearchObjects
{
private:
	HistoryObjects* List;
	int list_count;
	int size_of_list;
public:
	SearchObjects();
	SearchObjects(int size);
	void addhistory(const HistoryObjects& history);
	void resizelist();
	void sorttime();
	void print();
	int getListCount();

};

