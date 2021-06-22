#ifndef _PVWKEYINFOF32_H
#define _PVWKEYINFOF32_H

#pragma once
#include <types.hpp>

class DllImport PVWKeyInfoF32 {
public:
    class PVWKeyInfoF32& operator=(class PVWKeyInfoF32 const&);
    void read(class RandomAccessStream&);
    void write(class RandomAccessStream&);
};

#endif
