// Name: Wacom Loader
// Author: Ricky Cheung <rcheung844@gmail.com>

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// Loader configuration
#define KERNEL_MODULE_NAME "wacom"
#define KERNEL_MODULE_LOADER "modprobe"
#define KERNEL_MODULE_UNLOADER "rmmod"

// Notification configuration
#define NOTIFICATION_ENABLED true
#define NOTIFICATION_EXPIRE_MS 1000

int main()
{
    int ret = 0;

    FILE *fd = popen("lsmod | grep wacom", "r");
    char buf[127];
    bool module_loaded = fread(buf, 1, sizeof (buf), fd) > 0;

    // Store a copy of uid for restoring later
    int uid = getuid();

    // Raise user privileges to root and execute loader/unloader
    setuid(0);
    snprintf(buf, sizeof(buf), "%s %s",
             module_loaded ? KERNEL_MODULE_UNLOADER : KERNEL_MODULE_LOADER, KERNEL_MODULE_NAME);
    ret = system(buf);

    if (ret == -1) {
        printf("Failed to load/unload kernel module %s\n", KERNEL_MODULE_NAME);
        return ret;
    }

    // Restore original uid to drop user privileges
    setuid(uid);

    // Show results
    printf("Kernel module \"%s\" is %s\n", KERNEL_MODULE_NAME, module_loaded ? "UNLOADED" : "LOADED");
    if (NOTIFICATION_ENABLED) {
        snprintf(buf, sizeof(buf), "notify-send --app-name=\"Wacom Loader\" --expire-time=%u %s",
                 NOTIFICATION_EXPIRE_MS, module_loaded ? "Unloaded!" : "Loaded!");
        system(buf);
    }

    return ret;
}
