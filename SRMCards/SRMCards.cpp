// SRMCards.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class SRMCards
{
	public:
		int maxTurns(vector<int> cards);
};

int SRMCards::maxTurns(vector<int> cards)
{
	int turns = 0;
	unordered_set<int> cardSet;
	unordered_set<int>::iterator pos1;
	unordered_set<int>::iterator pos2;

	// Initialize our set with the card numbers
	for(vector<int>::iterator it = cards.begin(); it != cards.end(); ++it)
	{
		cardSet.insert(*it);
	}
	
	// For every  possible card number starting from the lowest to the highest value
	// check if the value and value + 1 is in the set. If it is remove both, otherwise 
	// remove value.
	for(int i = 1; i < 500; i++)
	{
		if(cardSet.size())
		{
			if((pos1 = cardSet.find(i)) != cardSet.end() &&
				(pos2 = cardSet.find(i + 1)) != cardSet.end())
			{
				cardSet.erase(pos1);
				cardSet.erase(pos2);
				turns++;
			}
			else if((pos1 = cardSet.find(i)) != cardSet.end())
			{
				cardSet.erase(pos1);
				turns++;
			}
		}
		else break;
	}

	return turns;
}

int _tmain(int argc, _TCHAR* argv[])
{
	SRMCards srmCards;

	// Test 1
	int cardValues[] = {498, 499};
	vector<int> cards (cardValues, cardValues + sizeof(cardValues)/sizeof(int));
	int count = srmCards.maxTurns(cards);

	cout << "{ ";
	for(vector<int>::iterator it = cards.begin(); it != cards.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << " }\n" << "Returned: " << count << endl << endl;

	// Test 2
	int cardValues2[] = {491, 492, 495, 497, 498, 499};
	vector<int> cards2 (cardValues2, cardValues2 + sizeof(cardValues2)/sizeof(int));
	count = srmCards.maxTurns(cards2);

	cout << "{ ";
	for(vector<int>::iterator it = cards2.begin(); it != cards2.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << " }\n" << "Returned: " << count << endl << endl;

	// Test 3
	int cardValues3[] = {100, 200, 300, 400};
	vector<int> cards3 (cardValues3, cardValues3 + sizeof(cardValues3)/sizeof(int));
	count = srmCards.maxTurns(cards3);

	cout << "{ ";
	for(vector<int>::iterator it = cards3.begin(); it != cards3.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << " }\n" << "Returned: " << count << endl << endl;

	// Test 4
	int cardValues4[] = {11, 12, 102, 13, 100, 101, 99, 8, 1};
	vector<int> cards4 (cardValues4, cardValues4 + sizeof(cardValues4)/sizeof(int));
	count = srmCards.maxTurns(cards4);

	cout << "{ ";
	for(vector<int>::iterator it = cards4.begin(); it != cards4.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << " }\n" << "Returned: " << count << endl << endl;

	// Test 5
	int cardValues5[] = {118, 321, 322, 119, 120, 320};
	vector<int> cards5 (cardValues5, cardValues5 + sizeof(cardValues5)/sizeof(int));
	count = srmCards.maxTurns(cards5);

	cout << "{ ";
	for(vector<int>::iterator it = cards5.begin(); it != cards5.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << " }\n" << "Returned: " << count << endl << endl;

	// Test 6
	int cardValues6[] = {10, 11, 12, 13, 14, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> cards6 (cardValues6, cardValues6 + sizeof(cardValues6)/sizeof(int));
	count = srmCards.maxTurns(cards6);

	cout << "{ ";
	for(vector<int>::iterator it = cards6.begin(); it != cards6.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << " }\n" << "Returned: " << count << endl << endl;

	// Test 7
	int cardValues7[] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> cards7 (cardValues7, cardValues7 + sizeof(cardValues7)/sizeof(int));
	count = srmCards.maxTurns(cards7);

	cout << "{ ";
	for(vector<int>::iterator it = cards7.begin(); it != cards7.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << " }\n" << "Returned: " << count << endl << endl;

	// Test 8
	int cardValues8[] = {10,9,8,7,6,5,4,3,2,1};
	vector<int> cards8 (cardValues8, cardValues8 + sizeof(cardValues8)/sizeof(int));
	count = srmCards.maxTurns(cards8);

	cout << "{ ";
	for(vector<int>::iterator it = cards8.begin(); it != cards8.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << " }\n" << "Returned: " << count << endl << endl;
	system("pause");
	return 0;
}

