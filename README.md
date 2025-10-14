# Pico Template

## Submodules

```zsh
git submodule add https://github.com/raspberrypi/pico-sdk extern/pico-sdk
git submodule update --init --recursive

git submodule add https://github.com/ThrowTheSwitch/Unity.git extern/unity_cmake/unity
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

## Build

```zsh
cmake --preset debug
cmake --build --preset debug
```

## Flash

```zsh
picotool load build/waveshare-debug/hello_world.uf2
```

## Simulator

Edit wokwi.toml and diagram.json to match your project structure.

In VSCode, open Command Palette with
Command+Shift+P -> "Wokwi: Start Simulator"
