#ifndef LR26ARR_STACK1_H
#define LR26ARR_STACK1_H
#endif
#include <stdio.h>

#define N 20
#define Tvalue int

struct Stack {
    int first;
    Tvalue body[N];
};

void Init(Stack & S) {
    S.first = 0;
}

int Empty(Stack S) {
    return S.first == 0;
}

void Push(Stack & S, Tvalue V) {
    if (S.first == N) {
        printf("STACK IS OVERFLOW\n");
    }
    else S.body[S.first++] = V;
}

Tvalue Pop(Stack & S) {
    if (Empty(S)) {
        return -1;
    }
    else return S.body[--S.first];
}

Tvalue Top(Stack S) {
    if (Empty(S)) {
        return -1;
    }
    else return S.body[S.first - 1];
}

int Size(Stack S) {
    return S.first;
}

void Display(Stack S) {
    printf("[ ");
    for (int i = 0; i < S.first; i++) {
        printf("%d ", S.body[i]);
    }
    printf("]\n");
}
bool stack1 = true;