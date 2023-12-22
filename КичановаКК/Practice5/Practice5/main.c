#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAX_PATH 500
void openfile() {
    char directoryPath[MAX_PATH];
    printf("Input way to directory: ");
    scanf("%s", directoryPath);
    if (!SetCurrentDirectory(directoryPath)) {
        printf("Ќе удалось перейти в указанную директорию\n");
        return 1;
    }
    WIN32_FIND_DATA findData;
    HANDLE findHandle = FindFirstFile("*.*", &findData);

    if (findHandle == INVALID_HANDLE_VALUE) {
        printf("Can't find\n");
        return 1;
    }
    char files[100][MAX_PATH];
    int numFiles = 0;

    do {
        if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            strcpy(files[numFiles++], findData.cFileName);
        }
    } while (FindNextFile(findHandle, &findData) != 0);
    FindClose(findHandle);
}

void select(char* files, int file_count) {
    for (int i = 0; i < file_count; i++) {
        for (int j = (i + 1); j < file_count; j++) {
            if (files[i].size < files[j].size) {
                swap(files[i], files[j]);
            }
        }
    }
}
void insert(char* files, int file_count)
{
    for (int i = 1; i < file_count; i++) {
        int min = files[i].size;
        int j = i - 1;
        while ((j >= 0) && (files[j].size > files[i].size)) {
            files[j + 1] = files[j];
            j--;
        }
        files[j] = min;
    }
}
void merge(char* files, int left, int mid, int right) {
    int i1 = 0, i2 = 0, i = 0, n;
    float b[100];
    while ((left + i1 < mid) && (mid + i2 <= right)) {
        if (files[left + i1].size < files[mid + i2].size) {
            b[i] = files[left + i1];
            i1++; i++;
        }
        else { b[i] = files[mid + i2]; i2++; i++; }
    }
}
void mergeSort(char* files, int left, int right) {
    if (left >= right) return;
    mergeSort(files, left, (left + right) / 2);
    mergeSort(files, (left + right) / 2 + 1, right);
    merge(files, left, (left + right) / 2, right);
}
int main() {
    int rep;
    void openfile();
    do {
        int method;
        printf("Methods of sort:\n 1 - selection sort\n 2 - insertion sort\n 3 - merge sort\n");
        printf("Input method: ");
        scanf("%d", &method);
        if (method == 1) { void select(); }
        if (method == 2) { void insert(); }
        if (method == 3) { void mergeSort(); }
        printf("Repeat?\n");
        scanf("%d", &rep);
    } while (rep == 1);
    return 0;
}
