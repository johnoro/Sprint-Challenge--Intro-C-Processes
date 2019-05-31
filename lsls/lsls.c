#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

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

  // Open directory
  DIR *d = opendir(dirname);

  if (d == NULL) {
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
      printf("%10ld %s\n", buf.st_size, ent->d_name);
    } else {
      printf("%10s %s\n", "<DIR>", ent->d_name);
    }
  }

  // Close directory
  closedir(d);

  return 0;
}
