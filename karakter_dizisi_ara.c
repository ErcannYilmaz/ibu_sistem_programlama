#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char* argv[]){
	if(argc != 3){
		printf("Sirasiyla bir dosya ve kelime vermelisiniz.\n");
		exit(-1);
	}
	int fd = open(argv[1], O_RDONLY);
	if(fd < 0){
		printf("Dosya acma hatasi.\n");
		exit(-2);
	}
	int n = 1;
	int i;
	char buf;
	int count = 0;
	while(n != 0){
		i = 0;
		while(i < strlen(argv[2])){
			n = read(fd, &buf, 1);
			if(n == 0) break;
			if(buf == argv[2][i]){
				if(i == strlen(argv[2]) - 1){
					count++;
					i++;
					break;
				}
				else{
					i++;
				}
			}
		}
	}
	printf("%d\n", count);
	close(fd);
	return 0;
}
