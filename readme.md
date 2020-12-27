# neomura > c library sprites

gnu89 c library for animating and drawing sprites within games for neomura
virtual retro games console.

[mit licensed](./license.md).

## installation

add this repository as a git submodule, then include
[sprites.h](./sprites.h) from any files where the types or functions are
required, and add a stub c file to bring its function implementations into the
game:

```c
#include "path-to-neomura.h"
#include "path-to-sprites.c"
```

note that the neomura [c library](https://github.com/neomura/c-library) must be
included before including [sprites.h](./sprites.h).

## declarations

### types

#### sprite_t

struct representing a sprite, with multiple frames, in struct-of-arrays format.

| field    | meaning                                                          |
| -------- | ---------------------------------------------------------------- |
| width    | the widths of the sprite's frames.                               |
| height   | the heights of the sprite's frames.                              |
| x_offset | the relative locations of the left edges of the sprite's frames. |
| y_offset | the relative locations of the top edges of the sprite's frames.  |
| duration | the number of refresh rate frames to show the sprite's frames.   |
| rgba     | the pixel data of the sprite's frames (see below).               |
| count    | the number of frames in the sprite.                              |

##### rgba formatting

each u8 represents the intensity of a color channel for a pixel.

runs through channels red, green, blue and alpha (opacity), then from left to
right, then from top to bottom.

red, green and blue are pre-multiplied by alpha; a fully transparent pixel of
any color will always have a red, green and blue value of zero.  a fully opaque,
white pixel will have a red, green and blue value of 255.

alpha is inverted; fully opaque is 0 and fully transparent is 255.

#### sprite_animation_t

struct representing an animation constructed by specifying an order in which to
display a sprite's frames.

| field    | meaning                                           |
| -------- | ------------------------------------------------- |
| sprite   | the sprite an animation is defined for.           |
| indices  | the indices of the frames to display, in order.   |
| count    | the number of indices.                            |
| duration | the total number of refresh rate frames per loop. |

note that some animations may specify the same index twice.

### functions

#### sprite_draw

given:

- a sprite.
- the location of the origin relative to the left border of the video buffer.
- the location of the origin relative to the top border of the video buffer.
- the video buffer to render to.
- the width of the video buffer.
- the height of the video buffer.

draws the sprite to the video buffer.

#### sprite_animation_draw

given:

- a sprite animation.
- the number of elapsed refresh rate frames.
- the location of the origin relative to the left border of the video buffer.
- the location of the origin relative to the top border of the video buffer.
- the video buffer to render to.
- the width of the video buffer.
- the height of the video buffer.

draws the currently visible sprite to the video buffer, looping at the end of
the animation.

#### sprite_animation_loops

given:

- a sprite animation.
- the number of elapsed refresh rate frames.

returns the number of times the animation has looped.
