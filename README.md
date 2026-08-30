
# Galaxy Rotation Model

> Minimalistic C implementation of galactic rotation curves incorporating dark matter approximations.

## Overview
A lightweight, stack-allocated simulation tool written in C designed to model galactic shell masses, orbital velocities, and the gravitational effects of dark matter. Built for educational visualization and scientific communication.

## Architecture
- **`const.h`**: Core data structures (`GalaxyShell`) and physical constants.
- **`physics.c`**: Core mathematical models for cumulative mass and orbital velocity calculations.
- **`main.c`**: Entry point and formatted telemetry output generator.

## Build & Run
```bash
gcc main.c physics.c -o galaxy_sim -lm
./galaxy_sim

```

## Author

oppenheimer-dev
