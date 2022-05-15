#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
        if(argc != 2){
                printf("Bir dosya ismi vermelisiniz.");
                exit(-1);
        }
	int fd = open(argv[1], O_RDONLY);
	if(fd < 0){
		printf("Dosya acma hatasi.");
		exit(-2);
	}
	int n = 1;
	int count = 0;
	char buf;
	while(n != 0){
		n = read(fd, &buf, 1);
		if(buf == ' '){
			count++;
		}
	}
	count++;
	printf("%d\n", count);
}

