#ifndef A0_COMMON_H
#define A0_COMMON_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int errno_t;

static const errno_t A0_OK = 0;

typedef struct a0_buf_s {
  uint8_t* ptr;
  size_t size;
} a0_buf_t;

typedef struct a0_callback_s {
  void* user_data;
  void (*fn)(void* user_data);
} a0_callback_t;

typedef struct a0_alloc_s {
  void* user_data;
  void (*fn)(void* user_data, size_t size, a0_buf_t*);
} a0_alloc_t;

#ifdef __cplusplus
}
#endif

#endif  // A0_COMMON_H
