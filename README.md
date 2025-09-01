# ETISS Accelerator Plugins

This repository contains plugins for modelling ML accelerators in [ETISS](https://github.com/tum-ei-eda/etiss).

## Contents

- `QVanillaAccelerator`: TODO: Description
- `QVanillaAcceleratorT`: TODO: Description
- `VanillaAccelerator`: TODO: Description

## Building Instructions

### Integrated ETISS Build

1. Clone ETISS repository
2. Copy (or symlink) the plugin directory (i.e. `QVanillaAcceleratorT`) into the `PluginImpl` directory of the ETISS source tree.
3. Build ETISS as usual (following the instructions in the README)

### Out-of-Tree Build

1. Clone, build and install ETISS according to the README.
2. Enter one plugin directory, i.e. `cd `
3. Build plugin with CMake, passing it `ETISS_DIR` to find the relevant CMake configuration

```sh
cmake -B ./build -S . -DETISS_DIR=/path/to/etiss/install/lib/CMake/ETISS
cmake --build build -j$(nproc)
```

## Running Instructions

### Integrated ETISS Build

### Out-of-Tree Build

#### Option A (`etiss_wd`)

1. Create a directory: `mkdir ./temp/`
2. Create INI file with following contents:
```ini
# Filename: custom.ini
[StringConfigurations]
etiss_wd=/path/to/temp
```
3. Create `PluginImpl` subdirectory: `mkdir ./temp/PluginImpl`
4. Copy `./build/libQVanillaAcceleratorT.so` (or other plugin) into this subdir: `cp ./build/libQVanillaAcceleratorT.so ./temp/PluginImpl`
5. Run ETISS via `run_helper.sh` script (or calling `bare_etiss_processor` directly)
```sh
/path/to/etiss/install/bin/run_helper.sh /path/to/program -p QVanillaAcceleratorT -icustom.ini
```

**Hint:** Steps 1.-3. can be skipped if executing ETISS in the same path where the `PluginImpl` directory is located. This yields to this more simple procedure:

```sh
mkdir ./PluginImpl
cp ./build/libQVanillaAcceleratorT.so ./PluginImpl
/path/to/etiss/install/bin/run_helper.sh /path/to/program -p QVanillaAcceleratorT
```

#### Option B (`list.txt`)

1. Edit the `list.txt` file located in `/path/to/etiss/install/lib/plugins/`
```sh
echo "QVanillaAcceleratorT,$(pwd)/build/,QVanillaAcceleratorT" >> ../../../install/lib/plugins/list.txt
```
2. Run ETISS: `/path/to/etiss/install/bin/run_helper.sh /path/to/program -p QVanillaAcceleratorT`


**Warning**: These changes will be overwritten, when ETISS is being rebuilt!

## End-to-End Example

A full example on how to use these plugins with TVMs UMA flow is part of the MLonMCU project: https://github.com/tum-ei-eda/mlonmcu/blob/main/ipynb/Examples/TVM-UMA/TVM-UMA.ipynb
