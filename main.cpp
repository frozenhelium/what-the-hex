#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/cursorfont.h>

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>

int main()
{
    Display *display = XOpenDisplay(NULL);
    if (display == NULL)
    {
        return 1;
    }

    Cursor cursor = XCreateFontCursor(display, XC_ul_angle);
    XGrabPointer(display, DefaultRootWindow(display), False,
               ButtonPressMask | ButtonReleaseMask | PointerMotionMask | FocusChangeMask | EnterWindowMask | LeaveWindowMask,
               GrabModeAsync, GrabModeAsync, RootWindow(display, DefaultScreen(display)), cursor, CurrentTime);

    XEvent e;
    while (true)
    {
        XNextEvent(display, &e);
        if(e.type == ButtonPress)
        {
            XImage *screen;
            screen = XGetImage (display, RootWindow(display, DefaultScreen(display)), e.xbutton.x, e.xbutton.y, 1, 1, AllPlanes, XYPixmap);
            XColor color;
            color.pixel = XGetPixel (screen, 0, 0);
            XFree (screen);
            XQueryColor (display, DefaultColormap(display, DefaultScreen (display)), &color);
            std::cout<< std::setfill ('0') << std::setw (2) << std::hex << (255*color.red)/65535
                << std::setfill ('0') << std::setw (2) << std::hex << (255*color.green)/65535
                << std::setfill ('0') << std::setw (2) << std::hex << (255*color.blue)/65535 << std::endl;
            std::stringstream ss;
            ss << "echo \""
                << std::setfill ('0') << std::setw (2) << std::hex << (255*color.red)/65535
                << std::setfill ('0') << std::setw (2) << std::hex << (255*color.green)/65535
                << std::setfill ('0') << std::setw (2) << std::hex << (255*color.blue)/65535 << "\" | xsel -i -b";
            std::string cmd = ss.str();
            system(cmd.c_str());
            break;
        }
    }
    XUngrabPointer(display, CurrentTime);
    XCloseDisplay(display);
    return 0;
}
