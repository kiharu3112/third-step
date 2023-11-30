#include <math.h>
#include <stdio.h>

int calcSum(int nums[], int n) {
  int sum = 0;

  for (int i = 0; i < n; i++) {
    sum = sum + nums[i];
  }

  return sum;
}
double calcAve(int nums[], int n) {

  if (n == 0) {
    printf("nが0なので平均が計算できません\n");
    return 0;
  }

  int sum = calcSum(nums, n);
  double ave = (double)sum / (double)n;

  return ave;
}

double calcVar(int nums[], int n) {

  if (n == 0) {
    printf("nが0なので分散が計算できません\n");
    return 0;
  }

  double ave = calcAve(nums, n);
  double sum;

  sum = 0;
  for (int i = 0; i < n; i++) {
    double y = (nums[i] - ave) * (nums[i] - ave);
    sum = sum + y;
  }

  double var = sum / n;

  return var;
}

int descSort(int nums[], int n) {
  int tmp;

  for (int i = 0; i < n - 1; i++) {
    for (int j = n - 1; j > i; j--) {
      if (nums[j - 1] < nums[j]) {
        tmp = nums[j];
        nums[j] = nums[j - 1];
        nums[j - 1] = tmp;
      }
    }
  }

  return 0;
}

int main() {
  int science[20] = {65, 80, 67, 35, 58, 60, 72, 68, 92, 36,
                     50, 25, 85, 46, 42, 78, 62, 84, 70};
  int english[20] = {44, 87, 100, 63, 52, 60, 58, 73, 55, 86,
                     29, 56, 89,  23, 65, 84, 64, 27, 86, 84};
  // 平均点,標準偏差,合計点を求める
  printf("理科の平均点は%fです\n", calcAve(science, 20));
  printf("英語の平均点は%fです\n", calcAve(english, 20));
  printf("理科の標準偏差は%fです\n", sqrt(calcVar(science, 20)));
  printf("英語の標準偏差は%fです\n", sqrt(calcVar(english, 20)));
  printf("理科の合計点は%dです\n", calcSum(science, 20));
  printf("英語の合計点は%dです\n", calcSum(english, 20));
  printf("それぞれの人毎の平均点\n");
  for (int i = 0; i < 20; i++) {
    printf("%d人目の理科の偏差値は%fです\n", i + 1,
           (science[i] - calcAve(science, 20)) / sqrt(calcVar(science, 20)));
    printf("%d人目の英語の偏差値は%fです\n", i + 1,
           (english[i] - calcAve(english, 20)) / sqrt(calcVar(english, 20)));
  }
  
  // 降順にソートする
  printf("理科の降順にソートした結果\n");
  descSort(science, 20);
  for (int i = 0; i < 20; i++) {
    printf("%d, ",science[i]);
  }
  printf("\n");
  printf("英語の降順にソートした結果\n");
  descSort(english, 20);
  for (int i = 0; i < 20; i++) {
    printf("%d, ",english[i]);
  }
  printf("\n");
  return 0;
}
