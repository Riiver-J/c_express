#include <stdio.h>

struct point {
	int x, y;
};
typedef struct circle {
	struct point center;		
	double radius;	
}CIRCLE;

double area(CIRCLE c) {
	return c.radius * c.radius * 3.14;
}
double perimeter(CIRCLE c) {
	return 2.0 * c.radius * 3.14;
}
int main(void)
{
	CIRCLE c;
	
	printf("원의 중심점: ");
	scanf("%d %d", &c.center.x, &c.center.y);
	printf("원의 반지름: ");
	scanf("%lf", &c.radius);
	printf("원의 면적=%f, 원의 둘레=%f \n", area(c), perimeter(c));
	
	return 0;
}