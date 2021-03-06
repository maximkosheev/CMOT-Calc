#include <math.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

// ����� ��������� ����� �����
double S_array[10][13] = {
    {18.99, 22.64, 24.45, 26.24, 28.02, 29.79, 33.29, 36.75, 40.15, 43.50, 46.81, 50.06, 53.27},
    {0,      31.52, 34.06, 36.6, 39.12, 41.63, 46.61, 51.54, 56.43, 61.26, 66.04, 70.78, 75.46},
    {0,      0,      42.72, 45.92, 49.11, 52.28, 58.6, 64.86, 71.07, 77.24, 83.36, 89.42, 95.44},
    {0,      0,      0,      0,      58.73, 62.54, 70.14, 77.68, 85.18, 92.63, 100.03, 107.38, 114.68},
    {0,      0,      0,      0,      0,      0,      81.68, 90.51, 99.29, 108.02, 116.7, 125.33, 133.91},
    {0,      0,      0,      0,      0,      0,      92.56, 102.59, 112.58, 122.52, 132.41, 142.25, 152.04},
    {0,      0,      0,      0,      0,      0,      115.64, 128.24, 140.79, 153.3, 165.75, 178.16, 190.51},
    {0,      0,      0,      0,      0,      0,      0,      152.83, 167.84, 182.8, 197.72, 212.58, 0},
    {0,      0,      0,      0,      0,      0,      0,      175.02, 192.25, 209.43, 226.56, 243.64, 0},
    {0,      0,      0,      0,      0,      0,      0,      199.67, 219.36, 239.01, 258.6, 278.15, 0}
};

// ������� ������ ������������
double S1_array[10][13] = {
    {6, 6, 8, 8, 8, 8, 10, 10, 12, 12, 14, 14, 16},
    {0,  6, 8, 8, 8, 8, 10, 10, 12, 12, 14, 14, 16},
    {0,  0,  8, 8, 8, 8, 10, 10, 12, 12, 14, 14, 16},
    {0,  0,  0,  0,  8, 8, 10, 10, 12, 12, 14, 14, 16},
    {0,  0,  0,  0,  0,  0,  10, 10, 12, 12, 14, 14, 16},
    {0,  0,  0,  0,  0,  0,  10, 10, 12, 12, 14, 14, 16},
    {0,  0,  0,  0,  0,  0,  10, 10, 12, 12, 14, 14, 16},
    {0,  0,  0,  0,  0,  0,  0,   10, 12, 12, 14, 14, 0},
    {0,  0,  0,  0,  0,  0,  0,   10, 12, 12, 14, 14, 0},
    {0,  0,  0,  0,  0,  0,  0,   10, 12, 12, 14, 14, 0}
};

// ����� ������������� ������������
double S2_array[10][13] = {
    {1.5, 2.3, 2.3, 2.3, 2.3, 2.3, 2.3, 2.3, 2.3, 2.3, 2.3, 2.3, 2.3},
    {0,    4.6, 4.6, 4.6, 4.6, 4.6, 4.6, 5.1, 5.1, 5.1, 5.1, 5.1, 5.1},
    {0,    0,    4.9, 4.9, 4.9, 4.9, 4.9, 9.2, 9.2, 9.2, 9.2, 9.2, 9.2},
    {0,    0,    0,    0,   11.0, 11.0, 11.0, 11.0, 13, 13, 13, 13,  13},
    {0,    0,    0,    0,    0,    0,    16,  16,  18,  18,  18,  18,  18},
    {0,    0,    0,    0,    0,    0,    19,  19,  23,  23,  23,  23,  23},
    {0,    0,    0,    0,    0,    0,    25,  25,  26.5,26.5,26.5,26.5,26.5},
    {0,    0,    0,    0,    0,    0,    0,    0, 0, 0, 0, 0, 0},
    {0,    0,    0,    0,    0,    0,    0,    0, 0, 0, 0, 0, 0},
    {0,    0,    0,    0,    0,    0,    0,    0, 0, 0, 0, 0, 0}
};

// ����� ������� �������
double S3_array[10][13] = {
    {2.5, 2.5, 2.5, 2.5, 3.1, 3.1, 3.75, 3.75, 3.75, 3.75, 5.0, 5.0, 5.0},
    {0, 4.2, 4.2, 4.2, 4.2, 5.3, 5.3, 6.4, 6.4, 7.4, 7.4, 8.5, 8.5},
    {0, 0, 6.0, 6.0, 6.0, 7.5, 7.5, 9.0, 9.0, 10.5, 10.5, 12.0, 12.0},
    {0, 0, 0, 0, 8.5, 10.7, 10.7, 12.8, 12.8, 15.0, 15.0, 17.1, 17.1},
    {0, 0, 0, 0, 0, 0, 15.0, 15.0, 15.0, 17.5, 17.5, 20.0, 20.0},
    {0, 0, 0, 0, 0, 0, 20.8, 20.8, 20.8, 24.2, 24.2, 27.7, 27.7},
    {0, 0, 0, 0, 0, 0, 30.6, 30.6, 30.6, 35.7, 35.7, 40.8, 40.8},
    {0, 0, 0, 0, 0, 0, 0, 42.2, 42.2, 49.3, 49.3, 56.3, 0},
    {0, 0, 0, 0, 0, 0, 0, 80.3, 80.3, 80.3, 80.3, 80.3, 0},
    {0, 0, 0, 0, 0, 0, 0, 101.7, 101.7, 101.7, 101.7, 101.7, 0}
};

// ����� ������� ����������� �������
double S4_array[10][13] = {
    {3.9, 3.9, 3.9, 3.9, 3.9, 4.9, 4.9, 5.9, 5.9, 6.9, 6.9, 7.8, 7.8},
    {0, 5.7, 5.7, 5.7, 5.7, 7.1, 7.1, 8.5, 8.5, 9.9, 9.9, 11.3, 11.3},
    {0, 0, 7.7, 7.7, 7.7, 9.6, 9.6, 11.5, 11.5, 13.5, 13.5, 15.4, 15.4},
    {0, 0, 0, 0, 10.0, 12.6, 12.6, 15.1, 15.1, 17.6, 17.6, 20.1, 20.1},
    {0, 0, 0, 0, 0, 0, 19.1, 19.1, 19.1, 22.3, 22.3, 25.5, 25.5},
    {0, 0, 0, 0, 0, 0, 23.6, 23.6, 23.6, 27.5, 27.5, 31.4, 31.4},
    {0, 0, 0, 0, 0, 0, 33.9, 33.9, 33.9, 39.6, 39.6, 45.3, 45.3},
    {0, 0, 0, 0, 0, 0, 0, 46.2, 46.2, 53.9, 53.9, 61.6, 0},
    {0, 0, 0, 0, 0, 0, 0, 125.5, 125.5, 125.5, 125.5, 125.5, 0},
    {0, 0, 0, 0, 0, 0, 0, 180.7, 180.7, 180.7, 180.7, 180.7, 0}
};

// ����� ��������� �������
double S5_array[10][13] = {
    {5.2, 5.2, 5.2, 5.2, 5.2, 6.5, 6.5, 7.8, 7.8, 9.1, 9.1, 10.4, 10.4},
    {0, 7.3, 7.3, 7.3, 7.3, 9.3, 9.3, 11.3, 11.3, 13.2, 13.2, 15.1, 15.1},
    {0, 0, 10.2, 10.2, 10.2, 12.7, 12.7, 15.0, 15.0, 18.0, 18.0, 20.6, 20.6},
    {0, 0, 0, 0, 12.5, 16.5, 16.5, 19.5, 19.5, 23.5, 23.5, 26.9, 26.9},
    {0, 0, 0, 0, 0, 0, 24.6, 24.6, 24.6, 29.6, 29.6, 33.8, 33.8},
    {0, 0, 0, 0, 0, 0, 30.3, 30.3, 30.3, 36.5, 36.5, 41.7, 41.7},
    {0, 0, 0, 0, 0, 0, 44.5, 44.5, 44.5, 52.3, 52.3, 59.8, 59.8},
    {0, 0, 0, 0, 0, 0, 0, 60.4, 60.4, 70.1, 70.1, 80.1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

};

//����� ��������� ����������� �������
double S6_array[10][13] = {
    {8.9, 8.9, 8.9, 8.9, 8.9, 11.4, 11.4, 13.9, 13.9, 16.0, 16.0, 18.24, 18.24},
    {0, 16.0, 16.0, 16.0, 16.0, 20.4, 20.4, 24.9, 24.9, 29.1, 29.1, 33.2, 33.2},
    {0, 0, 25.7, 25.7, 25.7, 31.9, 31.9, 38.9, 38.9, 45.9, 45.9, 52.5, 52.5},
    {0, 0, 0, 0, 33.6, 45.9, 45.9, 53.7, 53.7, 66.0, 66.0, 75.4, 75.4},
    {0, 0, 0, 0, 0, 0, 73.0, 76.0, 76.0, 89.7, 89.7, 102.5, 102.5},
    {0, 0, 0, 0, 0, 0, 95.1, 95.1, 95.1, 116.8, 116.8, 133.5, 133.5},
    {0, 0, 0, 0, 0, 0, 154.5, 154.5, 154.5, 182.2, 182.2, 208.2, 208.2},
    {0, 0, 0, 0, 0, 0, 0, 221.9, 221.9, 261.8, 261.8, 299.2, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

};

// ����� ������� �2
double S7_array[10][13] = {
    {5.07, 6.04, 6.04, 7.94, 7.94, 7.94, 7.94, 7.94, 7.94, 7.94, 7.94, 7.94, 7.94},
    {0, 13.0, 13.0, 13.0, 14.78, 14.78, 14.78, 14.78, 14.78, 14.78, 14.78, 14.78, 14.78},
    {0, 0, 28.81, 28.81, 28.81, 28.81, 28.81, 28.81, 28.81, 28.81, 28.81, 28.81, 28.81},
    {0, 0, 0, 0, 38.57, 38.57, 38.57, 38.57, 38.57, 38.57, 38.57, 38.57, 38.57},
    {0, 0, 0, 0, 0, 0, 51.37, 51.37, 51.37, 51.37, 51.37, 51.37, 51.37},
    {0, 0, 0, 0, 0, 0, 87.21, 87.21, 87.21, 87.21, 87.21, 87.21, 87.21},
    {0, 0, 0, 0, 0, 0, 108.48, 108.48, 108.48, 108.48, 108.48, 108.48, 108.48},
    {0, 0, 0, 0, 0, 0, 0, 149.66, 149.66, 149.66, 149.66, 149.66, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// �������� ��������� ������ �3
double S8_array[10][13] = {
    {64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64},
    {0, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88, 88},
    {0, 0, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109},
    {0, 0, 0, 0, 130, 130, 130, 130, 130, 130, 130, 130, 130},
    {0, 0, 0, 0, 0, 0, 151, 151, 151, 151, 151, 151, 151},
    {0, 0, 0, 0, 0, 0, 170, 170, 170, 170, 170, 170, 170},
    {0, 0, 0, 0, 0, 0, 212, 212, 212, 212, 212, 212, 212},
    {0, 0, 0, 0, 0, 0, 252, 252, 252, 252, 252, 252, 252},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// ����� ������ �5
double S9_array[10][13] = {
    {4.35, 4.35, 5.3, 5.3, 5.3, 5.3, 5.3, 5.3, 5.3, 5.3, 5.3, 5.3, 5.3},
    {0, 5.5, 5.5, 5.5, 7.1, 7.1, 7.8, 7.8, 7.8, 7.8, 7.8, 7.8, 7.8},
    {0, 0, 6.8, 6.8, 10.1, 10.1, 12.2, 12.2, 14.3, 14.3, 14.3, 14.3, 14.3},
    {0, 0, 0, 0, 16.3, 16.3, 19.1, 19.1, 19.1, 19.1, 19.1, 19.1, 19.1},
    {0, 0, 0, 0, 0, 0, 19.6, 21.5, 21.5, 25.2, 25.2, 25.2, 25.2},
    {0, 0, 0, 0, 0, 0, 31.9, 31.9, 31.9, 37.6, 37.6, 37.6, 37.6},
    {0, 0, 0, 0, 0, 0, 38.0, 46.2, 46.21, 54.3, 54.3, 54.3, 54.3},
    {0, 0, 0, 0, 0, 0, 0, 61.9, 61.9, 63.9, 63.9, 63.9, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// ����� ������ �6
double S10_array[10][13] = {
   {22.8, 27.6, 27.6, 27.6, 27.6, 37.2, 37.2, 37.2, 37.2, 37.2, 37.2, 37.2, 37.2},
    {0, 60.0, 60.0, 60.0, 60.0, 68.4, 68.4, 85.2, 85.2, 85.2, 85.2, 85.2, 85.2},
    {0, 0, 106.8, 106.8, 106.8, 106.8, 106.8, 106.8, 106.8, 106.8, 106.8, 106.8, 106.8},
    {0, 0, 0, 0, 128.4, 128.4, 128.4, 128.4, 128.4, 128.4, 128.4, 128.4, 128.4},
    {0, 0, 0, 0, 0, 0, 147.6, 147.6, 147.6, 147.6, 147.6, 147.6, 147.6},
    {0, 0, 0, 0, 0, 0, 168.0, 168.0, 168.0, 168.0, 168.0, 168.0, 168.0},
    {0, 0, 0, 0, 0, 0, 213.6, 213.6, 213.6, 213.6, 213.6, 213.6, 213.6},
    {0, 0, 0, 0, 0, 0, 0, 249.6, 249.6, 249.6, 249.6, 249.6, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// ����� ������ �7
double S11_array[10][13] = {
    {11.5, 11.5, 11.5, 11.5, 11.5, 11.5, 11.5, 11.5, 11.5, 11.5, 11.5, 11.5, 11.5},
    {0, 15.9, 15.9, 15.9, 15.9, 15.9, 15.9, 15.9, 15.9, 15.9, 15.9, 15.9, 15.9},
    {0, 0, 19.8, 19.8, 19.8, 19.8, 19.8, 19.8, 19.8, 19.8, 19.8, 19.8, 19.8},
    {0, 0, 0, 0, 46.2, 46.2, 46.2, 46.2, 46.2, 46.2, 46.2, 46.2, 46.2},
    {0, 0, 0, 0, 0, 0, 53.6, 53.6, 53.6, 53.6, 53.6, 53.6, 53.6},
    {0, 0, 0, 0, 0, 0, 79.1, 79.1, 79.1, 79.1, 79.1, 79.1, 79.1},
    {0, 0, 0, 0, 0, 0, 153.9, 153.9, 153.9, 153.9, 153.9, 153.9, 153.9},
    {0, 0, 0, 0, 0, 0, 0, 285.3, 285.3, 285.3, 285.3, 285.3, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

};

// ����� ������ �10
double S12_array[10][13] = {
    {1.2, 1.2, 1.2, 1.2, 1.2, 1.2, 1.2, 1.2, 1.2, 1.2, 1.2, 1.2, 1.2},
    {0, 1.6, 1.6, 1.6, 1.6, 1.6, 1.6, 1.6, 1.6, 1.6, 1.6, 1.6, 1.6},
    {0, 0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0},
    {0, 0, 0, 0, 5.2, 5.2, 5.2, 5.2, 5.2, 5.2, 5.2, 5.2, 5.2},
    {0, 0, 0, 0, 0, 0, 6.1, 6.1, 6.1, 6.1, 6.1, 6.1, 6.1},
    {0, 0, 0, 0, 0, 0, 8.1, 8.1, 8.1, 8.1, 8.1, 8.1, 8.1},
    {0, 0, 0, 0, 0, 0, 15.7, 15.7, 15.7, 15.7, 15.7, 15.7, 15.7},
    {0, 0, 0, 0, 0, 0, 0, 18.7, 18.7, 18.7, 18.7, 18.7, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// ����� ������ �11
double S13_array[10][13] = {
    {1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5},
    {0, 1.8, 1.8, 1.8, 1.8, 1.8, 1.8, 1.8, 1.8, 1.8, 1.8, 1.8, 1.8},
    {0, 0, 2.4, 2.4, 2.4, 2.4, 2.4, 2.4, 2.4, 2.4, 2.4, 2.4, 2.4},
    {0, 0, 0, 0, 6.2, 6.2, 6.2, 6.2, 6.2, 6.2, 6.2, 6.2, 6.2},
    {0, 0, 0, 0, 0, 0, 7.3, 7.3, 7.3, 7.3, 7.3, 7.3, 7.3},
    {0, 0, 0, 0, 0, 0, 9.8, 9.8, 9.8, 9.8, 9.8, 9.8, 9.8},
    {0, 0, 0, 0, 0, 0, 18.8, 18.8, 18.8, 18.8, 18.8, 18.8, 18.8},
    {0, 0, 0, 0, 0, 0, 0, 22.4, 22.4, 22.4, 22.4, 22.4, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// ����� �������� �����������
double S14_array[10][13] = {
    {1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5},
    {0, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5},
    {0, 0, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5},
    {0, 0, 0, 0, 2.9, 2.9, 2.9, 2.9, 2.9, 2.9, 2.9, 2.9, 2.9},
    {0, 0, 0, 0, 0, 0, 2.9, 2.9, 2.9, 2.9, 2.9, 2.9, 2.9},
    {0, 0, 0, 0, 0, 0, 3.8, 3.8, 3.8, 3.8, 3.8, 3.8, 3.8},
    {0, 0, 0, 0, 0, 0, 5.9, 5.9, 5.9, 5.9, 5.9, 5.9, 5.9},
    {0, 0, 0, 0, 0, 0, 0, 9.2, 9.2, 9.2, 9.2, 9.2, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// ����� ������������������ ������
double S15_array[10][13] = {
    {0.39, 0.39, 0.39, 0.39, 0.39, 0.39, 0.39, 0.39, 0.39, 0.39, 0.39, 0.39, 0.39},
    {0, 0.54, 0.54, 0.54, 0.54, 0.54, 0.54, 0.54, 0.54, 0.54, 0.54, 0.54, 0.54},
    {0, 0, 0.67, 0.67, 0.67, 0.67, 0.67, 0.67, 0.67, 0.67, 0.67, 0.67, 0.67},
    {0, 0, 0, 0, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8},
    {0, 0, 0, 0, 0, 0, 0.93, 0.93, 0.93, 0.93, 0.93, 0.93, 0.93},
    {0, 0, 0, 0, 0, 0, 1.05, 1.05, 1.05, 1.05, 1.05, 1.05, 1.05},
    {0, 0, 0, 0, 0, 0, 1.31, 1.31, 1.31, 1.31, 1.31, 1.31, 1.31},
    {0, 0, 0, 0, 0, 0, 0, 1.51, 1.51, 1.51, 1.51, 1.51, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// ����� ��������� ����� �/� ��������
double S16_array[10][13] = {
    {1.2, 1.2, 1.2, 1.2, 1.2, 1.2, 1.2, 1.2, 1.2, 1.2, 1.2, 1.2, 1.2},
    {0, 1.6, 1.6, 1.6, 1.6, 1.6, 1.6, 1.6, 1.6, 1.6, 1.6, 1.6, 1.6},
    {0, 0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0},
    {0, 0, 0, 0, 2.4, 2.4, 2.4, 2.4, 2.4, 2.4, 2.4, 2.4, 2.4},
    {0, 0, 0, 0, 0, 0, 2.8, 2.8, 2.8, 2.8, 2.8, 2.8, 2.8},
    {0, 0, 0, 0, 0, 0, 3.1, 3.1, 3.1, 3.1, 3.1, 3.1, 3.1},
    {0, 0, 0, 0, 0, 0, 3.9, 3.9, 3.9, 3.9, 3.9, 3.9, 3.9},
    {0, 0, 0, 0, 0, 0, 0, 6.5, 6.5, 6.5, 6.5, 6.5, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

double S17_array[10][13] = {
    {2.7, 2.7, 2.7, 2.7, 3.3, 3.3, 3.3, 4.0, 4.0, 4.6, 4.6, 5.3, 5.3},
    {0, 4.0, 4.0, 4.0, 5.0, 5.0, 5.0, 6.1, 6.1, 7.1, 7.1, 8.1, 8.1},
    {0, 0, 7.5, 7.5, 9.4, 9.4, 9.4, 11.3, 11.3, 13.2, 13.2, 15.1, 15.1},
    {0, 0, 0, 0, 14.1, 14.1, 14.1, 16.9, 16.9, 19.7, 19.7, 22.5, 22.5},
    {0, 0, 0, 0, 0, 0, 16.4, 19.7, 19.7, 23.0, 23.0, 26.3, 26.3},
    {0, 0, 0, 0, 0, 0, 25.1, 30.1, 30.1, 35.1, 35.1, 40.1, 40.1},
    {0, 0, 0, 0, 0, 0, 31.3, 37.6, 37.6, 43.9, 43.9, 50.2, 50.2},
    {0, 0, 0, 0, 0, 0, 0, 56.5, 56.5, 65.9, 65.9, 75.3, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    a_array.append("159");
    a_array.append("219");
    a_array.append("273");
    a_array.append("325");
    a_array.append("377");
    a_array.append("426");
    a_array.append("530");
    a_array.append("630");
    a_array.append("720");
    a_array.append("820");

    b_array.append("5");
    b_array.append("6");
    b_array.append("6.5");
    b_array.append("7");
    b_array.append("7.5");
    b_array.append("8");
    b_array.append("9");
    b_array.append("10");
    b_array.append("11");
    b_array.append("12");
    b_array.append("13");
    b_array.append("14");
    b_array.append("15");

    ui->setupUi(this);
    initA();
    // ������� ����
    ui->cb_b->addItems(b_array);
    setDefaultValues();
    updateFormula();
    connect(ui->cb_a, SIGNAL(currentIndexChanged(int)), this, SLOT(onCB_AChanged()));
    connect(ui->cb_a, SIGNAL(currentIndexChanged(int)), this, SLOT(updateFormula()));
    connect(ui->cb_b, SIGNAL(currentIndexChanged(int)), this, SLOT(updateFormula()));
    connect(ui->cb_c, SIGNAL(currentIndexChanged(int)), this, SLOT(updateFormula()));
    connect(ui->cb_d, SIGNAL(currentIndexChanged(int)), this, SLOT(updateFormula()));
    connect(ui->cb_e, SIGNAL(currentIndexChanged(int)), this, SLOT(updateFormula()));
    connect(ui->cb_f, SIGNAL(currentIndexChanged(int)), this, SLOT(updateFormula()));
    connect(ui->cb_g, SIGNAL(currentIndexChanged(int)), this, SLOT(updateFormula()));
    connect(ui->cb_h, SIGNAL(currentIndexChanged(int)), this, SLOT(updateFormula()));
    connect(ui->cb_l, SIGNAL(currentIndexChanged(int)), this, SLOT(updateFormula()));
    connect(ui->cb_r, SIGNAL(currentIndexChanged(int)), this, SLOT(updateFormula()));
    connect(ui->cb_m, SIGNAL(currentIndexChanged(int)), this, SLOT(updateFormula()));
    connect(ui->edtAdditionalSpec, SIGNAL(textChanged(QString)), this, SLOT(updateFormula()));
    connect(ui->pushButton, SIGNAL(pressed()), this, SLOT(calcMass()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clear()
{
    ui->cb_c->clear();
    ui->cb_d->clear();
    ui->cb_e->clear();
    ui->cb_f->clear();
    ui->cb_g->clear();
    ui->cb_h->clear();
    ui->cb_l->clear();
    ui->cb_r->clear();
    ui->cb_m->clear();
}

void MainWindow::initA()
{
    ui->cb_a->clear();
    ui->cb_a->addItems(a_array);
}

void MainWindow::setDefaultValues()
{
    clear();
    // ����� ����
    for (int i = 8; i < 61; i++) {
        ui->cb_c->addItem(QString::number((double)i / 2.0));
    }
    // ��� �����
    ui->cb_d->addItem("�");
    ui->cb_d->addItem("�");
    // ��� ��������
    ui->cb_e->addItem("1");
    ui->cb_e->addItem("1�");
    ui->cb_e->addItem("2");
    ui->cb_e->addItem("2�");
    ui->cb_e->addItem("3");
    ui->cb_e->addItem("4");
    // ��� �����������
    ui->cb_f->addItem("0");
    ui->cb_f->addItem("00");
    ui->cb_f->addItem("�");
    ui->cb_f->addItem("�0");
    ui->cb_f->addItem("�");
    ui->cb_f->addItem("�0");
    ui->cb_f->addItem("�");
    ui->cb_f->addItem("��");
    // ��� ������
    ui->cb_g->addItem("A1");
    ui->cb_g->addItem("A2");
    ui->cb_g->addItem("A3");
    ui->cb_g->addItem("A4");
    ui->cb_g->addItem("A5");
    ui->cb_g->addItem("A6");
    ui->cb_g->addItem("A7");
    ui->cb_g->addItem("A8");
    ui->cb_g->addItem("A9");
    ui->cb_g->addItem("A10");
    ui->cb_g->addItem("A11");
    ui->cb_g->addItem("��");
    // ��� ����������
    ui->cb_h->addItem("�");
    ui->cb_h->addItem("�");
    // ��������������� ��������
    ui->cb_l->addItem("��");
    ui->cb_l->addItem("���");
    // ������� ���� ��������� ����������� � ����������
    ui->cb_r->addItem("1", 1);
    ui->cb_r->addItem("1.5", 1.5);
    ui->cb_r->addItem("2", 2);
    ui->cb_r->addItem("2.5", 2.5);
    ui->cb_r->addItem("3", 3);
    ui->cb_r->addItem("3.5", 3.5);
    ui->cb_r->addItem("4 (1 ����)", 4);
    ui->cb_r->addItem("4.5 (1 ����)", 4.5);
    ui->cb_r->addItem("5 (1 ����)", 5);
    // ����� �����
    ui->cb_m->addItem("09�2�");
    ui->cb_m->addItem("16�2��");
    ui->cb_m->addItem("17�1�");
    ui->cb_m->addItem("14�2");
    ui->cb_m->addItem("Cm3cn5");
    ui->cb_m->addItem("Cm3cn4");
    ui->cb_m->addItem("Cm10");
    ui->cb_m->addItem("Cm20");
}

void MainWindow::onCB_AChanged()
{
    int begin, end;

    clear();
    ui->cb_b->clear();
    switch (ui->cb_a->currentIndex()) {
        case 0:
            begin = 0;
            end = 12;
            break;
        case 1:
            begin = 1;
            end = 12;
            break;
        case 2:
            begin = 2;
            end = 12;
            break;
        case 3:
            begin = 4;
            end = 12;
            break;
        case 4:
        case 5:
        case 6:
            begin = 6;
            end = 12;
            break;
        case 7:
        case 8:
        case 9:
            begin = 7;
            end = 11;
            break;
        default:
            begin = 0;
            end = 12;
    }

    for (int i = begin; i <= end; i++) {
        ui->cb_b->addItem(b_array[i]);
    }

    if (ui->cb_a->currentText() == "720" || ui->cb_a->currentText() == "820") {
        for (int i = 8; i < 24; i++) {
            ui->cb_c->addItem(QString::number((double)i / 2.0));
        }

        ui->cb_d->addItem("�");
        ui->cb_d->addItem("�");

        ui->cb_e->addItem("1");
        ui->cb_e->addItem("1�");
        ui->cb_e->addItem("3");
        ui->cb_e->addItem("4");

        ui->cb_f->addItem("0");
        ui->cb_f->addItem("00");
        ui->cb_f->addItem("�");
        ui->cb_f->addItem("�0");
        ui->cb_f->addItem("�");
        ui->cb_f->addItem("�0");
        ui->cb_f->addItem("��");

        ui->cb_g->addItem("A1");
        ui->cb_g->addItem("A4");
        ui->cb_g->addItem("A8");
        ui->cb_g->addItem("A9");
        ui->cb_g->addItem("��");

        ui->cb_h->addItem("�");

        ui->cb_l->addItem("���");

        ui->cb_r->addItem("1", 1);
        ui->cb_r->addItem("1.5", 1.5);
        ui->cb_r->addItem("2", 2);
        ui->cb_r->addItem("2.5", 2.5);
        ui->cb_r->addItem("3", 3);
        ui->cb_r->addItem("3.5", 3.5);
        ui->cb_r->addItem("4 (1 ����)", 4);
        ui->cb_r->addItem("4.5 (1 ����)", 4.5);
        ui->cb_r->addItem("5 (1 ����)", 5);

        ui->cb_m->addItem("09�2�");
        ui->cb_m->addItem("16�2��");
        ui->cb_m->addItem("17�1�");
        ui->cb_m->addItem("14�2");
        ui->cb_m->addItem("Cm3cn5");
        ui->cb_m->addItem("Cm3cn4");
        ui->cb_m->addItem("Cm10");
        ui->cb_m->addItem("Cm20");
    }
    else if (ui->cb_a->currentText() == "630") {
        setDefaultValues();
        ui->cb_f->clear();
        ui->cb_f->addItem("0");
        ui->cb_f->addItem("00");
        ui->cb_f->addItem("�");
        ui->cb_f->addItem("�0");
        ui->cb_f->addItem("�");
        ui->cb_f->addItem("�0");
        ui->cb_f->addItem("��");
    }
    else {
        setDefaultValues();
    }
}

void MainWindow::updateFormula()
{
    QString a,b,c,d,e,f,g,h,l,r,m;

    a = ui->cb_a->currentText();
    b = ui->cb_b->currentText();
    c = ui->cb_c->currentText();
    d = ui->cb_d->currentText();
    e = ui->cb_e->currentText();
    f = ui->cb_f->currentText();
    g = ui->cb_g->currentText();
    h = ui->cb_h->currentText();
    l = ui->cb_l->currentText();
    r = ui->cb_r->currentText();
    m = ui->cb_m->currentText();
    ui->lblFormula->setText(QString("CMOT-%1/%2-%3-%4-%5-%6-%7-%8-%9/%10-%11 %12")
                            .arg(a)
                            .arg(b)
                            .arg(c)
                            .arg(d)
                            .arg(e)
                            .arg(f)
                            .arg(g)
                            .arg(h)
                            .arg(l)
                            .arg(r)
                            .arg(m)
                            .arg(ui->edtAdditionalSpec->text()));
}
void MainWindow::calcMass()
{
    double c1 = 0,
        m1 = 0,
        m2 = 0,
        m3 = 0,
        m4 = 0,
        m5 = 0,
        m6 = 0,
        m7 = 0,
        m8 = 0,
        m9 = 0,
        m10 = 0,
        m11 = 0,
        m12 = 0;
    int AIndex = a_array.indexOf(ui->cb_a->currentText());
    int BIndex = b_array.indexOf(ui->cb_b->currentText());
    QString error;

    if (ui->cb_h->currentText() == "�") {
        c1 = ui->cb_c->currentText().toDouble();
        m5 = 0;
        if (c1 < 12) {
            m8 = m9 = 0;
        }
        else if (c1 < 23.5) {
            m8 = S17_array[AIndex][BIndex];
            m9 = 0.5;
        }
        else {
            m8 = 2 * S17_array[AIndex][BIndex];
            m9 = 1;
        }
    }
    else {
         c1 = ui->cb_c->currentText().toDouble() + 0.5;
         m5 = S14_array[AIndex][BIndex];
         if (c1 < 11.5) {
             m8 = m9 = 0;
         }
         else if (c1 < 23) {
             m8 = S17_array[AIndex][BIndex];
             m9 = 0.5;
         }
         else {
             m8 = 2 * S17_array[AIndex][BIndex];
             m9 = 1;
         }
    }
    m1 = c1 * S_array[AIndex][BIndex];

    QString f = ui->cb_f->currentText();
    double a = a_array[AIndex].toDouble();
    double b = b_array[BIndex].toDouble();

    if (f == "0")
        m2 = S_array[AIndex][BIndex] * a / (4000 * sin(15 * 3.1415 / 180));
    else if (f == "00")
        m2 = S_array[AIndex][BIndex] * a / (4000 * sin(15 * 3.1415 / 180)) - 0.005 * b;
    else if (f == "�")
        m2 = S_array[AIndex][BIndex] * a / (4000 * sin(30 * 3.1415 / 180));
    else if (f == "�0")
        m2 = S_array[AIndex][BIndex] * a / (4000 * sin(30 * 3.1415 / 180)) - 0.005 * b;
    else if (f == "�")
        m2 = S1_array[AIndex][BIndex] * a * a * 24.66 / (4000000);
    else if (f == "�0")
        m2 = S1_array[AIndex][BIndex] * a * a * 24.66 / (4000000) - 0.0025 * b;
    else if (f == "�")
        m2 = S2_array[AIndex][BIndex];
    else
        error += "��� ����������� ������ �������";

    QString e = ui->cb_e->currentText();

    if (e == "1")
        m3 = S3_array[AIndex][BIndex];
    else if (e == "1�")
        m3 = S4_array[AIndex][BIndex];
    else if (e == "2")
        m3 = S5_array[AIndex][BIndex];
    else if (e == "2�")
        m3 = S6_array[AIndex][BIndex];
    else if (e == "3" || e == "4")
        m3 = 0;
    else
        error += "��� �������� ������ �� �����";

    QString g = ui->cb_g->currentText();

    if (g == "A2")
        m4 = S7_array[AIndex][BIndex];
    else if (g == "A3")
        m4 = -0.000075 * S8_array[AIndex][BIndex] * S8_array[AIndex][BIndex] * b;
    else if (g == "A5")
        m4 = S9_array[AIndex][BIndex];
    else if (g == "A6")
        m4 = S10_array[AIndex][BIndex];
    else if (g == "A7")
        m4 = S11_array[AIndex][BIndex];
    else if (g == "A10")
        m4 = S12_array[AIndex][BIndex];
    else if (g == "A11")
        m4 = S13_array[AIndex][BIndex];
    else
        m4 = 0;

    QString l = ui->cb_l->currentText();
    double r = ui->cb_r->itemData(ui->cb_r->currentIndex()).toDouble();

    if (l == "���") {
        m6 = 0;
        m7 = 0;
    }
    else
    {
        m6 = S15_array[AIndex][BIndex];
        m7 = S16_array[AIndex][BIndex] * (r + 0.4);
    }

    m10 = m1 + m2 + m3 + m4 + m5 + m6 + m8 + m9;
    m11 = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9;
    m12 = m1 + m2 + m3 + m4 + m6 + m7 + m8 + m9;

    if (l == "�")
        m12 = m12 - S_array[AIndex][BIndex] * 0.5;

    ui->lblRes1->setText(QString::number(m10, 'f', 2));
    ui->lblRes2->setText(QString::number(m11, 'f', 2));
    ui->lblRes3->setText(QString::number(m12, 'f', 2));
}

