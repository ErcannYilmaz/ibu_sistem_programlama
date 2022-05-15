#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
	if(argc != 3){
		printf("Sirasiyla bir dosya ve bir harf vermelisiniz.\n");
		exit(-1);
	}
	int fd = open(argv[1], O_RDONLY);
	if(fd < 0){
		printf("Dosya acma hatasi.\n");
		exit(-2);
	}
	int n = 1;
	char buf;
	int yeniKelime = 1;
	int count = 0;
	while(n != 0){
		n = read(fd, &buf, 1);
		if(buf == argv[2][0]){
			if(yeniKelime == 1){
				count++;
				yeniKelime = 0;
			}
		}
		if(buf == ' '){
			yeniKelime = 1;
		}
	}
	close(fd);
	printf("%d\n", count);
	return 0;
}
