#include <stdio.h>

void smult(int A[][3], int, int B[][3]);
void print(int A[][3]);

int main(void) {
  int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int B[3][3];

  smult(A, 2, B);
  print(B);
  return 0;
}

void smult(int A[][3], int scalar, int B[][3]) {
  int r, c;
  for (r = 0; r < 3; r++) {
    for (c = 0; c < 3; c++) {
      B[r][c] = scalar * A[r][c];
    }
  }
}
void print(int A[][3]) {
  int r, c;
  for (r = 0; r < 3; r++) {
    for (c = 0; c < 3; c++)
      printf("%3d ", A[r][c]);
    printf("\n");
  }
}

