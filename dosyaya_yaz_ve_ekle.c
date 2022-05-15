#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FILE_MODE	(S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main(int argc, char* argv[]){
	if(argc != 2){
		printf("Bir dosya ismi vermelisiniz.");
		exit(-1);
	}
	int n;
	int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE);
	if(fd < 0){
		printf("Dosya acma hatasi\n");
		exit(-2);
	}
	char buf[29] = "Bu dosya yeni olusturuldu.\n";
       	if(n = write(fd, buf, sizeof(buf) - 1) < 0){
		printf("Yazma Hatası.\n");
		exit(-3);
	}
	int a;
	close(fd);
	char buf2[24] = "Dosyanin ikinci satiri.";
	fd = open(argv[1], O_WRONLY | O_APPEND, FILE_MODE);
	write(fd, buf2, sizeof(buf2) - 1);
	close(fd);
	return 0;
}
	
	
