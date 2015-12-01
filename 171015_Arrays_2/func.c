﻿int getlongword (char *str)
{
	//counter - длина текущего слова
	//ind - индекс текущего слова
	//longind - индекс текущего самого длинного слова
	//longword - длина текущего самого длинного слова
	//Выше слово "текущий" означает слова, на символ которого указывает в данный момент указатель str
	int counter = 0, ind = 0, longind = 0, longword = 0;
	//Бесконечный цикл - нормальная практика. если он есть, значит условие останова должно быть где-то внутри
	while (1)
	{
		//Каждая итерация цикла while обрабатывает 1 символ исходной строки
		
		//Если текущий символ это пробел или конец строки ...
		if ((*str == ' ') || (*str == '\0'))
		{
			// ... сверяем длину текущего слова и длиннейшего на данный момент слова ...
			if (longword < counter)
			{
				//...если текущее слово длиннее, то запоминаем его параметры
				longword = counter;
				longind = ind;
			}

			//Эта проверка необходима, чтобы алгоритм не считал пробелы идущие подряд разными словами
			if(counter != 0)
				ind++;

			//Если мы встретили пробел или конец строки это значит что нам надо начинать подсчёт длины нового слова. Обнуляем счётчик
			counter = 0;

			//Если встретили конец строки - выходим из цикла. Делать больше нечего
			if (*str == '\0')
				break;
		}
		else
		{
			//Если это не пробел и не конец строки то увеличиваем ... смотрим что же мы увеличиваем выше
			counter++;
		}
		//В конце каждой итерации переходим к следующему символу
		str++;
	}
	//Возвращаем найденное значение индекса длиннейшего слова
	return longind;
}

#include <stdio.h>
void print_word(char* str, int wordIndex)
{
	int counter = 0, ind = 0, longind = 0, longword = 0;
	while (1)
	{
		
		if ((*str == ' ') || (*str == '\0'))
		{   //Этот блок практически идентичен такому же из предыдущей функции, за исключением того, 
			// что здесь мы не фиксируем индекс и длину самого длинного слова
			if(counter != 0)
				ind++;
			counter = 0;
			if (*str == '\0')
				break;
		}
		else
		{ 
			counter++;
			//Если индекс текущего слова равен искомому, то наш указатель str указывает на символ искомого ...
			// ... слова (в блоке else он гарантированно указывает не на пробел и не на конец строки) и мы выводим его на экран
			if (ind == wordIndex) //ПОДУМАЙТЕ что произойдёт если мы передадим в функцию заведомо некорректный индекс слова. Что она выведет на экран?
			{
				printf("%c",*str);
			}
		}
		str++;
	}
	//В конце печатаем перевод строки, так как вывод последнего символа переводом строки не завершается
	printf("\n");
}