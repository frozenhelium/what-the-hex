# what-the-hex

Desktop color picker using Xlib.

## Dependencies

* X11
* xsel

Install xsel:

```bash
$ sudo apt-get install xsel
```

## Build and install

Build the application using following command:

```bash
$ make
```

The application is built into the *bin* directory. You can install it to run globally using following command:

```bash
$ sudo make install
```

## Run

Once installed, you can the run the application with following command:

```bash
$ what-the-hex
```

Click anywhere on screen to pick a color. The hex value will be copied to the clipboard.
