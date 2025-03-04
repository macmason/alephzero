#pragma once

#include <a0/common.h>

#include <a0/internal/stream_tools.hh>

#include <mutex>
#include <set>
#include <string>

inline std::string str(a0_buf_t buf) {
  return std::string((char*)buf.ptr, buf.size);
}

inline std::string str(a0_stream_frame_t frame) {
  return str(a0::buf(frame));
}

inline a0_buf_t buf(std::string str) {
  static std::set<std::string> mem;
  static std::mutex mu;
  std::unique_lock<std::mutex> lk{mu};
  if (!mem.count(str)) {
    mem.insert(str);
  }
  return a0_buf_t{
      .ptr = (uint8_t*)mem.find(str)->c_str(),
      .size = str.size(),
  };
}

inline bool is_valgrind() {
#ifdef RUNNING_ON_VALGRIND
  return RUNNING_ON_VALGRIND;
#endif
  char* env = getenv("RUNNING_ON_VALGRIND");
  return env && std::string(env) != "0";
}
