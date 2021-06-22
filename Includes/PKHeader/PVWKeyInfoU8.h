#ifndef _PVWKEYINFOU8_H
#define _PVWKEYINFOU8_H

#pragma once
#include <types.hpp>

class DllImport PVWKeyInfoU8 {
public:
    class PVWKeyInfoU8& operator=(class PVWKeyInfoU8 const&);
    void read(class RandomAccessStream&);
    void write(class RandomAccessStream&);
};

#endif
