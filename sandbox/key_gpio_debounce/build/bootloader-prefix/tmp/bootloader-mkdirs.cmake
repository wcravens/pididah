# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/wcravens/Repos/esp/esp-idf/components/bootloader/subproject"
  "/Users/wcravens/Repos/pididah/sandbox/key_gpio_debounce/build/bootloader"
  "/Users/wcravens/Repos/pididah/sandbox/key_gpio_debounce/build/bootloader-prefix"
  "/Users/wcravens/Repos/pididah/sandbox/key_gpio_debounce/build/bootloader-prefix/tmp"
  "/Users/wcravens/Repos/pididah/sandbox/key_gpio_debounce/build/bootloader-prefix/src/bootloader-stamp"
  "/Users/wcravens/Repos/pididah/sandbox/key_gpio_debounce/build/bootloader-prefix/src"
  "/Users/wcravens/Repos/pididah/sandbox/key_gpio_debounce/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/wcravens/Repos/pididah/sandbox/key_gpio_debounce/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/wcravens/Repos/pididah/sandbox/key_gpio_debounce/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
