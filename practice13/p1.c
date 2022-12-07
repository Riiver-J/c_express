#include <stdio.h>

struct point {
	int x, y;
};

int equal(struct point p1, struct point p2);

int main(void)
{
	struct point p1 = { 1, 2 };
	struct point p2 = { 3, 5 };

	printf("(%d, %d) %s (%d, %d) \n", p1.x, p1.y, equal(p1, p2) ? "==" : "!=", p2.x, p2.y);

	return 0;
}

int equal(struct point p1, struct point p2)
{
	if (p1.x == p2.x && p1.y == p2.y) return 1;
	else return 0;
}
