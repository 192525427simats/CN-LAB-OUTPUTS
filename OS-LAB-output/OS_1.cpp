#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() 
{
    int s, dest;
    char buffer[1024];
    int bytes;

    s = open("source.txt", O_RDONLY);
    dest = open("dest.txt", O_WRONLY | O_CREAT, 0644);

    while ((bytes = read(s, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, bytes);
    }

    close(s);
    close(dest);

    printf("File copied successfully\n");
    return 0;
}
