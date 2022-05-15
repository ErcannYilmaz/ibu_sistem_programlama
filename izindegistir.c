#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define filemode1 (S_IRUSR | S_IWUSR) 
#define filemode2 (S_IWGRP | S_IROTH)

int main(int argc, char * argv[]){
	if(argc != 2){
		printf("Bir adet dosya ismi vermelisiniz.\n");
		exit(-1);
	}
	int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, filemode1);
	if(fd < 0){
		printf("Dosya acma hatasi.\n");
		exit(-2);
	}
	char buf[] = "Bu dosya sadece Ercan Yilmaz tarafindan okunabilir.\n";
	write(fd, buf, sizeof(buf) - 1);
	close(fd);
	fd = open(argv[1], O_WRONLY | O_APPEND);
	fchmod(fd, filemode1 | filemode2);
	if(fd < 0){
		printf("Dosya acma hatasi.\n");
		exit(-3);
	}
	char buf2[] = "Dosyanın izinleri değişti artık grup arkadaşlarım da yazabiliyor.\n";
	write(fd, buf2, sizeof(buf2) - 1);
	close(fd);
	return 0;
}
