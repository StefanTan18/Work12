#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>

int dirfiles(char * dirname) {
  DIR * d;
  d = opendir(dirname[1]);
  struct dirent * entry = readdir(d);
  struct stat meta;
  int total = 0;

  while (entry) {
    stat(entry->d_name, &meta);
    if (entry->d_type != DT_DIR) {
      total += meta.st_size;
    }
    entry = readdir(d);
  }
  printf("Total Directory Size: %d Bytes\n", total);

  d = opendir(dirname[1]);
  entry = readdir(d);

  printf("Directories:\n");
  while (entry) {
    if (entry->d_type == DT_DIR) {
      printf("\t%s\n", entry->d_name);
    }
    entry = readdir(d);
  }

  d = opendir(".");
  entry = readdir(d);

  printf("Regular files:\n");
  while (entry) {
    if (entry->d_type != DT_DIR) {
      printf("\t%s\n", entry->d_name);
    }
    entry = readdir(d);
  }
  
  closedir(d);
  return 0;
}

int main(int argc, char *argv[]){
  dirfiles(argv[1]);
  return 0;
}
