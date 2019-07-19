[English version of this document](readme.md) is available.

# split_sample 日本語

解説用のプロジェクトですが、Helixをベースに作成しています。

現在のところ、実際にテストはできていないのでご了承ください。

qmk_firmware のビルド環境の準備ができたら、以下を実行することでビルドすることができます。

    cd (qmk_firmwareのディレクトリ)
    cp -r (このファイルがあるディレクトリ) keyboards/
    make split_sample:default

## このプロジェクトの作り方

### テンプレートをコピーするスクリプトを実行する

以下のコマンドを実行します。

    cd (qmk_firmwareのディレクトリ)
    util/new_keyboard.sh

実行するとキーボードの名前を聞かれるので入力してください。他にもいくつか質問されますが、分からなければEnterキーを押すだけでいいです。

キーボード名には英数字、アンダーバーを使用できますが、 **ハイフンは使用できません** 。ビルド時にエラーが出るのでハマりやすいです。

### 設定変更

#### bootloader の設定

`rules.mk` ファイル内の `BOOTLOADER` の初期値は `atmel-dfu` になっています。ProMicroをデフォルトのcaterinaブートローダーで使用する場合は `caterina` に変更してください。
