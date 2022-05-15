#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FILE_MODE	(S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main(int argc, char* argv[]){
	if(argc != 2){
		printf("Bir dosya ismi vermelisiniz.");
		exit(-1);
	}
	int fd1 = open("metin_sesli_harfsiz.txt", O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE);
	if(fd1 < 0){
		printf("Dosya acma hatasi\n");
		exit(-2);
	}
	int fd2 = open(argv[1], O_RDONLY);
	if(fd2 < 0){
		printf("Dosya acma hatasi\n");
		exit(-2);
	}
	char buf;
	int n = 1;
	while(n != 0){
		n = read(fd2, &buf, 1);
		if(buf != 'a' && buf != 'e' && buf != 'i' && buf != 'o' && buf != 'u' && buf != 'A' && buf != 'E' && buf != 'I' && buf != 'O' && buf != 'U'){
			write(fd1, &buf, 1);
		}
	}
	close(fd2);
	close(fd1);
	return 0;
}
	

