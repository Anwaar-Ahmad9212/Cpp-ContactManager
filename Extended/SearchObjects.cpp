
#include "SearchObjects.h"
#include <iostream>
using namespace std;
SearchObjects::SearchObjects()
{
}
SearchObjects::SearchObjects(int size)
{
	List = new HistoryObjects[size];
	//count = new int[size];
	list_count = 0;
	size_of_list = size;
}

void SearchObjects::addhistory(const HistoryObjects& history)
{
	if (list_count < size_of_list)
	{
		List[list_count++] = history;
	}
	else
	{
		resizelist();
		addhistory(history);
	}
}

void SearchObjects::resizelist()
{
	int size = 2 * list_count;
	HistoryObjects* NewArray;
	NewArray = new HistoryObjects[size];

	for (int i = 0; i < list_count; i++)
	{
		*(NewArray + i) = *(List + i);
	}

	//delete[]contacts_list;

	List = NewArray;
	this->size_of_list = size;
}

void SearchObjects::sorttime()
{
	for (int i = 0; i < list_count; i++)
	{
		for (int j = i + 1; j < list_count; j++)
		{
			if (List[i].getCurrentTime() < List[j].getCurrentTime())
			{
				HistoryObjects temp = List[i];
				List[i] = List[j];
				List[j] = temp;
			}
		}


	}
}

void SearchObjects::print()
{
	for (int i = 0; i < list_count; i++)
	{
		cout << List[i].getStr() << " " << List[i].getCurrentTime() << endl;
	}


	//ListGeneric<string, int, HistoryObjects>obj;
	//obj.savetofile("SearchHistory.txt",list_count,List);

}

int SearchObjects::getListCount()
{
	return list_count;
}

