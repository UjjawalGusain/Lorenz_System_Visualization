# Lorenz System Chaos Theory Visualization

This project visualizes the Lorenz attractor, a system of differential equations that exhibit chaotic behavior. The Lorenz system is a simple yet fascinating example of how deterministic systems can exhibit unpredictable and complex behavior.

## Table of Contents
- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [How It Works](#how-it-works)
- [Dependencies](#dependencies)
- [Acknowledgements](#acknowledgements)
- [License](#license)

## Introduction

The Lorenz attractor is a set of chaotic solutions to the Lorenz system, which is a system of ordinary differential equations. This visualization shows the behavior of two sets of initial conditions, displaying their paths in red and blue to illustrate the divergence over time.

## Installation

To run this project, you need to have [SFML](https://www.sfml-dev.org/) installed on your system. Follow the instructions for your specific platform to install SFML.

Clone this repository to your local machine using:
```sh
git clone https://github.com/UjjawalGusain/Lorenz_System_Visualization.git
cd lorenz-visualization
```

## Usage

- Compile the program using your preferred C++ compiler. Ensure you link the SFML libraries.
- Run the compiled executable. The program will start in full-screen mode, displaying the initial title screen.
- Press the Enter key to start the animation.

### Example Compilation Command
Using g++:
```sh
g++ -o lorenz main.cpp -lsfml-graphics -lsfml-window -lsfml-system
```

## How It Works

### The Lorenz system is defined by three differential equations:
  - dx/dt = σ (y - x)
  - dy/dt = x (ρ - z) - y
  - dz/dt = x y - β z
    
  where:
σ (sigma) = 10, 
ρ (rho) = 28,
β (beta) = 8/3

- These equations describe the rate of change of the variables x, y, and z over time.
- The updateLorenz function computes the new state of the system based on these equations.
- The createPixel function maps the 3D coordinates to 2D screen coordinates and sets the corresponding pixel on the screen.
- The main loop handles events, updates the system state, and renders the visualization.

## Dependencies
- SFML (Simple and Fast Multimedia Library)

## Acknowledgements
- SFML for providing an easy-to-use multimedia library.
- The Lorenz system equations and their application in chaos theory.

## License
This project is licensed under the MIT License - see the LICENSE file for details.
