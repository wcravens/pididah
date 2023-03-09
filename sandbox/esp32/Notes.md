[Getting Started with ESP-IDF](https://idf.espressif.com/)

[Get Started with esp32s3](https://docs.espressif.com/projects/esp-idf/en/stable/esp32s3/get-started/index.html)

[ESP32-S3-DevKitC-1 v1.1](https://docs.espressif.com/projects/esp-idf/en/stable/esp32s3/hw-reference/esp32s3/user-guide-devkitc-1.html)

```
ESP_INTR_FLAG... definitions
components/esp_hw_support/include/esp_intr_alloc.h
```

```sh
  mkdir -p ~/Repos/esp
  cd ~/Repos/esp
  git clone -b v5.0.1 --recursive https://github.com/espressif/esp-idf.git
```

```sh
  cd esp-idf
  ./install.sh esp32s3
```

```sh
alias idfgo='. $HOME/Repos/esp/esp-idf/export.sh' >> ~/.zprofile
source .zprofile
idfgo
```
