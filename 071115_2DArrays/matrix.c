#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int ** generate (int nRows, int nCols)
{
	int **matrix;
	int size, j,i;
	void *address;
	//������� �������� ������ ��� ������ ���������� �� ������
	size = nRows * sizeof(int*); // ������� ��������� ������ (� ������) ������� ���������� (�������� ������)
	address = malloc(size); //����������� � ������� ����������� ���� ������ ���������� ������� � ��������� ����� ��� ������ �� ��������� ����������
	matrix = (int**)address; //� ��������� ���������� ��� - ��������� �� �����. ������� � � ���� ��������� �� int*, ��� ��� �� ����������� ������ ��� ������ ���� int*

	//����� �������� ������ ��� ������ ������ (������) � ������ ��� ����� ��������������� ��������� �� ������� �������� �� ��� ������
	for (i = 0; i < nRows; i++)
	{
		matrix[i] = (int*)malloc(nCols * sizeof(int));
	}

	//�������������� ��������� ��������� ����� ������� ��������, ����� ��� ������ ������� ��������� ��������������� ����� ���� �������
	srand(time(NULL));

	for (i = 0; i < nRows; i++)
	{
		for (j = 0; j < nCols; j++)
		{
			matrix[i][j] = rand()%20 - 10;
		}
	}

	return matrix;
}

void show ( int **matr, int nRows, int nCols )
{
	int row, column;
	for ( row = 0; row < nRows; row++ )
	{
		for ( column = 0; column < nCols; column++ )
		{
			printf ( "%i\t", matr[row][column] );
		}
		printf ( " \n " );
	}
}

void setfree ( int **matr, int nRows )
{
	int i;
	for ( i = 0; i < nRows; i++ )
	{
		free ( matr[i] );
	}
	free ( matr );
}

//��� �������� �������� ��������� �� ������ ������� ������� ���������� �� ��������� ���� int*, ���� ��������� ����� ��� int**
//���� �� � ������� main �������� ��������� ���� int** (�������� int** matr) � ����� ������� ��� ����� �� ��������� � �����-�� �������, � ������� �� ��� ���������, �� �� ������ �������� �� matr,
//� ����� matr, ����� ������� ������ ������ �� ����� ������ � �������� ��������, ������� ���. ����� ������� ������� ������ ����� �������� int***, � �� ����� ���������� � �� �� matr, � &matr
void scan_mass(int ***matrix, int *rows, int *cols)
{
	int i,j;
	printf("Rows :");
	scanf("%d",rows);
	printf("Columns :");
	scanf("%d",cols);
	//��� ������ ��������� ������ ����� � ����, ��� ��� �������
	*matrix=(int**)malloc(*rows*sizeof(int*));

	for (i=0; i<*rows; i++)
	{
		(*matrix)[i]=(int*)malloc(*cols*sizeof(int));
	}

	for (i = 0; i <* rows; i++)
	{
		for(j = 0; j < *cols; j++)
		{
			printf ("m[%d][%d] = ",i,j);
			scanf("%d",&(*matrix)[i][j]);
		}
	}

}