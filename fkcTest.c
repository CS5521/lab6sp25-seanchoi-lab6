#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char * argv[])
{
    int pid = 0;
    int fkc0, fkc1, fkc2, fkc3;
    fkc0 = fkc(1);
    printf(1, "number of forks when program starts: %d\n", fkc0);
    pid = fork();
    if(pid == 0){
        exit();
    }
    pid = fork();
    if(pid == 0){
        exit();
    }
    wait();
    wait();
    fkc1 = fkc(1);
    printf(1, "number of forks after two more forks: %d\n", fkc1);
    fkc2 = fkc(0);
    printf(1, "number of forks after fork count cleared: %d\n", fkc2);
    pid = fork();
    if(pid == 0){
        exit();
    }
    pid = fork();
    if(pid == 0){
        exit();
    }
    pid = fork();
    if(pid == 0){
        exit();
    }
    wait();
    wait();
    wait();
    fkc3 = fkc(1);
    printf(1, "number of forks after three more forks: %d\n", fkc3);
    exit();
}
