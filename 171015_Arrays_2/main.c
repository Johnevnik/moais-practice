#include <stdio.h>
//��� ��������� incude ������� � ��� ����� ����� main.c ���������� ����� func.h (�������� �������� �� ������� �������)
// � ��������� ����� �� ������ ������������ ������� �� ����� func.c 
#include "func.h"


//������� ��� ������������ ������� getlongword
void Test(char* str, int expected)
{
	//��������� ��� ����, ���������� � ��� ��� ������ ���� � ������� ��������������� ���������
	int actual = getlongword(str);
	printf("%s -> Expected %d, Actual %d -> %s\n", //�������� ��������, ����� ��������� ���������, ���������� ��������, �� ������ ������
		str, 
		expected, 
		actual, 
		actual == expected ? "Ok" : "Error");
}

void main()
{
	char a[] = "d sd a sassssss sdfds";

	Test("d sd a sassssss sdfds", 3); 
	Test("d sassssss a sdfds", 1); 
	Test("d sd    a sassssss sdfds", 3); 
	Test("d sd    a sassssss sdfds   ", 3); 
	Test("   d sd    a sassssss sdfds", 3); 

	print_word(a, 3);

	return;
}
