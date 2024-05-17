#include "cachelab.h"

#include<getopt.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int verbose = 0;
char *tracefile = NULL;

void help() {
    printf("Usage: ./csim [-hv] -s <num> -E <num> -b <num> -t <file>\n");
    printf("Options:\n");
    printf("  -h         Print this help message.\n");
    printf("  -v         Optional verbose flag.\n");
    printf("  -s <num>   Number of set index bits.\n");
    printf("  -E <num>   Number of lines per set.\n");
    printf("  -b <num>   Number of block offset bits.\n");
    printf("  -t <file>  Trace file.\n");
    printf("\nExamples:\n");
    printf("  linux>  ./csim -s 4 -E 1 -b 4 -t traces/yi.trace\n");
    printf("  linux>  ./csim -v -s 8 -E 2 -b 4 -t traces/yi.trace\n");
    return;
}

void cacheInit(int s, int E, int b) {
    return;
}

void cacheTrace(int s, int E, int b) {
    return;
}

void cacheFree() {
    return;
}

int main(int argc, char *argv[]) {
    char opt;
    int s = 0, E = 0, b = 0;
    while((opt=getopt(argc,argv,"hvs:E:b:t"))!=-1)
    {
        switch(opt)
        {
            case 'h':
                help();
                exit(0);
            case 'v':
                verbose = 1;
                break;
            case 's':
                s = atoi(optarg);
                break;
            case 'E':
                E = atoi(optarg);
                break;
            case 'b':
                b = atoi(optarg);
                break;
            case 't':
                tracefile = optarg;
                break;
            default:
                help();
                exit(-1);
        }
    }
    cacheInit(s, E, b);
    cacheTrace(s, E, b);
    cacheFree();
    printSummary(0, 0, 0);
    return 0;
}
