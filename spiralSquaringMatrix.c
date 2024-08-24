#include <stdio.h>
#include <stdlib.h>

int main() {
    int m = 0;

    // Принимаем число - размер квадратной матрицы и проверяем его валидность
    int counter = scanf("%d", &m);
    char temp = getchar();
    if (m < 1 || counter != 1 || (temp != '\n' && temp != '\0')) {
        printf("n/a");
        return 0;
    }

    // Динамически создаем матрицу размером M*M
    int** matrix = (int**)malloc(m * (sizeof(int*)));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(m * sizeof(int));
    }

    /*
     * Переменная x1 показывает нам сколько столбцов было уже заполнено слева
     * Переменная y1 показывает нам сколько строк было уже заполнено сверху
     * Переменная x2 показывает нам сколько столбцов было уже заполнено справа
     * Переменная y2 показывает нам сколько строк было уже заполнено снизу
     * Переменная lap отвечает за текущий виток заполнения матрицы
     * Переменная way указывает на то к какой группе принадлежит конкретный виток
     *   1 - Движение вниз
     *   2 - Движение вправо
     *   3 - Движение вверх
     *   4 - Движение влево
     */
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, lap = 0, way = 1;
    counter = 0;

    for (; lap < 2 * m - 1; lap++) {
        switch (way) {
            case 1:
                way = 2;
                for (int i = x1; i < m - y2; i++) {
                    matrix[i][y1] = counter * counter;
                    counter++;
                }
                x1++;
                break;
            case 2:
                way = 3;
                for (int i = x1; i < m - x2; i++) {
                    matrix[m - 1 - x2][i] = counter * counter;
                    counter++;
                }
                y2++;
                break;
            case 3:
                way = 4;
                for (int i = m - 1 - y2; i >= y1; i--) {
                    matrix[i][m - 1 - x2] = counter * counter;
                    counter++;
                }
                x2++;
                break;
            case 4:
                way = 1;
                for (int i = m - 1 - x2; i >= x1; i--) {
                    matrix[y1][i] = counter * counter;
                    counter++;
                }
                y1++;
                break;
        }
    }

    // Вывод матрицы на консоль
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
            if (j + 1 < m) {
                printf(" ");
            }
        }
        if (i + 1 < m) {
            printf("\n");
        }
    }

    // Очистка памяти матрицы
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
