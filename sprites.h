#pragma once

typedef struct sprite_t {
  const u16_t * width;
  const u16_t * height;
  const s16_t * x_offset;
  const s16_t * y_offset;
  const u8_t * duration;
  const u8_t ** rgba;
  const u16_t count;
} sprite_t;

typedef struct sprite_animation_t {
  const sprite_t * sprite;
  const u16_t * indices;
  const u16_t count;
} sprite_animation_t;

void sprite_draw(
  const sprite_t sprite,
  s16_t x,
  s16_t y,
  u8_t * rgba,
  u16_t rgba_width,
  u16_t rgba_height
);

void sprite_animation_draw(
  const sprite_animation_t sprite_animation,
  u64_t elapsed_frames,
  s16_t x,
  s16_t y,
  u8_t * rgba,
  u16_t rgba_width,
  u16_t rgba_height
);
