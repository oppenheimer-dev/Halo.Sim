#ifndef CONST_H
#define CONST_H

#define MAX_PARTICL 200
#define G_CONST 0.0001f
#define TIME_STEP 0.01f
#define SCREEN_W
#define SCREEN_H

struct GalaxyShell {
    float x, y;
    float vx, vy;
    float ax, ay;
    float mass;
    float rad;
    float big_mass;       
};



#endif