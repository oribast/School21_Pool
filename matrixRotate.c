#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n, value, flag = 0;

    // Принимаем число - размер квадратной матрицы и проверяем его валидность
    int counter = scanf("%d %d", &m, &n);
    char temp = getchar();
    if (m < 1 || n < 1 || counter != 2 || (temp != '\n' && temp != '\0')) {
        printf("n/a");
        return 0;
    }

    // Динамически создаем матрицу размером M*M
    int** matrix = (int**)malloc(m * (sizeof(int*)));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    int** resMatrix = (int**)malloc(n * (sizeof(int*)));
    for (int i = 0; i < n; i++) {
        resMatrix[i] = (int*)malloc(m * sizeof(int));
    }

    // Заполняем матрицу значениями, предварительно проверив их валидность
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            counter = scanf("%d", &value);
            temp = getchar();
            if (counter != 1 || (temp != '\n' && temp != '\0' && temp != ' ')) {
                flag = 1;
                break;
            }
            matrix[i][j] = value;
        }
        if (flag) {
            break;
        }
    }
    if (!flag) {
        // Поворачиваем матрицу на 90 градусов вправо
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                resMatrix[j][m - 1 - i] = matrix[i][j];
            }
        }

        // Выводим матрицу
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d", resMatrix[i][j]);
                if (j + 1 < m) {
                    printf(" ");
                }
            }
            if (i + 1 < n) {
                printf("\n");
            }
        }
    }
    // Очистки
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < n; i++) {
        free(resMatrix[i]);
    }
    free(resMatrix);

    return 0;
}
