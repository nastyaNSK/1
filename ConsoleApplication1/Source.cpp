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

square * init(int a) // �- �������� ������� ����, �������������
{
	square *lst;
	// ��������� ������ ��� ������ ������
	lst = new square(a);
	lst->size = a;
	lst->ptr = NULL; // ��� ��������� ���� ������
	return (lst);
}

square * addelem(square* &lst, int number)
{
	square *temp, *p;
	temp = new square(number);

	if (lst) {
		p = lst->ptr; // ���������� ��������� �� ��������� ����
		lst->ptr = temp; // ���������� ���� ��������� �� �����������
		temp->ptr = p; // ��������� ���� ��������� �� ��������� �������
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

	while (temp != NULL && temp != lst) // ������������� ������ ������� � �����
	{
		// ���� �� ������ ����, �������������� lst
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
	prev->ptr = temp->ptr; // ������������ ���������
	free(temp); // ����������� ������ ���������� ����
}
square* getElem(square *root, int kpos)
{
	int i = 0;
	while (root != NULL && i<kpos) // ������������� ������ ������� � �����
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