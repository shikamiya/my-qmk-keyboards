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

you can use alphanumeric letters as keyboard's name, but **can't use hyphen** . It causes build error.

### change settings

this project contains working firmware settings, and you can follow this instruction to build your own project like this.

#### bootloader setting

default `BOOTLOADER` value in `rules.mk` file is `atmel-dfu`. If you're using pro micro with default caterina bootloader, change it to `caterina`.

#### split keyboard setting

if you use split feature, add `SPLIT_KEYBOARD = yes` to `rules.mk` file. then you need to choose following 2 connection type and modify config for it. default is software serial.

Note: currently this project's code is using 3-wired soft serial with `D2` pin.

##### Option1: software serial(3-wired, use normal TRS AUX audio cable)

choose one signal pin in `D0`, `D1`, `D2`, `D3` or `E6`. default is `D0`, so you need to change `#define SOFT_SERIAL_PIN D0` in `config.h` to your selected value.

##### Option2: I2C(4-wired, use TRRS cable or USB OTG cable)

you need to add `#define USE_I2C` to `config.h` file.

default I2C pin of pro micro is `D0` for clock and `D1` for data.

you need 2 resistor to pull up these 2 signal pins. (according to Let's split, resistance value is about 4.7kOhm)

if you use split feature with OLED, you may need to use software serial for split. (TODO: test it)

#### RGB LED settings

if you use RGB LED like SK6812mini, modify `RGBLIGHT_ENABLE` in `rules.mk` to `yes`.

default LED data pin is `E2`, but Pro Micro doesn't provide this pin. this project's code is using `D3` pin.

you need to uncomment `#define RGB_DI_PIN` (remove `//` at the start of the line) and modify this value to your selected value.

and you also need to uncomment `#define RGBLED_NUM` and modify this value to the number of LEDs connected to your keyboard.

then you can configulate some more features described in [RGB Lightning docs of QMK](https://beta.docs.qmk.fm/features/feature_rgblight).

for example, if you use lightning both hands for split keyboard, add `#define RGBLED_SPLIT { (LEFT), (RIGHT) }` and modify the number of LEDs connected to each hands. (TODO: test it)

#### OLED setting

if you use OLED, add `OLED_DRIVER_ENABLE = yes` in `rules.mk`.

default resolution is `128x32`. if you use `128x64` display, add `#define OLED_DISPLAY_128X64` in `config.h`.

then add `oled_task_user()` function to `keymap.c` file. in the function, you can use API function like `oled_write_P()` to show something in OLED. more API is described in  [OLED Driver docs of QMK](https://beta.docs.qmk.fm/features/feature_oled_driver).

you can also configulate some more features described in the docs above.

for example, you can use different font file to show some more logos.

#### reduce firmware size by disabling some features

maybe you're suffering too large firmware size. disable some unused feature to reduce firmware size.

for example:

##### Option: remove LOCKING support

this feature is only used by mechanical locking feature for Num lock, Caps lock and Scroll lock.

as far as you use normal key switch, you don't need this feature. remove or comment out `#define LOCKING_SUPPORT_ENABLE` and `#define LOCKING_RESYNC_ENABLE` from `config.h`.

disabling this feature makes about 200 bytes free space.

##### Option: disable mouse keys

change `MOUSEKEY_ENABLE` value in `rules.mk` to `no`.

disabling this feature makes about 3000 bytes free space.
