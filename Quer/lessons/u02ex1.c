#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define N 100
#define L 255

typedef struct record_s{
    int i;
    char s[N];
    float f;
    struct record_s *next;
} record_t;

void printList(record_t *head);

int main(int arch, char **argv[]){
    
    int fd, size_read, position=0;
    char c;
    char line[L];
    record_t *r, *head;

    fd = open("input.txt", O_RDONLY);
    head = NULL;

    do{
        position = 0;
        do{
            size_read = read(fd, &c, sizeof(char));
            if(size_read != 0){
                line[position] = c;
                position ++;
            }
        }while(c != '\n' && size_read);
        
        r = (record_t *) malloc(1*sizeof(record_t));
        sscanf(line, "%d %s %f", &r->i, r->s, &r->f);
        r->next = head;
        head = r;
    }while(size_read);

    close(fd);
    printList(head);

    return 0;
}

void printList(record_t *head){
    record_t *t;
    for(t=head; t != NULL; t = t->next){
        printf("%d %s %f\n", t->i, t->s, t->f);
    }
}