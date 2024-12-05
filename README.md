# CSE350 Group 11 Calculator Project

## Table of Contents
- [Description](#description)
- [Build](#build)
- [Built With](#built-with)
- [License](#license)

## Description
An multi-function calculator with several modules for different kinds of computations.

The 5 main modules are:
- Standard calculator
- Unit converter
- Quadratic equation plotter
- Quadratic simplifier and inequality solver
- Population statistics calculator

![program screenshot](screenshot.png)

## Build
#### Linux:
1. Install g++ and wxWidgets\
Arch Linux: ```pacman -S gcc wxwidgets-gtk3```
2. Clone the repository
```
git clone https://github.com/bdwark/Calculator-Project.git 
cd Calculator-Project
```
3. Compile with GCC
```
g++ -o calculator BaseCalculator/*.cpp ConversionsCode/*.cpp GraphingFunction/*.cpp StatisticsCode/*.cpp UICode/*.cpp `wx-config --cxxflags --libs
```
#### Windows:
1. Install cmake
2. Install wxWidgets
I recommend installing [wxWidgets via vcpkg](https://docs.wxwidgets.org/latest/plat_msw_install.html)
3. Clone the cmake branch of the repostiory
4. Open up a bash terminal in UIcode and running
```
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=<vcpkg-path>/scripts/buildsystems/vcpkg.cmake
cmake --build build
```
You should get the -DCMAKE_TOOLCHAIN_FILE=<vcpkg-path>/scripts/buildsystems/vcpkg.cmake path from when you ran
```vcpkg integrate install```
## Built with
[wxWidgets](https://wxwidgets.org/) - Cross-platform GUI library

## License
[LGPL](https://www.gnu.org/licenses/lgpl-3.0.txt)

## Group Members
Sam Smallwood, Eve Warkentine, Quinlan Toole, Lauren Rose, Elijah Marshall
