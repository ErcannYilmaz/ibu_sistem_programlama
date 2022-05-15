#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FILE_MODE       (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main(int argc, char* argv[]){
	if(argc != 2){
		printf("Bir adet dosya ismi girmelisiniz.");
		exit(-1);
	}
	int fd1 = open(argv[1], O_RDONLY);
	int fd2 = open("Upper.txt", O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE);
	if(fd1 < 0){
		printf("Dosya acma hatasi.\n");
		exit(-2);
	}
	if(fd2 < 0){
		printf("Dosya acma hatasi.\n");
		exit(-3);
	}
	char buf;
	int n = 1;
	while(n != 0){
		n = read(fd1, &buf, 1);
		buf = toupper(buf);
		write(fd2, &buf, 1);
	}
	close(fd1);
	close(fd2);
	return 0;
}
