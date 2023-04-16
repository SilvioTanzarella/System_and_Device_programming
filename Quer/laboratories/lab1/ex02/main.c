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



int main(int argc, char **argv[]){

    char str[L], command[L];
    int fd, n;
    student_t student_d;
    
    if(argc != 2){
        fprintf(stderr, "Wrong number of parameters\n");
        exit(1);
    }

    fprintf("Final file:\n");
    fd = open(argv[1], O_RDWR);
    if(fd == -1){
        fprintf(stderr, "error opening file %s", argv[1]);
        exit(1);
    }

    while((n = read(fd, &student_d, sizeof(student_t))) == sizeof(student_d)){
        fprintf(stdout, "%d %ld %s %s %d\n", student_d.id, student_d.rn, student_d.n, student_d.s, student_d.mark);
    }

    do{
        fprintf(stdout, "Command:");
        fgets(str, L, stdin);
        sscanf(str, "%s", command);
        if(strcmp(command, "E") == 0){
            break;
        }
        sscanf(str, "%*s%d", &n);
        lseek(fd, ((n-1)*sizeof(student_t)), SEEK_SET);
        if(strcmp(command, "R") == 0){
            read(fd, &student_d, sizeof(student_t));
            fprintf(stdout, "%d %ld %s %s %d\n", student_d.id, student_d.rn, student_d.n, student_d.s, student_d.mark);
        }else if(strcmp(command, "W") == 0){
            scanf("%d%ld%s%s%d\n", &student_d.id, &student_d.rn, student_d.n, student_d.s, &student_d.mark);
            write(fd, &student_d, sizeof(student_t));
        }
    }while(strcmp(command, "E") != 0);

    fprintf(stdout, "Final file:\n");
    lseek(fd, 0, SEEK_SET);
    while((n = read(fd, &student_d, sizeof(student_t))) == sizeof(student_d)){
        fprintf(stdout, "%d %ld %s %s %d\n", student_d.id, student_d.rn, student_d.n, student_d.s, student_d.mark);   
    }
    
    close(fd);
    
    return 0;
}