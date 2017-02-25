#ifndef ERPC_BUFFER_H
#define ERPC_BUFFER_H

#include "common.h"

namespace ERpc {

/// A class to hold a fixed-size buffer. The size of the buffer is read-only
/// after the Buffer is created.
class Buffer {
 public:
  Buffer(uint8_t *buf, size_t size, uint32_t lkey)
      : buf(buf), size(size), lkey(lkey) {}

  Buffer() {}

  /// Since \p Buffer does not allocate its own \p buf, do nothing here.
  ~Buffer() {}

  inline bool is_valid() { return buf != nullptr; }

  static Buffer get_invalid_buffer() { return Buffer(nullptr, 0, 0); }
  size_t get_size() { return (size_t)size; }
  uint32_t get_lkey() { return lkey; }

  uint8_t *buf = nullptr;

 private:
  size_t size = 0;
  uint32_t lkey = 0;
};

}  // End ERpc

#endif  // ERPC_BUFFER_H
