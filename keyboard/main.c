#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <sys/time.h>

/*
 * This is another project that i am doing as a stress relief, from daily react/js work.
 * 
 * This little project is to understand how i interact with devices and hardware events,
 * It's also to understand how Linux handels keyboard input at a decent low level.
 * I'm way to dumb to write C on a baselevel as of now.
 * But i am getting knowledge on Hands-on experience with file descriptors (open(), read(), close()),
 * and handling binary data and structures directly.
 *
 *
 * Typically in Linux and in this case 'Keyboard', but any input devices are handled via Special files located in,
 * /dev/input/
 * The kernel sends keyboard and mouse input tt these special files.
 * So first we have to indentify the our input device, and one way is by: cat /proc/bus/input/devices or ls -l /dev/input/by-path,
 * (Look for kbd if you want to test your keyboard.)
 *
 * On some keyboards you might have different events as,
 * TKL Nkeys System Control,
 * TKL Nkeys Keyboard,
 * TKL Nkeys Consumer Control &
 * TKL Nkeys
 *
 * More correct way of describing this is,
 * Standard typing keys(in my case, event3) &
 * Media controll keys(event5, event6)(FN + F11 for raising volume as example).
 * 
 * 
 * If you have alot of devices connected you can filter it out by 
 * cat /proc/bus/input/devices | grep -i <name>.
 *
*/





/*
* Allocate keycodes in global memory, 
* which remains allocated for the entire time runtime of the program.
*
* Point to a constant string literal stored in read-only memory (static memory), 
* pointed to by a pointer stored on the stack.
*
* Honestly i cba documenting more for now, i will continue as i continue on this project.
* My right wrist hurts. :,(
*
*/

const char *keycodes[] = {
    "", "<ESC>", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0",
    "-", "=", "<Backspace>", "<Tab>",
    "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "[", "]",
    "\n", "<Ctrl>", "a", "s", "d", "f", "g", "h", "j", "k", "l",
    ";", "'", "`", "<Shift>", "\\", "z", "x", "c", "v", "b", "n",
    "m", ",", ".", "/", "<Shift>", "*", "<Alt>", " ", "<CapsLock>"
};

int main() {

    const char *device = "/dev/input/event3";
    struct input_event ev;

    int fd = open(device, O_RDONLY);
    if (fd == -1) {
        perror("Cannot open device");
        return 1;
    }

    printf("Ready for use...\n");
    
    while (1) {
        ssize_t n = read(fd, &ev, sizeof(struct input_event));
        if (n == (ssize_t)-1) {
            perror("Read error");
            break;
        }

        if (ev.type == EV_KEY && ev.value == 1) { // Key pressed

            // Get current time clearly
            struct timeval current_time;
            gettimeofday(&current_time, NULL);

            // Calculate response time in microseconds clearly
            long response_sec = current_time.tv_sec - ev.time.tv_sec;
            long response_usec = current_time.tv_usec - ev.time.tv_usec;
            double response_time = response_sec * 1000.0 + response_usec / 1000.0; // milliseconds clearly

            if (ev.code < sizeof(keycodes)/sizeof(keycodes[0])) {
                printf("Key pressed: %s (%d) | Response time: %.3f ms\n",
                       keycodes[ev.code],
                       ev.code,
                       response_time);
            } else {
                printf("Unknown key pressed: %d | Response time: %.3f ms\n",
                       ev.code,
                       response_time);
            }
        }
    }

    close(fd);
    return 0;
}
