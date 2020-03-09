# dwrite
Shell script to format &amp; write or flash a bootable device.

Usage:

## INFORMATION ##

-c: check devices.

-u: umount a device.

-p: the path of the device.

-v: show the version of the script.

## TO FORMAT THE DEVICE ##

-W: write the format to the usb table. (FAT32/EXT4/NTFS)

## TO FLASH A IMAGE TO THE DEVICE ##

-i: the path of the image.

-F: flash a image into the device.

REMEMBER: You need to use the uppercase flags (-W/-F) ever at the end!
          Don't mix the Write and Flash commands!   
          Use the main partition to describe it. The script will automatically write in the correct table.
          Example:
          
          /dev/sdb
          /dev/sdc
          /dev/sde
          ...

Example:
```shell
$ ./dwrite -p /dev/sdx -u -W [FORMAT] #To format & write a device
$ ./dwrite -p /dev/sdx -i /path/of/the/image.iso -F #To flash a bootable device
```

You can also use it without enter in the folder where the script is:
```shell
$ mv dwrite /usr/local/bin/dwrite
$ dwrite
```
Or as a ROOT:
```shell
# mv dwrite /bin/dwrite
# dwrite
```

This script have implemented sudo because to write partitions you need to have the administrator's authority.
