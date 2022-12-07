#include <stdio.h>
double get_average(int list[], int n);

int main(void)
{
	int score[3][3] = { {100, 30, 67}, {89, 50, 12}, {19, 60, 90} };
	int i;
	double avg;
	
	for (i = 0; i < 3; i++) {
		avg = get_average(score[i], 3);
		printf("%d행 학생의 평균값=%f\n", i, avg);
	}
	return 0;
}
double get_average(int list[], int n)
{
	int i;
	double sum = 0;
	
	for (i = 0; i < n; i++)
		sum += list[i];
	return (double)sum / n;
}