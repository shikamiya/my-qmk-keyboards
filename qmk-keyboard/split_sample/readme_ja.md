[English version of this document](readme.md) is available.

# split_sample 日本語

解説用のプロジェクトですが、Helixをベースに作成しています。

現在のところ、実際にテストはできていないのでご了承ください。

qmk_firmware のビルド環境の準備ができたら、以下を実行することでビルドすることができます。

    cd (qmk_firmwareのディレクトリ)
    cp -r (このファイルがあるディレクトリ) keyboards/
    make split_sample:default

## このプロジェクトの作り方

このプロジェクトはそのまま動くファームウェアを含んでいますが、以下の手順を追うことで、これに似た別のファームウェアを自分で作ることができます。

### テンプレートをコピーするスクリプトを実行する

以下のコマンドを実行します。

    cd (qmk_firmwareのディレクトリ)
    util/new_keyboard.sh

実行するとキーボードの名前を聞かれるので入力してください。他にもいくつか質問されますが、分からなければEnterキーを押すだけでいいです。

キーボード名には英数字、アンダーバーを使用できますが、 **ハイフンは使用できません** 。ビルド時にエラーが出るのでハマりやすいです。

### 設定変更

#### bootloader の設定

`rules.mk` ファイル内の `BOOTLOADER` の初期値は `atmel-dfu` になっています。ProMicroをデフォルトのcaterinaブートローダーで使用する場合は `caterina` に変更してください。

#### 分割キーボードの設定

分割機能を使用する場合、  `rules.mk` ファイルに `SPLIT_KEYBOARD = yes` を追加して、以下の2つの方式のいずれかを選択して設定してください。 デフォルトは soft serial です。

(現在このプロジェクトは `D2` ピンでの soft serial を使用しています。)

##### 方式1： soft serial(3本線、通常の音楽用AUXケーブルで接続)

`D0`, `D1`, `D2`, `D3`, `E6` ピンの中から通信に使用するピンを選択してください。デフォルトは `D0` です。変更するには `config.h` ファイル内の `#define SOFT_SERIAL_PIN D0` を書き換えてください。

##### 方式2： I2C(4本線、TRRSケーブル・USB OTGケーブルなどで接続)

`config.h` ファイルに `#define USE_I2C` を追加する必要があります。

Pro Micro では `D0` をクロック用ピンに、 `D1` をデータ用ピンに使用します。

I2Cを使用するにはその2本のピンをプルアップする必要があります。Let's split などでは 4.7kOhm 程度の抵抗が使用されています。

OLED を使用する場合は、分割機能には soft serial を使用する必要があるかもしれません。(未検証)

#### LEDの設定

SK6812miniなどのLEDを使用する場合、 `rules.mk` ファイル内の `RGBLIGHT_ENABLE` を `yes` に変更してください。

デフォルトのLED用データピンは `E2` になっていますが、Pro Microではこのピンを使用することはできません。このプロジェクトでは `D3` ピンを使用しています。

`config.h` ファイル内の `#define RGB_DI_PIN` と `#define RGBLED_NUM` をアンコメント(行頭の `//` を削除)して、それぞれ LED用データピン と 接続するLEDの数 に変更してください。

QMKのドキュメント内の[RGB Lightning](https://beta.docs.qmk.fm/features/feature_rgblight)ページに、他にも使用できる設定が書かれています。

例えば、分割キーボードでLEDを使用する場合、 `config.h` ファイル内に `#define RGBLED_SPLIT { (左), (右) }` を追加して、それぞれの基板に接続するLEDの数に変更してください。
