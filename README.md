# Lynton

[![Build Linux](https://github.com/christopher-besch/lynton/workflows/Build%20Linux/badge.svg)](https://github.com/christopher-besch/lynton/actions/workflows/build_linux.yml)
[![Build WASM](https://github.com/christopher-besch/lynton/workflows/Build%20WASM/badge.svg)](https://github.com/christopher-besch/lynton/actions/workflows/build_wasm.yml)
[![License](https://img.shields.io/badge/license-MIT-yellow)](https://github.com/christopher-besch/lynton/blob/main/LICENSE)

Lynton is a simple 2D game engine running natively on Linux and on the web using WASM.
Windows support is in the pipeline.

This repository consists of two build targets: `lynton` (the engine) and `sandbox` (an example "game" using Lynton)

You can compile this repository using cmake.

## Deployed Web Versions

- [Sandbox](https://christopher-besch.github.io/lynton/sandbox/sandbox.html)
- [Physics Words](https://christopher-besch.github.io/lynton/physics_words/physics_words.html)

## Dependencies (Debian)

`sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev`

## Dependencies (Red Hat)

`sudo dnf install SDL2-devel SDL2_image-devel SDL2_ttf-devel`

## Prepare Debug Build

```
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
```
