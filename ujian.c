#include <stdio.h>
#include <stdlib.h>

char q[20];
int front = -1, rear = -1, a[20][20], vis[20];

char del();
void add(char item);
void bfs(char s, int n);
int char_to_index(char c);
char index_to_char(int i);

int main() {
    int n, i, j;
    char s;

    printf("Masukkan jumlah simpul (maksimal 26): ");
    scanf("%d", &n);

    if (n > 26) {
        printf("Jumlah simpul maksimal adalah 26.\n");
        return -1;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Masukkan 1 jika terdapat hubungan antara %c dan %c, selain itu 0: ", index_to_char(i), index_to_char(j));
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nMatriks Adjasensi\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++)
        vis[i] = 0;

    printf("\nMasukkan simpul sumber: ");
    scanf(" %c", &s);

    bfs(s, n);

    return 0;
}

void bfs(char s, int n) {
    int i, p_index;
    char p;
    
    add(s);
    vis[char_to_index(s)] = 1;
    p = del();
    
    if (p != 0) {
        printf("%c\n", p);
    }
    
    while (p != 0) {
        p_index = char_to_index(p);
        for (i = 0; i < n; i++) {
            if ((a[p_index][i] != 0) && (vis[i] == 0)) {
                add(index_to_char(i));
                vis[i] = 1;
            }
        }
        p = del();
        if (p != 0) {
            printf("%c\n", p);
        }
    }
}

void add(char item) {
    if (rear == 19)
        printf("Antrian penuh\n");
    else {
        if (rear == -1) {
            q[++rear] = item;
            front++;
        } else {
            q[++rear] = item;
        }
    }
}

char del() {
    char k;
    if ((front > rear) || (front == -1))
        return 0;
    else {
        k = q[front++];
        return k;
    }
}

int char_to_index(char c) {
    return c - 'a';
}

char index_to_char(int i) {
    return (char) (i + 'a');
}