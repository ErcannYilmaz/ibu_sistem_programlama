#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
	if(argc != 2){
		printf("Bir dosya ismi vermelisiniz.");
		exit(-1);
	}
	int fd = open(argv[1], O_RDONLY);
	if(fd < 0){
		printf("Dosya acma hatasi.\n");
		exit(-2);
	}
	char buf;
	int size = 0;
	int num_of_vowels = 0;
	int n = 1;
	int num_of_spaces = 0;
	while(n != 0){
		n = read(fd, &buf, 1);
		if(buf == 'a' || buf == 'e' || buf == 'i' || buf == 'o' || buf == 'u' || buf == 'A' || buf == 'E' || buf == 'I' || buf == 'O' || buf == 'U'){
			num_of_vowels++;
		}
		if(buf == ' '){
			num_of_spaces++;
		}
		size++;
	}
	size -= 2;
	printf("Sesli harfleri sayisi:%d\nSessiz harflerin sayisi:%d\nBosluk karakterinin sayisi:%d\n", num_of_vowels, (size - num_of_vowels - num_of_spaces), num_of_spaces);
	close(fd);
	return 0;
}
