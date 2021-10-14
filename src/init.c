#include <syscall.h>


long _syscall(int num, void *a0, void *a1, void *a2, void * a3, void * a4, void * a5);

unsigned long _strlen(char *sz){
    int count = 0;
    while(*sz++){
        count++;
    }

    return count;
}

void delay(int ticks){
    for(int i=0; i < ticks;i++){
	//do nothing...
    }
}

void print_string(char *str){
    _syscall(SYS_write,(void *) 1 /*stdout*/, str, (void *)_strlen(str),0,0,0);
}

int main(int argc, char const *argv[])
{
    char* msg = "MyOs 0.0.0.1 Initializing...n";

    delay(1000000000);

    print_string(msg);
    while(1){
        //event loop of os
        delay(1000000000);
        print_string("TICK!\n");
    }

    return 0;
}
