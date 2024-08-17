\page sprite-sizes Design: Sprite Sizes

# Sprite Sizes {#sizes}

* other bg (bg): 256x256, 240x160 visible
* title screen (bg): 100,100 start, 240x160 visible
* textbox overlay (bg): 144x96 size, justified top left
* save screen (bg): 32,10 start // 28px box (10+2+10+2+10) // 40px between box starts (ex: 32,10,32,50,32,90)
* keyboard (bg): start 14x10
  * letters: use 8x8 grid, alternating squares contain letter
    * `8 cols == 8x120 == (width: 8*8 (letter) + 8*7 (spacing))`
    * `4 rows == 120x38 == (height: 8*4 + 8*3)`
  * "del" button: `start 54x58, 3*8 wide`
  * "done" button: `start 94x58, 4*8 wide`
  * input/ouput: `46x86, 8*8 wide`
* cursor (sprite): 16x16
* character (bg): 96x160
* menu bg, left and right, no animation: 64x64

---

# Color Palettes {#color-palettes}

Note: these are included in Aseprite

## This Game {#this-game}

* This game: Atari 2600 NTSC (128): https://lospec.com/palette-list/atari-2600-palette-ntsc-version

## Other Possibilities {#other-possibilities}

* AAP-Splendor128 (128): https://lospec.com/palette-list/aap-splendor128
* Commodore Plus/4 (119): https://lospec.com/palette-list/commodore-ted-plus-4-c16
* VGA (244): https://lospec.com/palette-list/video-graphics-array
* Web Safe 216 (216): https://lospec.com/palette-list/web-safe-216