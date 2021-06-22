#ifndef _PVWKEYINFOS10_H
#define _PVWKEYINFOS10_H

#pragma once
#include <types.hpp>

class DllImport PVWKeyInfoS10 {
public:
    class PVWKeyInfoS10& operator=(class PVWKeyInfoS10 const&);
    bool isSame(class PVWKeyInfoS10&);
    void read(class RandomAccessStream&);
    void write(class RandomAccessStream&);
};

#endif
