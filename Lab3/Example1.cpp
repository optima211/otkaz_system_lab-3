#include<omp.h>
#include<iostream>
#include<stdio.h>
#include<string>
#include<conio.h>

const int N = 100; //N из условия задачи (высота и ширина двумерного массива)

int main()
{
	using namespace std;
	printf("Exercise 1:\n");
	{
		int A[N];	//первый массив
		//инициализируем массив
		for (int i = 0; i < N; i++) {
			A[i] = i + 10;
		}

		//пример обычной (не параллельной) суммы
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
		double A[N][N];	//первый массив
		double B[N][N];	//второй массив


		#pragma omp parallel num_threads(2)
		{
			//задаём секции
			#pragma omp sections
			{
				//задаём первый массив
				#pragma omp section
				{
					printf("First massive, proccess %i\n", omp_get_thread_num());
					for (int i = 0; i < N; i++) {
						for (int j = 0; j < N; j++) {
							A[i][j] = (double)rand() / 35536 * 3;
						}
					}
				}
				//задаём второй массив
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