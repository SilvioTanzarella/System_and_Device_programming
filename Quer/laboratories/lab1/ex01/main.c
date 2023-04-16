#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define L 31

typedef struct student_s{
    int id;
    long int rn;
    char n[L];
    char s[L];
    int mark;
}student_t;



int main(int argc, char *argv[]){

    FILE *fp;
    int fd, n;
    student_t student_d;
    
    if(argc != 4){
        fprintf(stderr, "Wrong number of parameters\n");
        exit(1);
    }

    //PART 1: read ASCII file and write BINARY file
    fp = fopen(argv[1], "r");
    if(fp == NULL){
        fprintf(stderr, "error opening %s\n", argv[1]);
        exit(1);
    }

    fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC , S_IRUSR, S_IWUSR);
    if(fd == -1){
        fprintf(stderr, "error opening %s\n", argv[2]);
        exit(1);
    }

    while(fscanf(fp, "%d%ld%s%s%d", &student_d.id, &student_d.rn, student_d.n, student_d.s, &student_d.mark) !=EOF){
        fprintf(stdout, "%d %ld %s %s %d\n", student_d.id, student_d.rn, student_d.n, student_d.s, student_d.mark);
        n = write(fd, &student_d, sizeof(student_t));
        if(n != sizeof(student_t)){
            fprintf(stderr, "error wirting %s\n", argv[2]);
            exit(1);
        }
    }

    fclose(fp);
    close(fd);

    //PART 2: read BINARY and write ASCII file
    fd = open(argv[2], O_RDONLY);
    if(fd == -1){
        fprintf(stderr, "error opening %s\n", argv[2]);
        exit(1);
    }

    fp = fopen(argv[3], "w");
    if(fp == NULL){
        fprintf(stderr, "error opening %s\n", argv[3]);
        exit(1);
    }

    while((n = read(fd, &student_d, sizeof(student_t))) == sizeof(student_d)){
        fprintf(fp, "%d %ld %s %s %d\n", student_d.id, student_d.rn, student_d.n, student_d.s, student_d.mark);
    }

    fclose(fp);
    close(fd);

    return 0;
}