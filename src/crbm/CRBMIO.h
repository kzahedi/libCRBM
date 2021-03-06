#ifndef __CRBM_IO_H__
#define __CRBM_IO_H__

#include <crbm/CRBM.h>

#include <string>

using namespace std;
using namespace libcrbm::binary;

class CRBMIO
{
  public:

    static void write(string filename, CRBM* crbm);
    static CRBM* read(string filename);

  private:
};


#endif // __CRBM_IO_H__
