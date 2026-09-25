#include <stdio.h>
#include "const.h"

void cumulative_sum(struct GalaxyShell *full_part, const float G_const, const float base_mass, int count);

void save_to_file(const char *filename, struct GalaxyShell *galaxy) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Ошибка открытия файла %s для записи!\n", filename);
        return;
    }

    fprintf(file ,"-------------------------------------------------------\n");
    fprintf(file ,"Version:0.2.3|By oppenheimer-dev \n");
    fprintf(file ,"-------------------------------------------------------\n");
    fprintf(file ," Step  | Radius   | Big Mass  |Dark Mass  | Velocity  |\n");

    for (int i = 0; i < MAX_PARTICL; i++) {
        fprintf(file ," %3d  | %9.2f | %9.2f | %9.2f | %9.2f | \n", 
               i + 1, 
               galaxy[i].radius, 
               galaxy[i].visible_mass, 
               galaxy[i].dark_mass,
               galaxy[i].velocity);
    }
    fprintf(file ,"-------------------------------------------------------\n");
    fclose(file);
}
int main(void) {
    struct GalaxyShell galaxy[MAX_PARTICL];

    float base_mass = 100.0f;
    cumulative_sum(galaxy, G_CONST, base_mass, MAX_PARTICL);

    printf("-------------------------------------------------------\n");
    printf("Version:0.2.3|By oppenheimer-dev \n");
    printf("-------------------------------------------------------\n");
    printf(" Step  | Radius   | Big Mass  |Dark Mass  | Velocity  |\n");

    // Выводим значения для каждого шага
    for (int i = 0; i < MAX_PARTICL; i++) {
        printf(" %3d  | %9.2f | %9.2f | %9.2f | %9.2f | \n", 
               i + 1, 
               galaxy[i].radius, 
               galaxy[i].visible_mass, 
               galaxy[i].dark_mass,
               galaxy[i].velocity);
    }
    printf("-------------------------------------------------------\n");
    save_to_file("output.txt", galaxy);
    return 0;
}