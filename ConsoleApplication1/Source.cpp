#include <iostream>
#include <algorithm>
#include<ctime>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;
typedef unsigned char byte;

struct square
{
	byte size;
	square *ptr;

	square(byte n)
	{
		size = n;
		ptr = NULL;
	}
};

square * init(int a) // а- значение первого узла, инициализация
{
	square *lst;
	// выделение памяти под корень списка
	lst = new square(a);
	lst->size = a;
	lst->ptr = NULL; // это последний узел списка
	return (lst);
}

square * addelem(square* &lst, int number)
{
	square *temp, *p;
	temp = new square(number);

	if (lst) {
		p = lst->ptr; // сохранение указателя на следующий узел
		lst->ptr = temp; // предыдущий узел указывает на создаваемый
		temp->ptr = p; // созданный узел указывает на следующий элемент
	}
	else {
		lst = temp;
	}
	return (temp);
}

void deletelem(square *lst, square* &root)
{
	if (lst == NULL) return;
	square *temp = NULL, *prev = NULL;
	temp = root;

	while (temp != NULL && temp != lst) // просматриваем список начиная с корня
	{
		// пока не найдем узел, предшествующий lst
		prev = temp;
		temp = temp->ptr;
	}
	if (temp == NULL) return;

	if (root == lst) {
		temp = root;
		root = root->ptr;
		delete temp;
		return;
	}
	prev->ptr = temp->ptr; // переставляем указатель
	free(temp); // освобождаем память удаляемого узла
}
square* getElem(square *root, int kpos)
{
	int i = 0;
	while (root != NULL && i<kpos) // просматриваем список начиная с корня
	{
		++i;
		root = root->ptr;
	}

	return root;
}
void movekp(square *root, int k, int p)
{
	square* found = getElem(root, k);
	byte x = found->size;
	deletelem(found, root);
	square* foundp = getElem(root, p);
	if (foundp != NULL)
	{
		addelem(foundp, x);
	}
}

int main() {
	int M = 10;
	int j = 0;
	byte *ptrarray = new byte[M];
	for (int i = 0; i < M; i++) {
		ptrarray[i] = rand();
	}
	for (int i = 0; i < M; i++) {
		std::cout << ptrarray[i] << std::endl;
	}
	
	square* root = NULL;
	for (int i = 0; i < M; i++) {
		j = sqrt(ptrarray[i]);
		j = ptrarray[i] % j;
		if (j == 0)
			addelem(root, ptrarray[i]);
	}
	for (int i = 0; i < M; i++) {
		
	}


	system("pause");
}