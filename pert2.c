#include<stdio.h>
int a[100];
int max, min;
void maxmin();

int main(){
  int i, num;

  printf("\n\t\t\tMaximum dan Minimum\n\n");
  printf("Masukkan Banyak Angka : ");
  scanf("%d", &num);

  printf("\nMasukkan angka-angkanya : \n");
  for (i = 0; i < num; i++){
    scanf("%d", &a[i]);
  }

  printf("\nAngka-angkanya adalah : \n");
  for (i = 0; i < num; i++){
    printf("%d ", a[i]);
  }

  max = a[0];
  min = a[0];
  maxmin(0, num - 1);
  printf("\n\nMaksimum Angka : %d\n", max);
  printf("Minimum Angka : %d\n", min);
  return 0;
}

void maxmin(int i, int j){
  int max1, min1, mid;
  if (i == j){
    max = min = a[i];
  } else if (i == j - 1){
    if (a[i] > a[j]){
      max = a[i];
      min = a[j];
    } else {
      max = a[j];
      min = a[i];
    }
  } else {
    mid = (i + j) / 2;
    maxmin(i, mid);
    max1 = max;
    min1 = min;
    maxmin(mid + 1, j);
    if (max < max1)
      max = max1;
    if (min > min1)
      min = min1;
  }
}