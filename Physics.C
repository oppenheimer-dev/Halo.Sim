#include "const.h"
#include <math.h>


float calculate_orbital_velocity(struct GalaxyShell *full_part,const float G_const){
    if (full_part == NULL) {
        return 0.0f;
    }
    if ((full_part -> rad <= 0.0f) || (full_part -> big_mass <= 0.0f)) {
        return 0.0f;
    }else{
        full_part -> velocity = sqrtf((G_const * full_part ->big_mass)/full_part -> rad);//Расчет скорости стабильности
        return full_part -> velocity;
    }
}

void kepler_function(struct GalaxyShell *shell, const float G_const) {
    calculate_orbital_velocity(shell, G_const);
}

void cumulative_sum(struct GalaxyShell *full_part,const float G_const,const float base_mass,int count){
    float current_cumulative_mass = 0.0f;
    for(int i = 0;i<count;i++){
        full_part[i].rad = (float)(i + 1) * 1.0f;//Радиус оболочки с шагом
        full_part[i].shell_mass = base_mass / (1.0f + 0.1f * (float)i);//конкретный слой

        if(i == 0){
            full_part[i].big_mass = full_part[i].shell_mass;
        }else{
            full_part[i].big_mass = full_part[i - 1].big_mass + full_part[i].shell_mass;
        }
        kepler_function(&full_part[i], G_const);
    }
}