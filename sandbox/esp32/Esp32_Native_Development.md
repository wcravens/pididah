# ESP32 Native Development Tools.

The Arduino ecosystem provides a lot of benefits for getting started and bootstrapping simple projects.  But as a development environment it quickly reveals weaknesses when it comes to automation, alternative IDEs, customized shell environments, etc.  For these reasons, an experienced developer may choose to use the native Espressif tool chain.  The Espressif dev environment is arguably superior to the Arduino in terms of libraries and makeing the most efficient use of your ESP32 microcontroller.

There is an exctensive selection of [ESP32 Devlopment Kits](https://www.espressif.com/en/products/devkits).

Here we are going to start with the Adafruit Feather ESP32-S3 TFT board because that's the one currently on the workbench.

Down the road we may want to explore the [ESP32-S3-DevKitC-1](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/hw-reference/esp32s3/user-guide-devkitc-1.html) when we get out of 'tinkering' mode and start zeroing in on a production board candidate.

## Setting up the Development Environment / Toolchain

[Standard Toolchain Setup for Linux and macOS](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/get-started/linux-macos-setup.html#get-started-linux-macos-first-steps)

## Raspberry Pi 3 B+

```
sudo apt-get update
sudo apt-get install git wget flex bison gperf python3 python3-venv cmake ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0

wcravens@pididah:~/Repos $ python --version
Python 3.9.2

> mkdir ~/Repos/esp
> cd ~/Repos/esp
> git clone --recursive https://github.com/espressif/esp-idf.git
```

Be patient with the clone... the esp-idf repo is over a GByte.

```
> cd esp-idf
> ./install.sh esp32s3
```

This will take some time too.  It's not too bad on a desktop, but on the RPi it takes some time.

ESP-IDF functions by setting up a shell environment.  Source `export.sh` to activate the env settings.

```
> . export.sh

# Add to ~/.bashrc

> alias get-idf='. ~/Repos/esp/esp-idf/export.sh'

> get-idf
```

## [Build System](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/build-system.html)

### Start a New Project

[IDF Frontend](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/tools/idf-py.html)


[**ESP-IDF Programming Guide**](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/)

[**Get Started**](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html)

[**API Reference**](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/index.html)

[**API Guides**](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/index.html)

[**VSCode Esp-IDF Extension**](https://github.com/espressif/vscode-esp-idf-extension/blob/master/docs/tutorial/toc.md)


