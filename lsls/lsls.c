#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void print_dir(char *dirname, int width, int count) {
  // Open directory
  DIR *d = opendir(dirname);

  if (d == NULL) {
    // printf("\n%s\n", dirname);
    fprintf(stderr, "\nRequires a valid directory!\nUsage: ./lsls.exe [directory], i.e.: ./lsls.exe ../examples\n");
    exit(1);
  }

  // Repeatly read and print entries
  struct dirent *ent;
  struct stat buf;

  while ((ent = readdir(d)) != NULL) {
    int len = strlen(dirname) + strlen(ent->d_name) + 1;
    char path[len];
    strcpy(path, dirname);
    strcat(path, "/");
    strcat(path, ent->d_name);
    // printf("path: %s\n", path);
    stat(path, &buf);
    if (S_ISDIR(buf.st_mode) == 0) {
      printf("%*ld %s\n", width, buf.st_size, ent->d_name);
    } else {
      printf("%*s %s\n", width, "<DIR>", ent->d_name);
      if (count)
        print_dir(path, width+10, count-1);
    }
  }

  // Close directory
  closedir(d);
}

/**
 * Main
 */
int main(int argc, char **argv) {
  char *dirname;

  // Parse command line
  if (argc > 2) {
    fprintf(stderr, "\nUsage: ./lsls.exe [directory], i.e.: ./lsls.exe ../examples\n");
    exit(1);
  } else
    dirname = argc == 2 ? argv[1] : ".";
  
  print_dir(dirname, 10, 1);

  return 0;
}
