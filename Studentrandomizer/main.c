#include <stdio.h>
#define STUDENTS_COUNT 26
#include <stdlib.h>
#include <time.h>
#include <locale.h>

char* get_random_student()
{
	char* students[STUDENTS_COUNT] = 
	{
		"������� �������",
		"�������� ����", 
		"���������� ���������", 
		"�������� �����", 
		"�������� ���������", 
		"����� �����", 
		"��������� �����", 
		"�������� ������", 
		"�������� ������", 
		"�������� �����", 
		"�������� �������", 
		"��������� ���������", 
		"������ ����", 
		"������� �������", 
		"��������� �������", 
		"���������� ����", 
		"�������� �������", 
		"������� ���������", 
		"����������� �������", 
		"����� �����", 
		"�������� ������",
		"������� ���������", 
		"���������� ����", 
		"�������� �����", 
		"����� ����",
		"����� ���������"
	};

	srand(time(NULL));
	return students[rand() % STUDENTS_COUNT];
}

void main()
{
	setlocale(LC_ALL, "");
	//Put your code here ...
	printf("%s\n", get_random_student());
	getchar();
	return;
}