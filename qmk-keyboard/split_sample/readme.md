[日本語バージョン](readme_ja.md)もあります。

# split_sample EN

This project is for document purpose, but based on [Helix](https://github.com/MakotoKurauchi/helix/) keyboard.

Currently NOT TESTED for Helix!

Keyboard Maintainer: [shikamiya](https://github.com/shikamiya), [MakotoKurauchi](https://github.com/MakotoKurauchi)  
Hardware Supported: Helix PCB, Pro Micro, OLED using SSD1306 controller and SK6812mini RGB LED  
Hardware Availability: [Helix keyboard kit at Yushakobo](https://yushakobo.jp/shop/helix-keyboard-kit/)

Make example for this keyboard (after setting up your build environment):
     
    cd /path/to/qmk_firmware
    cp -r /path/to/this/directory keyboards/
    make split_sample:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## How to create this project

### copy template by script

run script below:

    cd /path/to/qmk_firmware
    util/new_keyboard.sh

then input keyboard's name and answer some questions (just hit enter if you don't understand it).

you can use alphanumeric letters as keyboard's name, but **can't use hyphen** . It cause build error.

### change settings

#### bootloader setting

default `BOOTLOADER` value in `rules.mk` file is `atmel-dfu`. If you're using pro micro with default caterina bootloader, change it to `caterina`.
