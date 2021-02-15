#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int checkDevices(){
  system("sudo fdisk -l");
  return 0;
}

void version(){
  printf("\n  dwrite 2.1 - \e[0;36mKanuX-14\e[m | 15/04/2021 ~ 01:23 AM\n");
}

void help(){
  printf("\n  \e[0;32m[INFORMATION]\n\n  [INITIAL FLAGS]\e[m\n\n  -h: prints this option.\n  -c: check devices.\n  -o: the path of the device.\n  -i: the ISO image.\n  -v: show the version of the script.\n  -F: format tables.(FAT32/EXT4/NTFS/ZERO)\n\n  \e[0;32m[TO FORMAT THE DEVICE]\e[m\n\n  Use the device path and the format that you desire to write:\n    dwrite -o /dev/sdx -F EXT4\n\n  \e[0;32m[TO FLASH A IMAGE TO THE DEVICE]\e[m\n\n  Use the ISO path and device flags:\n    dwrite -o /dev/sdx -i /path/of/the.iso\n\n  Use the main partition to describe it. The script will automatically write in the correct table.\n    Example:\n      /dev/sdb\n      /dev/sdc\n      /dev/sde\n      ...\n");
}

void main(int argc, char **argv){
  int option;
  int opened=1;
  char *ipath=NULL, *dpath=NULL, *arg=NULL, *fat32="FAT32", *ext4="EXT4", *ntfs="NTFS", *zero="ZERO";
  while((option = getopt(argc, argv, ":vVcCi:I:o:O:f:F:")) != -1){
    switch(option){
      case 'v':
      case 'V':
        version();
        opened=0;
        break;
      case 'c':
      case 'C':
        checkDevices();
        opened=0;
        break;
      case 'i':
      case 'I':
        ipath = optarg;
        break;
      case 'o':
      case 'O':
        dpath = optarg;
        break;
      case 'f':
      case 'F':
        arg = optarg;
        break;
      case '?':
        printf("I don't understand.");
    }
  }
  if((ipath != NULL) && (dpath != NULL) && (arg == NULL)){
    char cmd[128]; sprintf(cmd, "sudo dd if='%s' of='%s' bs=4M conv=fdatasync", ipath, dpath); system(cmd);
  }else if((dpath != NULL) && (arg != NULL) && (ipath == NULL)){
    char cmd[250]; sprintf(cmd, "sudo umount %s", dpath); system(cmd);
    if(arg[0] == fat32[0]){
      char cmd[250]; sprintf(cmd, "sudo mkfs.fat -F32 -v -l '%s'", dpath); system(cmd);
    }else if(arg[0] == ext4[0]){
      char cmd[250]; sprintf(cmd, "sudo mkfs.ext4 -F -O ^64bit -L '' '%s'", dpath); system(cmd);
    }else if(arg[0] == ntfs[0]){
      char cmd[250]; sprintf(cmd, "sudo mkfs.ntfs -F32 -Q -v -F -L '' '%s'", dpath); system(cmd);
    }else if(arg[0] == zero[0]){
      char cmd[250]; sprintf(cmd, "sudo dd if=/dev/zero of='%s' bs=512 count=1", dpath); system(cmd);
    }else if((arg[0] == fat32[0]) || (arg[0] == ext4[0]) || (arg[0] == ntfs[0]) || (arg[0] == zero[0]) || (ipath != NULL)){
      printf("This format is not supported or does not exists.\n");
    }
    printf("Reconnect your device to mount it.");
  }else if(opened){help();}
}
