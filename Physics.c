#include "const.h"
#include <math.h>
#include <stdio.h>

float calculate_dark_matter(struct GalaxyShell *full_part,const float G_const){
    if (full_part == NULL) {
        return 0.0f;
    }else{
        float dark_layer_mass = 15.0f;

        full_part->dark_mass = dark_layer_mass * full_part->radius;
        full_part->total_mass = full_part->visible_mass + full_part->dark_mass;
        
        return full_part -> dark_mass;

    }
}

float calculate_orbital_velocity(struct GalaxyShell *full_part,const float G_const){
    if (full_part == NULL) {
        return 0.0f;
    }
    if ((full_part -> radius <= 0.0f) || (full_part -> total_mass <= 0.0f)) {
        return 0.0f;
    }else{
        full_part -> velocity = sqrtf((G_const * full_part ->total_mass)/full_part -> radius);//Расчет скорости стабильности
        return full_part -> velocity;
    }
}

void cumulative_sum(struct GalaxyShell *full_part,const float G_const,const float base_mass,int count){
    for(int i = 0;i<count;i++){
        full_part[i].radius = (float)(i + 1) * 1.0f;//Радиус оболочки с шагом
        full_part[i].shell_mass = base_mass / (1.0f + 0.1f * (float)i);//конкретный слой

        if(i == 0){
            full_part[i].visible_mass = full_part[i].shell_mass;
        }else{
            full_part[i].visible_mass = full_part[i - 1].visible_mass + full_part[i].shell_mass;
        }
        calculate_dark_matter(&full_part[i], G_const);
        calculate_orbital_velocity(&full_part[i], G_const);
    }
}