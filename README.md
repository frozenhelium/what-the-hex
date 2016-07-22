# what-the-hex
Desktop color picker using Xlib

## Dependency
* X11
* xclip

Install xclip
```bash
$ sudo apt-get install xclip
```

## Build
Create a bin directory first inside project directory
```bash
$ mkdir bin
```
Now, build with `g++` as
```bash
$ g++ main.cpp -o bin/what-the-hex -lX11
```

## Run
Run with program with following command
```bash
$ ./bin/what-the-hex
```
Click on screen to pick the color. The hex value will be copied to the clipboard.
