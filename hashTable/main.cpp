#include "Hash.h"

using namespace std;

Hash::Hash()
{
	for (int i = 0; i < tableSize; i++)
	{
		hashTable[i] = new item;
		hashTable[i]->name = "empty";
		hashTable[i]->drink = "empty";
		hashTable[i]->next = nullptr;
	}
}

int Hash::hashStr(char* key) 
{
	int hashVal{0};
	int index;

	for (int i = 0; i < strlen(key); i++)
	{
		hashVal = hashVal + (int)key[i];
		cout << "hash = " << hashVal << endl;
	}

	index = hashVal % tableSize;
	return index;

}

void Hash::addItem(char* name, char* drink)
{
	int index = hashStr(name);

	if (hashTable[index]->name == "empty")
	{
		hashTable[index]->name = name;
		hashTable[index]->drink = drink;
	}
}

int main()
{
	Hash hashObj;
	int index;

	index = hashObj.hashStr("Paula");

	cout << "index = " << index << endl;

	system("pause");
	return 0;

}