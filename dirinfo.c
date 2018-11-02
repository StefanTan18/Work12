#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>

int main() {
  DIR * d;
  d = opendir(".");
  struct dirent * entry = readdir(d);
  struct stat meta;
  int total = 0;
 
  while (entry) {
    stat(entry->d_name, &meta);
    total += meta.st_size;
    entry = readdir(d);
  }

  printf("Total Directory Size: %d Bytes\n", total);

  /*
  if(readdir(d)){
    printf("NO D\n");
    return 0;
    }
  while(readdir(d)){
    entry = readdir(d);
    printf("%s", entry->d_name);
    }*/
  closedir(d);
  return 0;
}
