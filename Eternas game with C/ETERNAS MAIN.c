#include<stdio.h>

#include <conio.h>

#include<stdlib.h>

int stack[8][4];
int x = 0, top = -1;
void push(int);
void pop(void);
void display(void);
int main() {

  int ch = -1, n, i, j, q;
  int random;
  int ran;

  printf("\n\n  ETERNAS GAME SOFTWARE  \n\n");
  printf(" 5 REPRESENTS WHITE BEADS  \n\n");
  printf(" 6 REPRESENTS GREEN BEADS  \n\n");
  printf(" Whoever gets 20 or 24 points will win.  \n\n");
  while (ch != 0) {
    int beads [31]={5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6};
    int bcount = sizeof(beads) / sizeof(beads[0]);
    int c = 31;
    int de = 10;
    printf("\n 1.START THE GAME\n");
    printf(" 2.SHOW THE RESULT\n");
    printf(" 3.CLEAR STACKS\n");
    scanf("%d", & ch);
    switch (ch) {
    case 1: {
      srand(time(NULL));

      shuffle(beads, bcount);

      push(5);
      for (i = 0; i < bcount; i++) {
        push(beads[i]);
      }

      break;
    }
    case 2: {
      display();
      break;
    }
    case 3: {

      pop();

      break;
    }
    }

  }
  return 0;
}
void push(int n) {
  if (top == 3) {
    x++;
    top = -1;
  }
  if (x == 8)
    printf("the stacks are full\n");
  else {
    stack[x][++top] = n;

  }

}
void pop() {
  if (x == 0 && top == -1)
    printf("\nstacks are already empty\n");
  else {
    x = 0;
    top = -1;
    printf("\nstacks unloaded  \n");
  }

}
void display(void) {
  printf("x=%d top=%d\n", x, top);
  int i, j;
  int temp;
  int a = 0;
  int b = 0;
  int total = 0;
 
  int tdizi[8];
  if (x == 0 && top == -1)
    printf("empty\n");
  else
    for (i = 0; i <= x; i++) {
      if (i == x) {
        for (j = 0; j <= top; j++) {
          total = total + stack[i][j];
          tdizi[i] = total;
          printf("%d ", stack[i][j]);

        }
        printf(" ==>%d total score\n", total);

      } else {
        for (j = 0; j <= 3; j++) {
          total = total + stack[i][j];
          tdizi[i] = total;
          printf("%d ", stack[i][j]);
        }
        printf(" ==>%d total score\n", total);

        total = 0;

      }

    }

  for (i = 0; i < 8; i++) {
    if (20 == tdizi[i]) {
      a = 1;
      temp = i;

    }
    if (24 == tdizi[i]) {
      b = 1;
      temp = i;

    }

  }
  if (a == 1 && b == 1) {
    printf("\nthe game in a draw \n");
  }
  if (a == 0 && b == 0) {
    printf("\nthe game in a draw \n");
  }
  if (a == 1 && b == 0) {
    printf("\nPlayer 1 won There are 4 white beads in the  %d. stack .\n", (temp + 1));
  }
  if (a == 0 && b == 1) {
    printf("\nPlayer 2 won There are 4 green beads in the  %d. stack .\n", (temp + 1));
  }

}
void swap(int A[], int i, int j) {
  int temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}
void shuffle(int A[], int n) {
  int i;

  for (i = n - 1; i >= 1; i--) {

    int j = rand() % (i + 1);

    swap(A, i, j);
  }
}

