<h1 align="center"> Qt Chess Engine </h1>

[![Deploy static content to Pages](https://github.com/halaway/Qt-Chess-Engine/actions/workflows/static.yml/badge.svg?branch=main)](https://github.com/halaway/Qt-Chess-Engine/actions/workflows/static.yml)

> A Qt6.5 program for developing native and browser-based GUI applications,
  built with CMake, Qt Creator, and Emscripten, featuring a fully interactive Chess engine. 

## Description
As a final build, this project focuses again on the Qt Framework and creates a cross-platform graphical user interface for playing a game of Chess. 
Qt handles widget customization, piece renderings, and event handling while the Board class manages positional logic, game rules, and piece interactions.

As before, this project makes use of WebAssembly, a binary instruction format, capable of running alongside Javascript inside a 
virtual environment such as a web browser. Emscripten will again be used to compile the C++ application into WebAssembly (WASM) and JavaScript (js) files 
and finally deployed to be used across the web.



## Getting Started

### Dependencies

* Qt 5/6 
* CMake 
* Launch Qt VSCode Extension 
* GCC (Linux/macOS) – C++ compiler (install via ```apt``` or ```brew```)
* Clang (macOS/Linux) – C++ Compiler (x86/x64)
* Xcode Command Line Tools - Required for macOs
* Emscripten – Compiling C++/C projects to WebAssembly

## Building

### VSCode macOs

Running on mac using VSCode requires the Launch Qt Extension along with CMake. 
Using WebAssembly for browser compilation requires setting system Path for Emscripten: ```source "$HOME/emsdk/emsdk_env.sh" ```

To Run: 

```
- cd build
- cmake .. 
- cmake —build .
- open Project.app
```
### Qt Creator 
Using the Qt IDE:
```
- Run cmake
- Run
```

To run the application on a web browser using Qt Creator, ensure that compatible versions of Emscripten and WebAssembly are installed. Then 
set the Devices' Emscripten SDK path ```/users/path/to/emsdk/``` 
and Build using the WebAssembly Qt Kit.


## Native Desktop GUI Build
<img width="600" alt="Screen Shot 2024-09-13 at 3 11 16 PM" src="https://github.com/user-attachments/assets/d99e3052-e8e7-4479-871c-7a28a058ca4b">

## WebAssembly Based Browser Build 
<img width="600" alt="chess_gui" src="https://github.com/user-attachments/assets/1f73b86c-684b-49f2-92ac-6db84b7a9c89">


