#include <stdio.h>
#include <string.h>

void addBigNumbers(char first[], char second[], char result[]);
void sortBigNumbers(char* bigNumbers[], int N);
int main() {

return 0;
}
void addBigNumbers(char first[], char second[], char result[]) {

    for (int i=0; i < strlen(first); i++) {
        if (first[i] < '0' || first[i] > '9') {
            strcpy(result, "error");

            return;
        }
    }
    for (int j =0; j < strlen(second); j++) {
        if (second[j] < '0' || second[j] > '9') {
            strcpy(result, "error");
            return;

        }

    }
    int carry = 0, sum = 0, k = 0, j = strlen(second) - 1, i = strlen(first) - 1, temp = 0, hold = 0;
        for (; i >= 0 || j >= 0; i--, j--) {

            if (i < 0) {
                sum = (int) (second[j]) - 48 + carry;
                carry = sum / 10;
                result[k] = (char) (sum % 10) + 48;
            } else if (j < 0) {
                sum = (int) (first[i]) - 48 + carry;
                carry = sum / 10;
                result[k] = (char) (sum % 10) + 48;
            } else {
                hold = (int) (first[i]) - 48;
                temp = (int) (second[j]) - 48;

                sum = carry + hold + temp;
                if(sum>9){
                    carry=sum/10;
                    sum%=10;
                }
                result[k] = (char) (sum % 10) + 48;

            }
            k++;

        }

          if (carry != 0) {
            result[k] = (char) (carry) + 48;
            k++;
          }
          result[k]='\0';
          result = strrev(result);
    }



void swap(int *first[], int *second[])
{
    int temp = *first;
    first = second;
    second = temp;
}

void sortBigNumbers(char* bigNumbers[], int N) {

    int i =0 , j = i+1;
    for(; i < N;i++) {
        for(j=i+1; j < N; j++) {
            if(strlen(bigNumbers[i]) > strlen(bigNumbers[j])) {
                char *temp = bigNumbers[i];
                bigNumbers[i] = bigNumbers[j];
                bigNumbers[j] = temp;
            }
    }
    }
}