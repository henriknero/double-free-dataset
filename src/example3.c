#include <stdio.h>
#include <stdlib.h>

#define NROF_THINGS 0x300
#define VULN_INDEX  0x1a7

int *things[NROF_THINGS];

void ck_fread(void* ptr, size_t size, size_t nitems, FILE *stream) {
  if (fread(ptr, size, nitems, stream) != nitems) {
    printf("[-] Failed to read\n");
    exit(-1);
  }
}

void do_allocs(){
    for (int i = 0; i < NROF_THINGS; i++) {
        int *thing = malloc(sizeof(int));
        things[i] = thing;
    }
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage: %s [input]\n", argv[0]);
    exit(-1);
  }

  FILE* fp = fopen(argv[1], "rb");

  if (fp == NULL) {
    printf("[-] Failed to open\n");
    exit(-1);
  }

  int x;

  ck_fread(&x, sizeof(x), 1, fp);

  if (x >= NROF_THINGS || x < 0)
      exit(1);

  do_allocs();
  free(things[VULN_INDEX]);
  things[VULN_INDEX]=malloc(sizeof(int));
  free(things[x]);

  return 0;
}
