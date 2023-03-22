# PositionBasedFluids
[![Ubuntu Build](https://github.com/BFU-Graphics/PositionBasedFluids/actions/workflows/ubuntu.yml/badge.svg)](https://github.com/BFU-Graphics/PositionBasedFluids/actions/workflows/ubuntu.yml)
[![macOS Build](https://github.com/BFU-Graphics/PositionBasedFluids/actions/workflows/macos.yml/badge.svg)](https://github.com/BFU-Graphics/PositionBasedFluids/actions/workflows/macos.yml)
[![Windows Build](https://github.com/BFU-Graphics/PositionBasedFluids/actions/workflows/windows.yml/badge.svg)](https://github.com/BFU-Graphics/PositionBasedFluids/actions/workflows/windows.yml)

Miles Macklin and Matthias Müller. 2013. Position based fluids. ACM Trans. Graph. 32, 4, Article 104 (July 2013), 12 pages.

## Build Intruction
First **<u>recursively</u>** clone this repo and all submodules.

```shell
git clone --recursive https://github.com/BFU-Graphics/PositionBasedFluids.git
cd PositionBasedFluids
```

For all platform (MacOS, Ubuntu, Windows)

```shell
cmake -S . -B Build
cmake --build Build --config Release
```