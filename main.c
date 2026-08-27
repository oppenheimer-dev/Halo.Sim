#include <stdio.h>
#include "const.h"

void cumulative_sum(struct GalaxyShell *full_part, const float G_const, const float base_mass, int count);

int main(void) {
    struct GalaxyShell galaxy[MAX_PARTICL];
    
    float base_mass = 100.0f;
    cumulative_sum(galaxy, G_CONST, base_mass, MAX_PARTICL);

    printf("-----------------------------------------\n");
    printf("Version:0.2.1\n");
    printf("-----------------------------------------\n");
    printf(" Step | Radius    | Big Mass  | Velocity  \n");

    // Выводим значения для каждого шага
    for (int i = 0; i < MAX_PARTICL; i++) {
        printf(" %3d  | %9.2f | %9.2f | %9.2f \n", 
               i + 1, 
               galaxy[i].rad, 
               galaxy[i].big_mass, 
               galaxy[i].velocity);
    }
    printf("-----------------------------------------\n");
    return 0;
}