#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

int main(int argc, char * argv[]) {

  DIR * d;
  DIR * d1;
  DIR * d2;

  if(argc > 1) {
    d = opendir(argv[1]);
    d1 = opendir(argv[1]);
    d2 = opendir(argv[1]);
    printf("Statistics for directory: %s\n", argv[1]); 
  }
  else {
    printf("Enter a directory: ");
    char * s = malloc(sizeof(char));
    scanf("%s", s);
    d = opendir(s);
    d1 = opendir(s);
    d2 = opendir(s);
    printf("Statistics for directory: %s\n", s);
    free(s);
  }

  if(!d) {
    printf("%s\n", strerror(errno));
    return 0;
  }
  
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

  if(total < 1024){
    printf("Total Directory Size: %d B\n", total);
  }
  else if(total < 1048576){
    printf("Total Directory Size: %f KB\n", total / 1024.0);
  }
  else if(total < 1073741824){
    printf("Total Directory Size: %f MB\n", total / 1048576.0);
  }
  else {
    printf("Total Directory Size: %f GB\n", total / 1073741824.0);
  }
  closedir(d);

  entry = readdir(d1);
  
  printf("Directories:\n");
  while (entry) {
    if (entry->d_type == DT_DIR) {
      printf("\t%s\n", entry->d_name);
    }
    entry = readdir(d1);
  }
  closedir(d1);
  
  entry = readdir(d2);

  printf("Regular files:\n");
  while (entry) {
    if (entry->d_type != DT_DIR) {
      printf("\t%s\n", entry->d_name);
    }
    entry = readdir(d2);
  }
  closedir(d2);

  return 0;
}
