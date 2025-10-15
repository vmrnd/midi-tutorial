# MIDI Tutorial

https://learn.sparkfun.com/tutorials/midi-tutorial/all

## Submodules

```zsh
git submodule update --init --recursive
```

## Prerequisites

```zsh
brew tap ArmMbed/homebrew-formulae
brew install --cask gcc-arm-embedded
brew install cmake
brew install ninja
brew install picotool
```

## Clean

```zsh
rm -rf build
```

## Configure and Build

Sample CMakePresets.json

```json
{
  "version": 3,
  "cmakeMinimumRequired": {
    "major": 3,
    "minor": 13,
    "patch": 0
  },
  "configurePresets": [
    {
      "name": "debug",
      "hidden": false,
      "generator": "Ninja",
      "binaryDir": "${sourceDir}/build",
      "description": "Debug build for RP2040",
      "cacheVariables": {
        "PICO_PLATFORM": "rp2040",
        "PICO_BOARD": "pico",
        "CMAKE_BUILD_TYPE": "Debug",
        "CMAKE_EXPORT_COMPILE_COMMANDS": "TRUE",
        "CMAKE_C_COMPILER": "/opt/homebrew/bin/arm-none-eabi-gcc",
        "CMAKE_CXX_COMPILER": "/opt/homebrew/bin/arm-none-eabi-g++"
      }
    }
  ],
  "buildPresets": [
    {
      "name": "debug",
      "description": "Build main target",
      "displayName": "Build",
      "configurePreset": "debug",
      "configuration": "Debug",
      "targets": ["main"]
    }
  ]
}
```

```zsh
cmake --preset debug
cmake --build --preset debug
```

## Flash

```zsh
picotool load build/apps/main.uf2
```

## Python and FluidSynth

Create and activate a virtual environment:

```zsh
pip install -r requirements.txt
python scripts/script.py
```

## Simulator

Edit wokwi.toml and diagram.json to match your project structure.

In VSCode, open Command Palette with
Command+Shift+P -> "Wokwi: Start Simulator"
