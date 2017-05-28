#ifndef HASH_H
#define HASH_H

#include <iostream>
//#include <string>

class Hash
{
public:
	Hash();
	int hashStr(char* key);
	void addItem(char* name, char* drink);


private:
	static const int tableSize = 10;

	struct item
	{
		char* name;
		char* drink;
		item* next;
	};

	item* hashTable[tableSize];

};

#endif
