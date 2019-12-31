#include<omp.h>
#include<iostream>
#include<stdio.h>
#include<string>
#include<conio.h>

const int N = 100; //N �� ������� ������ (������ � ������ ���������� �������)

int main()
{
	using namespace std;
	printf("Exercise 1:\n");
	{
		int A[N];	//������ ������
		//�������������� ������
		for (int i = 0; i < N; i++) {
			A[i] = i + 10;
		}

		//������ ������� (�� ������������) �����
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += A[i];
		}
		printf("Sum is %d\n", sum);

		sum = 0;
		#pragma omp parallel for reduction(+:sum)
		for (int i = 0; i < N; i++) {
			sum += A[i];
		}

		printf("Sum is %d\n", sum);

		getch();
	}
	printf("\n\nExercise 2:\n");
	{
		double A[N][N];	//������ ������
		double B[N][N];	//������ ������


		#pragma omp parallel num_threads(2)
		{
			//����� ������
			#pragma omp sections
			{
				//����� ������ ������
				#pragma omp section
				{
					printf("First massive, proccess %i\n", omp_get_thread_num());
					for (int i = 0; i < N; i++) {
						for (int j = 0; j < N; j++) {
							A[i][j] = (double)rand() / 35536 * 3;
						}
					}
				}
				//����� ������ ������
				#pragma omp section
				{
					printf("Second massive, proccess %i\n", omp_get_thread_num());
					for (int i = 0; i < N; i++) {
						for (int j = 0; j < N; j++) {
							B[i][j] = (double)rand() / 35536 * 3;
						}
					}
				}
			}
		}
		getch();
	}
}