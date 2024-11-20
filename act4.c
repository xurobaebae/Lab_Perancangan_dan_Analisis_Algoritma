//blok 1
#include <stdio.h>

int q[20], top = -1, front = -1, rear = -1, a[20][20], vis[20], stack[20];

int del();
void add(int item);
void bfs(int s, int n);
void dfs(int s, int n);
void push(int item);
int pop();

//blok 2
int main() {
    int n, i, s, ch, j;
    printf("Masukkan berapa edge: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("Masukkan %d jika mempunyai simpul %d selain itu 0: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    //blok 3
    printf("\nMatriks Adjasensi\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    //blok 4

    for (i = 1; i <= n; i++)
        vis[i] = 0;

    printf("\n---MENU---\n");
    printf("1. BFS\n");
    printf("2. DFS\n");
    printf("Pilihan: ");
    scanf("%d", &ch);
    printf("\nMasukan simpul sumber: ");
    scanf("%d", &s);

    switch (ch) {
        case 1:
            bfs(s, n);
            break;
        case 2:
            dfs(s, n);
            break;
        default:
            printf("=== SALAH INPUT ===");
            break;
    }
    return 0;
}

//blok 5

void bfs(int s, int n) {
    int p, i;
    add(s);
    vis[s] = 1;
    p = del();
    if (p != 0) {
        printf("%d\n", p);
    }
    while (p != 0) {
        for (i = 1; i <= n; i++) {
            if ((a[p][i] != 0) && (vis[i] == 0)) {
                add(i);
                vis[i] = 1;
            }
        }
        p = del();
        if (p != 0)
            printf("%d\n", p);
    }
    for (i = 1; i <= n; i++) {
        if (vis[i] == 0)
            bfs(i, n);
    }
}

//blok 6

void add(int item) {
    if (rear == 19)
        printf("Antrian full\n");
    else {
        if (rear == -1) {
            q[++rear] = item;
            front++;
        } else {
            q[++rear] = item;
        }
    }
}

//blok 7

int del() {
    int k;
    if ((front > rear) || (front == -1))
        return 0;
    else {
        k = q[front++];
        return k;
    }
}

//blok 8

void dfs(int s, int n) {
    int i, k;
    push(s);
    vis[s] = 1;
    k = pop();
    if (k != 0) {
        printf("%d\n", k);
    }
    while (k != 0) {
        for (i = 1; i <= n; i++) {
            if ((a[k][i] != 0) && (vis[i] == 0)) {
                push(i);
                vis[i] = 1;
            }
        }
        k = pop();
        if (k != 0)
            printf("%d\n", k);
    }
    for (i = 1; i <= n; i++) {
        if (vis[i] == 0)
            dfs(i, n);
    }
}

//blok 9

void push(int item) {
    if (top == 19)
        printf("Stack penuh\n");
    else
        stack[++top] = item;
}

int pop() {
    int k;
    if (top == -1)
        return 0;
    else {
        k = stack[top--];
        return k;
    }
}