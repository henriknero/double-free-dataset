#include <stdio.h>
#include <stdlib.h>

#define NROF_THINGS 0x300

int *things[NROF_THINGS];
int *things2[NROF_THINGS];

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
    for (int i = 0; i < NROF_THINGS; i++) {
        int *thing2 = malloc(sizeof(int));
        things2[i] = thing2;
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

  int y;

  ck_fread(&y, sizeof(y), 1, fp);

  if (y >= NROF_THINGS || y < (-0x300))
      exit(1);

  do_allocs();
  free(things[1]);
  free(things2[y]);

  return 0;
}
