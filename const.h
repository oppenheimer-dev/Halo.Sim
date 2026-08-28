#ifndef CONST_H
#define CONST_H

#define MAX_PARTICL 10
#define G_CONST 0.0001f
#define TIME_STEP 0.01f
#define BASE_MASS 10.0f

struct GalaxyShell {
    float velocity;
    float mass;
    float radius;
    float visible_mass;
    float shell_mass; 
    
    float real_velocity;
    float total_mass;
    float dark_mass;
};



#endif