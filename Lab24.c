#include <stdio.h>
#include <stdlib.h>

struct Man {
    char lastName[50];
    int age;
    char hairColor[30];
    char address[100];
    float salary;
};

int main() {
    int n;
    FILE *fp;

    printf("Введіть кількість чоловіків: ");
    scanf("%d", &n);

    struct Man men[n];

    printf("\n--- Введення даних про чоловіків ---\n");
    for (int i = 0; i < n; ++i) {
        printf("\nВведіть дані для чоловіка #%d:\n", i + 1);
        printf("Прізвище: ");
        scanf("%s", men[i].lastName);
        printf("Вік: ");
        scanf("%d", &men[i].age);
        printf("Колір волосся: ");
        scanf("%s", men[i].hairColor);
        printf("Адреса (одним словом або використовуйте _ замість пробілів): ");
        scanf("%s", men[i].address);
        printf("Зарплата: ");
        scanf("%f", &men[i].salary);
    }

    fp = fopen("men_data.txt", "w");
    if (fp == NULL) {
        printf("Помилка відкриття файлу для запису!\n");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        fprintf(fp, "%s %d %s %s %.2f\n", men[i].lastName, men[i].age, men[i].hairColor, men[i].address, men[i].salary);
    }
    fclose(fp);
    printf("\nДані про чоловіків успішно записано в файл 'men_data.txt'.\n");

    printf("\n--- Оновлення зарплат ---\n");
    for (int i = 0; i < n; ++i) {
        printf("Поточна зарплата для %s: %.2f\n", men[i].lastName, men[i].salary);
        printf("Введіть нову зарплату для %s: ", men[i].lastName);
        scanf("%f", &men[i].salary);
    }

    fp = fopen("men_data.txt", "w");
    if (fp == NULL) {
        printf("Помилка відкриття файлу для оновлення!\n");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        fprintf(fp, "%s %d %s %s %.2f\n", men[i].lastName, men[i].age, men[i].hairColor, men[i].address, men[i].salary);
    }
    fclose(fp);

    printf("\nДані про зарплати успішно оновлено в файлі 'men_data.txt'.\n");

    return 0;
}