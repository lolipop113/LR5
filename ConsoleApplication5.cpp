#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#define MAX_N 10 // Максимальная размерность матрицы смежности
int main() {
	setlocale(LC_ALL, "Rus");
	int N; // Размерность матрицы смежности
	int adjacencyMatrix[MAX_N][MAX_N];
	int isolatedVertices[MAX_N] = { 0 }; 
	int terminalVertices[MAX_N] = { 0 }; 
	int dominatingVertices[MAX_N] = { 0 };
	int isolatedVertices1[MAX_N] = { 0 };
	int terminalVertices1[MAX_N] = { 0 };
	int dominatingVertices1[MAX_N] = { 0 }; 

	int edgeCount = 0; // Счетчик ребер
	int edgeCount1 = 0; 
	srand(time(NULL)); 
	printf("Введите размерность матрицы смежности (не больше %d): ", MAX_N);
	scanf("%d", &N);

	if (N <= 0 || N > MAX_N) {
		printf("Некорректный ввод размерности матрицы смежности.\n");
		return 1;
	}

	// Заполнение матрицы смежности случайными значениями
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (i == j) {
				adjacencyMatrix[i][j] = 0; // Нет петель
			}
			else {
				int randomValue = rand() % 2; 
				adjacencyMatrix[i][j] = randomValue;
				adjacencyMatrix[j][i] = randomValue; 
				edgeCount += randomValue; 
			}
		}
	}

	int incidenceMatrix[MAX_N][MAX_N]; 

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < edgeCount; j++) {
			incidenceMatrix[i][j] = 0;
		}
	}

	int currentEdge = 0; // Текущее ребро

	// Заполнение матрицы инциденции
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (adjacencyMatrix[i][j] == 1) {
				incidenceMatrix[i][currentEdge] = 1;
				incidenceMatrix[j][currentEdge] = 1;
				currentEdge++;
			}
		}
	}

	// Поиск изолированных, концевых и доминирующих вершин
	for (int i = 0; i < N; i++) {
		int degree = 0;
		for (int j = 0; j < N; j++) {
			if (adjacencyMatrix[i][j] == 1) {
				degree++;
			}
		}
		if (degree == 0) {
			isolatedVertices[i] = 1; 
		}
		if (degree == 1) {
			terminalVertices[i] = 1; 
		}
		if (degree <= N-1) {
			dominatingVertices[i] = 1; 
		}
	}

	printf("Размер графа G: %d\n", edgeCount);

	printf("Изолированные вершины: ");
	for (int i = 0; i < N; i++) {
		if (isolatedVertices[i] == 1) {
			printf("%d ", i);
		}
	}
	printf("\n");

	printf("Концевые вершины: ");
	for (int i = 0; i < N; i++) {
		if (terminalVertices[i] == 1) {
			printf("%d ", i);
		}
	}
	printf("\n");

	printf("Доминирующие вершины: ");
	for (int i = 0; i < N; i++) {
		if (dominatingVertices[i] == 1) {
			printf("%d ", i);
		}
	}
	printf("\n");

	printf("Матрица смежности:\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", adjacencyMatrix[i][j]);
		}
		printf("\n");
	}

	// Поиск изолированных, концевых и доминирующих вершин в матрице инциденции
	for (int i = 0; i < N; i++) {
		int degree = 0; // Счетчик степени вершины
		for (int j = 0; j < edgeCount; j++) {
			if (incidenceMatrix[i][j] == 1) {
				degree++;
			}
		}
		if (degree == 0) {
			isolatedVertices1[i] = 1; 
		}
		if (degree == 1) {
			terminalVertices1[i] = 1; 
		}
		if (degree <= N - 1) {
			dominatingVertices1[i] = 1;
		}
	}

	printf("Размер графа G: %d\n", edgeCount);

	printf("Изолированные вершины: ");
	for (int i = 0; i < N; i++) {
		if (isolatedVertices1[i] == 1) {
			printf("%d ", i);
		}
	}
	printf("\n");

	printf("Концевые вершины: ");
	for (int i = 0; i < N; i++) {
		if (terminalVertices1[i] == 1) {
			printf("%d ", i);
		}
	}
	printf("\n");

	printf("Доминирующие вершины: ");
	for (int i = 0; i < N; i++) {
		if (dominatingVertices1[i] == 1) {
			printf("%d ", i);
		}
	}
	printf("\n");

	printf("Матрица инциденции:\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < edgeCount; j++) {
			printf("%d ", incidenceMatrix[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}