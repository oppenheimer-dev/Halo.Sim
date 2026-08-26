#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 // Гравитационная постоянная
#define DT 3600.0     // Шаг по времени в секундах (1 час)
#define STEPS 1000    // Количество шагов симуляции
#define N 3           // Количество тел

typedef struct {
    double x, y;    // Координаты (метры)
    double vx, vy;  // Скорости (м/с)
    double mass;    // Масса (кг)
} Body;