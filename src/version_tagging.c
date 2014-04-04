#include <stdlib.h>
#include <stdio.h>
#include <hdf5.h>
#include <hdf5_hl.h>
#include "git.h"

int main(int argc, char *argv[])
{

  hid_t fd;
  hsize_t dims[1] = {10};
  
  printf("Hello world!\n");

  printf("Writing file...\n");

  fd = H5Fcreate("output.hdf5", H5F_ACC_TRUNC, H5P_DEFAULT, H5P_DEFAULT);
  H5LTmake_dataset_string(fd, "gitdiff", GITDIFF);
  H5LTset_attribute_string(fd, "gitdiff", "gitref", GITREF);
  H5Fclose(fd);

  printf("...done\n");

  return 0;
}
