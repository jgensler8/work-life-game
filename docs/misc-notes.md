\page misc-notes Notes: Miscellaneous

* start button menu
** menu container
** global settings
* scene presets (bg, audio, sprite, text)
* text wrapping / packing (?)
* dialog choice

debugging: https://felixjones.co.uk/mgba_gdb/vscode.html

web emulator: https://github.com/simon-paris/gba.ninja

inspect object file: `C:\devkitPro\devkitARM\arm-none-eabi\bin\objdump.exe`

`C:\devkitPro\devkitARM\arm-none-eabi\bin\nm.exe --print-size --size-sort ./build/story.o`

## line length

* https://ux.stackexchange.com/questions/108801/what-is-the-best-number-of-paragraph-width-for-readability
* https://en.wikipedia.org/wiki/Line_length#Electronic_text
* ideal is 66 chars. variable width best case: 240 / 5 = 48 chars

note: I've found 80 chars to not be comfortable. 50 seems ok.

* fixed width: 144 px / 8px width = 18 chars. 
* variable width: 144 px / 5px width = ~28 chars.