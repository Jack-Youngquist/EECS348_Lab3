/*Header- reads from a file and returns various averages and totals monthly totals.*/
#include <stdio.h>
#define ROWS 12

int monthly_sales(char month_array[][10], float data_array[]){
  printf("Monthly sales report for 2022:\n\n");
  printf("Month\t\tSales\n\n");
  for (int i=0;i<12;i++){
      printf("%s\t$%.2f\n", &month_array[i], data_array[i]);
  }
  printf("\n");
  return 0;
}
int min_max_avg(char month_array[][10], float data_array[]){
  printf("Sale Summary: \n\n");
  for (int i=0;i<12;i++){
    int min = 1;
      for (int j=0;j<12;j++){
        if (data_array[i] > data_array[j]){
          min = 0;
          break;
        }
      }
    if (min == 1){
      printf("Minnimum Sales:\t$%.2f\t(%s)\n", data_array[i], &month_array[i]);
    }
  }
  for (int i=0;i<12;i++){
    int max = 1;
      for (int j=0;j<12;j++){
        if (data_array[i] < data_array[j]){
          max = 0;
          break;
        }
      }
    if (max == 1){
      printf("Maximum Sales:\t$%.2f\t(%s)\n", data_array[i], &month_array[i]);
    }
  }
  float total = 0;
  for (int i=0;i<12;i++){
    total += data_array[i];
  }
  total/=12;//getting average
  printf("Average Sales:\t$%.2f\n\n", total);
  return 0;
}

int six_month_avg(char month_array[][10], float data_array[], int i){
  float total = 0;
  int starting_month = i;
  int j = (i + 6);
  for (i;i<j;i++){
    total += data_array[i];
  }
  total/=6;//getting average
  printf("%s\t- %s\t$%.2f\n", &month_array[starting_month], &month_array[i-1], total);
  return 0;
}

int high_low(char month_array[][10], float data_array[]){
  printf("\nSales Report (Highest to Lowest):\n\n  Month\t\t  Sales\n\n");
  float previous_max;
  for (int i=0;i<12;i++){
    int max = 1;
    for (int j=0;j<12;j++){
      if (data_array[i] < data_array[j]){
        max = 0;
        break;
      }
    }
    if (max == 1){
      previous_max = data_array[i];
      printf("%s\t$%.2f\n", &month_array[i], data_array[i]);
      break;
    }
  }
  for (int k=0;k<11;k++){
    for (int i=0;i<12;i++){
      int max = 1;
        for (int j=0;j<12;j++){
          if (((data_array[i] < data_array[j]) && (data_array[j]<previous_max)) || (data_array[i] >= previous_max)){
            max = 0;
            break;
          }
        }
      if (max == 1){
        previous_max = data_array[i];
        printf("%s\t$%.2f\n", &month_array[i], data_array[i]);
        break;
      }
    }
  }
}

int main(){
  float array[ROWS];
  char months[][10]={"January  ", "Febuary  ", "March    ", "April    ", "May      ", "June     ", "July    ", "August   ", "September", "October  ", "November ", "December "};
  FILE *file;
  char file_name [100];
  //printf("Enter file name: ");
  //scanf("%s", &file_name);
  file = fopen("sample.txt", "r");
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
  int row = 0;

  while (!feof(file)) {
    if (ferror(file)){
      printf("Error reading file.\n");
      return 1;
    }
    if (fscanf(file, "%f", &array[row]) == EOF){
      break;
    }
    row++;
    if (row == ROWS) break;
  }
  fclose(file);
  monthly_sales(months, array);
  min_max_avg(months, array);
  printf("Six-Month Moving Average Report:\n\n");
  six_month_avg(months, array, 0);
  six_month_avg(months, array, 1);
  six_month_avg(months, array, 2);
  six_month_avg(months, array, 3);
  six_month_avg(months, array, 4);
  six_month_avg(months, array, 5);
  six_month_avg(months, array, 6);
  high_low(months, array);
  return 0;
}