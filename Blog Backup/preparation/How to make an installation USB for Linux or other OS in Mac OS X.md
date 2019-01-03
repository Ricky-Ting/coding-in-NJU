# How to make an installation USB for Linux or other OS in Mac OS X

Step1: Download the image(iso) file from the Internet.

Step2: Open a Terminal(the following command are all completed in a terminal)

Step3: Trun `.iso` file into `.img` file by `hdiutil convert -format UDRW -o ~/path/to/target.img ~/path/from/src.iso`(The file created may end with `.dmg`)

Step4: `diskutil list` to obtain the devices mounted.

Step5: Insert your USB.

Step6: `diskutil list` to see which is added(/dev/diskN).

Step7: `diskutil unmountDisk /dev/diskN` to unmount USB

Step8: `sudo dd if=/path/to/target.img of=/dev/rdiskN bs=1m` to write the installation file into the USB

Step9: `diskutil eject /dev/diskN` to eject your USB.