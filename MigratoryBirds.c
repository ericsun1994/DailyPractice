
//  https://www.hackerrank.com/challenges/migratory-birds/problem
/ *   
  *   Problem : Migratory Birds.
  *   Difficulty : Easy
  *   Date: 2019-11-20 WED
  * /
  
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

// Complete the migratoryBirds function below.
int findMaxNumber(int arr_count, int *arr)
{
    int i;
    int max;
    int tmp = 0;
    max = arr[0];

    for(i=1; i<arr_count; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }
 
    for(i=arr_count-1; i>0; i--)
    {
        if(arr[i] == max)
            birdId = i+1;
    } 
 
    return tmp;
}

int migratoryBirds(int arr_count, int* arr) {
    
    int i;
    int tmp[arr_count];
    int num=0;

    for(i=0; i<arr_count; i++)
    {
        tmp[i] = 0;
    }

    for(i=0; i<arr_count; i++)
    {   
        if(arr[i]==1){
            tmp[0]++;
        }else if(arr[i]==2){
            tmp[1]++; 
        }else if(arr[i]==3){
            tmp[2]++;
        }else if(arr[i]==4){
            tmp[3]++;
        }else if(arr[i]==5){
            tmp[4]++;
        }
    }    
    num = findMaxNumber(arr_count, tmp);

    return num; 
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* arr_count_endptr;
    char* arr_count_str = ltrim(rtrim(readline()));
    int arr_count = strtol(arr_count_str, &arr_count_endptr, 10);

    if (arr_count_endptr == arr_count_str || *arr_count_endptr != '\0') { exit(EXIT_FAILURE); }

    char** arr_temp = split_string(rtrim(readline()));

    int* arr = malloc(arr_count * sizeof(int));

    for (int i = 0; i < arr_count; i++) {
        char* arr_item_endptr;
        char* arr_item_str = *(arr_temp + i);
        int arr_item = strtol(arr_item_str, &arr_item_endptr, 10);

        if (arr_item_endptr == arr_item_str || *arr_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(arr + i) = arr_item;
    }

    int result = migratoryBirds(arr_count, arr);

    fprintf(fptr, "%d", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
