# dwrite
Shell script to format &amp; write or flash a bootable device.

Usage:

First compile to run this script:
```shell
$ gcc dwrite.c -o dwrite; ./dwrite -h
```

## INFORMATION ##

-h: prints the help option.

-c: check devices.

-o: the path of the device.

-i: the ISO image.

-v: show the version of the script.

-F: format tables.(FAT32/EXT4/NTFS/ZERO)

## TO FORMAT THE DEVICE ##

Use the device path and the format that you desire to write:
  ```shell
$ ./dwrite -o /dev/sdx -F EXT4
  ```

## TO FLASH A IMAGE TO THE DEVICE ##

Use the ISO path and device flags:
```shell
$ ./dwrite -o /dev/sdx -i /path/of/the.iso
```

Use the main partition to describe it. The script will automatically write in the correct table.

Example: /dev/sdb | /dev/sdc | /dev/sde...

## NOTE ##

You can also use it without enter in the folder where the script is:
```shell
$ mv dwrite /usr/local/sbin/dwrite
$ dwrite
```
Or as a ROOT:
```shell
# mv dwrite /usr/sbin/dwrite
# dwrite
```

This script have implemented sudo, because to write partitions you need to have the administrator's authority.
