#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>

// #include <xf86drm.h>
// #include <xf86drmMode.h>

int main(void) {


    chmod("/busybox", 0777);


    pid_t pid = fork();
    if (pid == 0) {
        int err = execlp("/busybox", "busybox", "--install", "-s", NULL);
        perror("ERROR");
        assert(err != -1);
    }
    wait(NULL);

    DIR *dirp = opendir("/");
    struct dirent *dir = NULL;
    while ((dir = readdir(dirp)) != NULL) {
        printf("%s\n", dir->d_name);
    }



    // int fd = open("/dev/dri/card1", O_RDWR | O_CLOEXEC);
    // assert(fd != -1);

    while (1);

    return 0;
}
