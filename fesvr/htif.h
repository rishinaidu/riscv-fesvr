#ifndef __HTIF_H
#define __HTIF_H

#include "interface.h"
#include <string.h>

class htif_t
{
public:
  virtual ~htif_t() {}

  virtual void start(int coreid) = 0;
  virtual void stop(int coreid) = 0;
  virtual void read_chunk(addr_t taddr, size_t len, uint8_t* dst, int cmd=IF_MEM) = 0;
  virtual void write_chunk(addr_t taddr, size_t len, const uint8_t* src, int cmd=IF_MEM) = 0;
  virtual reg_t read_cr(int coreid, int regnum) = 0;
  virtual void write_cr(int coreid, int regnum, reg_t val) = 0;
  virtual size_t chunk_align() = 0;
};

struct packet_t;

#endif // __HTIF_H