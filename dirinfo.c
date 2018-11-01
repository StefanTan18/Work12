#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>

int main() {
  DIR * d;
  d = opendir("../Work12");
  struct dirent * entry;
  if(readdir(d)){
    printf("NO D\n");
    return 0;
  }
  while(readdir(d)){
    entry = readdir(d);
    printf("%s", entry->d_name);
  }
  closedir(d);
  return 0;
}
