#include <stdio.h>
#include <math.h>
enum shape_type { TRIANGLE, RECTANGLE, CIRCLE };
struct shape {
	int type;
	union {
		struct {
			int base, height;
		} tri;
		struct {
			int width, height;
		} rect;
		struct {
			int radius;
		} circ;
	} p;
};

int main(void)
{
	struct shape s;
	enum shpae_type;
    int type;
	printf("도형의 타입을 입력하시오(0, 1, 2): ");
	scanf("%d", &type);
	switch(type){
	case TRIANGLE:
		printf("밑변과 반지름을 입력하시오(예를 들어서 100 200): ");
		scanf("%d %d", &s.p.tri.base, &s.p.tri.height);
		printf("면적은 %d\n", (int)(0.5*s.p.tri.base*s.p.tri.height));
		break;
	case RECTANGLE:
		printf("가로와 세로의 길이를 입력하시오(예를 들어서 100 200):");
		scanf("%d %d", &s.p.rect.width, &s.p.rect.height);
		printf("면적은 %d\n", (int)(s.p.rect.width*s.p.rect.height));
		break;
	case CIRCLE:
		printf("반지름을 입력하시오(예를 들어서 100): ");
		scanf("%d", &s.p.circ.radius);
		printf("면적은 %d\n", (int)(3.14*s.p.circ.radius*s.p.circ.radius));
		break;
	}
	return 0;
}	