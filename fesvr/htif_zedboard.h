// See LICENSE for license details.

#ifndef __HTIF_ZEDBOARD_H
#define __HTIF_ZEDBOARD_H

#include "htif.h"
#include <vector>

class htif_zedboard_t : public htif_t
{
 public:
  htif_zedboard_t(const std::vector<std::string>& args);
  ~htif_zedboard_t();

 protected:
  ssize_t read(void* buf, size_t max_size);
  ssize_t write(const void* buf, size_t size);

  size_t chunk_max_size() { return 64; }
  size_t chunk_align() { return 64; }
  uint32_t mem_mb() { return 256; }

 private:
  void poll_mem();
  uintptr_t* mem;
  volatile uintptr_t* dev_vaddr;

  const static uintptr_t dev_paddr = 0x40000000;
};

#endif // __HTIF_ZEDBOARD_H
