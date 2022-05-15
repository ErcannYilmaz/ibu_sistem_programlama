#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FILE_MODE	(S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main(int argc, char* argv[]){
	if(argc != 2){
		printf("Bir ader dosya ismi girmelisiniz.");
		exit(-1);
	}
	int fd = open(argv[1], O_RDONLY);
	if(fd < 0){
		printf("Dosya acma hatasi.\n");
		exit(-2);
	}
	int fd2 = open("doubled.txt", O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE);
	if(fd2 < 0){
		printf("Dosya acma hatasi.\n");
		exit(-3);
	}
	int n = 1;
	char buf;
	while(n != 0){
		n = read(fd, &buf, 1);
		write(fd2, &buf, 1);
	}
	lseek(fd, 0L, 0);
	n = 1;
	while(n != 0){
		n = read(fd, &buf, 1);
		write(fd2, &buf, 1);
	}
	close(fd);
	close(fd2);
	return 0;
}
