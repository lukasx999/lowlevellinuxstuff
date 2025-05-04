#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <fcntl.h>

// #include <xf86drm.h>
// #include <xf86drmMode.h>

int main(void) {

    int err = execlp("/busybox", "busybox", "ls");
    perror("ERROR");
    assert(err != -1);

    // int fd = open("/dev/dri/card1", O_RDWR | O_CLOEXEC);
    // assert(fd != -1);

    while (1);

    return 0;
}
