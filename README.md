# ASEAI_PI
UV ASEAI à l'IMT NORD EUROPE

## Motor control
- **GPIO** : motor is turning or not
- **PWM** : pulse width modulation (`sys/class/pwm`)

## Compiler avec CMake
mkdir build && cd build
cmake ..
cmake --build .
sudo ./ASEAI_PI

## Signaux

List of the known signals : `kill -L`

## PWM

Dans `/boot/config.txt`, ajouter : `dtoverlay=pwm,pin=12,func=0`.
Puis faire `echo 0 > /sys/class/pwm/pwmchip0`.
Et un dossier `/sys/class/pwm/pwmchip0/pwm0` apparaît !
Puis echo dans `enable`, `period` et `duty_cycle`

Remarque : on peut exporte 0 et 1 avec ce modèle de PI. Ces numéros sont fixes.

Overlays data :
- PWM0 : GPIO 12, func 4
- PWM0 : GPIO 18, func 2
- PWM1 : GPIO 13 func 4
- PWM1 : GPIO 19, func 2
Attention, appremment : `dtoverlay=pwm-2chan,pin=12,func=4,pin2=13,func2=4`

## Camera

### Installation
- In "Preferences", check that **SPI** is enable.
- `libcamera-hello`

## Install picamera
```
sudo apt install -y python3-libcamera python3-kms++ libcap-dev
sudo apt install -y python3-opencv python3-picamera2
```

## Branchements
PIN pour PWM = 32 sur le bornier
PIN pour GPIO = 18 sur le bornier

Lancer le programme : cd ./python, puis ./camera.py
Pour compiler : cd ./build, cmake .., puis cmake --build .

## Infos sur l'OS
Linux raspberrypi 6.6.51+rpt-rpi-v8 #1 SMP PREEMPT Debian 1:6.6.51-1+rpt3 (2024-10-08) aarch64 GNU/Linux

## Librairies Python
Package                            Version
---------------------------------- ----------
arandr                             0.1.11
asgiref                            3.6.0
astroid                            2.14.2
asttokens                          2.2.1
attrs                              22.2.0
av                                 10.0.0
Babel                              2.10.3
beautifulsoup4                     4.11.2
blinker                            1.5
certifi                            2022.9.24
chardet                            5.1.0
charset-normalizer                 3.0.1
click                              8.1.3
colorama                           0.4.6
colorzero                          2.0
cryptography                       38.0.4
cupshelpers                        1.0
dbus-python                        1.3.2
dill                               0.3.6
distro                             1.8.0
docutils                           0.19
Flask                              2.2.2
git-cola                           3.12.0
gpiozero                           2.0.1
html5lib                           1.1
idna                               3.3
importlib-metadata                 4.12.0
isort                              5.6.4
itsdangerous                       2.1.2
jedi                               0.18.2
Jinja2                             3.1.2
jsonpointer                        2.3
jsonschema                         4.10.3
lazy-object-proxy                  1.9.0
lgpio                              0.2.2.0
libarchive-c                       2.9
libevdev                           0.5
logilab-common                     1.9.8
lxml                               4.9.2
MarkupSafe                         2.1.2
mccabe                             0.7.0
meson                              1.0.1
more-itertools                     8.10.0
mypy                               1.0.1
mypy-extensions                    0.4.3
numpy                              1.24.2
oauthlib                           3.2.2
olefile                            0.46
packaging                          23.0
parso                              0.8.3
pexpect                            4.8.0
pgzero                             1.2
picamera2                          0.3.22
pidng                              4.0.9
piexif                             1.1.3
pigpio                             1.78
Pillow                             9.4.0
pip                                23.0.1
platformdirs                       2.6.0
psutil                             5.9.4
ptyprocess                         0.7.0
pycairo                            1.20.1
pycryptodomex                      3.11.0
pycups                             2.0.1
pygame                             2.1.2
Pygments                           2.14.0
PyGObject                          3.42.2
pyinotify                          0.9.6
PyJWT                              2.6.0
pylint                             2.16.2
PyOpenGL                           3.1.6
pyOpenSSL                          23.0.0
PyQt5                              5.15.9
PyQt5-sip                          12.11.1
PyQtWebEngine                      5.15.6
pyrsistent                         0.18.1
pyserial                           3.5
pysmbc                             1.0.23
python-apt                         2.6.0
python-dotenv                      0.21.0
python-prctl                       1.8.1
pytz                               2022.7.1
pyudev                             0.24.0
QtPy                               2.3.0
reportlab                          3.6.12
requests                           2.28.1
requests-oauthlib                  1.3.0
responses                          0.18.0
rfc3987                            1.3.8
roman                              3.3
RPi.GPIO                           0.7.1a4
RTIMULib                           7.2.1
Send2Trash                         1.8.1b0
sense-hat                          2.6.0
setuptools                         66.1.1
simplejpeg                         1.6.6
simplejson                         3.18.3
six                                1.16.0
smbus2                             0.4.2
soupsieve                          2.3.2
spidev                             3.5
ssh-import-id                      5.10
thonny                             4.1.4
toml                               0.10.2
tomlkit                            0.11.7
tqdm                               4.64.1
twython                            3.8.2
types-aiofiles                     22.1
types-annoy                        1.17
types-appdirs                      1.4
types-aws-xray-sdk                 2.10
types-babel                        2.11
types-backports.ssl-match-hostname 3.7
types-beautifulsoup4               4.11
types-bleach                       5.0
types-boto                         2.49
types-braintree                    4.17
types-cachetools                   5.2
types-caldav                       0.10
types-certifi                      2021.10.8
types-cffi                         1.15
types-chardet                      5.0
types-chevron                      0.14
types-click-spinner                0.1
types-colorama                     0.4
types-commonmark                   0.9
types-console-menu                 0.7
types-contextvars                  2.4
types-croniter                     1.3
types-cryptography                 3.3
types-D3DShot                      0.1
types-dateparser                   1.1
types-DateTimeRange                1.2
types-decorator                    5.1
types-Deprecated                   1.2
types-dj-database-url              1.0
types-docopt                       0.6
types-docutils                     0.19
types-editdistance                 0.6
types-emoji                        2.1
types-entrypoints                  0.4
types-first                        2.0
types-flake8-2020                  1.7
types-flake8-bugbear               22.10.27
types-flake8-builtins              2.0
types-flake8-docstrings            1.6
types-flake8-plugin-utils          1.3
types-flake8-rst-docstrings        0.2
types-flake8-simplify              0.19
types-flake8-typing-imports        1.14
types-Flask-Cors                   3.0
types-Flask-SQLAlchemy             2.5
types-fpdf2                        2.5
types-gdb                          12.1
types-google-cloud-ndb             1.11
types-hdbcli                       2.14
types-html5lib                     1.1
types-httplib2                     0.21
types-humanfriendly                10.0
types-invoke                       1.7
types-JACK-Client                  0.5
types-jmespath                     1.0
types-jsonschema                   4.17
types-keyboard                     0.13
types-ldap3                        2.9
types-Markdown                     3.4
types-mock                         4.0
types-mypy-extensions              0.4
types-mysqlclient                  2.1
types-oauthlib                     3.2
types-openpyxl                     3.0
types-opentracing                  2.4
types-paho-mqtt                    1.6
types-paramiko                     2.11
types-parsimonious                 0.10
types-passlib                      1.7
types-passpy                       1.0
types-peewee                       3.15
types-pep8-naming                  0.13
types-Pillow                       9.3
types-playsound                    1.3
types-polib                        1.1
types-prettytable                  3.4
types-protobuf                     3.20
types-psutil                       5.9
types-psycopg2                     2.9
types-pyaudio                      0.2
types-PyAutoGUI                    0.9
types-pycurl                       7.45
types-pyfarmhash                   0.3
types-pyflakes                     2.5
types-Pygments                     2.13
types-pyinstaller                  5.6
types-PyMySQL                      1.0
types-pynput                       1.7
types-pyOpenSSL                    22.1
types-pyRFC3339                    1.1
types-PyScreeze                    0.1
types-pysftp                       0.2
types-pytest-lazy-fixture          0.6
types-python-crontab               2.6
types-python-dateutil              2.8
types-python-gflags                3.1
types-python-jose                  3.3
types-python-nmap                  0.7
types-python-slugify               6.1
types-pytz                         2022.6
types-pyvmomi                      7.0
types-pywin32                      304
types-PyYAML                       6.0
types-redis                        4.3
types-regex                        2022.10.31
types-requests                     2.28
types-retry                        0.9
types-Send2Trash                   1.8
types-setuptools                   65.5
types-simplejson                   3.17
types-singledispatch               3.7
types-six                          1.16
types-slumber                      0.7
types-SQLAlchemy                   1.4.43
types-stdlib-list                  0.8
types-stripe                       3.5
types-tabulate                     0.9
types-termcolor                    1.1
types-toml                         0.10
types-toposort                     1.7
types-tqdm                         4.64
types-tree-sitter                  0.20
types-tree-sitter-languages        1.5
types-ttkthemes                    3.2
types-typed-ast                    1.5
types-tzlocal                      4.2
types-ujson                        5.5
types-urllib3                      1.26
types-vobject                      0.9
types-waitress                     2.1
types-whatthepatch                 1.0
types-xmltodict                    0.13
types-xxhash                       3.0
types-zxcvbn                       4.4
typing_extensions                  4.4.0
uritemplate                        4.1.1
urllib3                            1.26.12
v4l2-python3                       0.3.5
webcolors                          1.11.1
webencodings                       0.5.1
Werkzeug                           2.2.2
wheel                              0.38.4
wrapt                              1.14.1
zipp                               1.0.0

## Version de cmake
cmake version 3.25.1
