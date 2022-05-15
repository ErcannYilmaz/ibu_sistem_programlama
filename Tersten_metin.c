#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FILE_MODE	(S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main(int argc, char* argv[]){
	if(argc != 3){
		printf("İki adet dosya ismi vermelisiniz.\n");
		exit(-1);
	}
	int fd = open(argv[1], O_RDONLY);
	if(fd < 0){
		printf("1.Dosya acma hatasi.\n");
		exit(-2);
	}
	int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE);
	if(fd2 < 0){
		printf("2.Dosya acma hatasi.\n");
		exit(-3);
	}
	int offset = lseek(fd, 0, SEEK_END) - 1;
	char c;
	while(offset >= 0){
		lseek(fd, offset, SEEK_SET);
		read(fd, &c, 1);
		write(fd2, &c, 1);
		offset--;
	}
	close(fd);
	close(fd2);
	return 0;
}
