#ifndef _PVWPOLYGONCOLOURINFO_H
#define _PVWPOLYGONCOLOURINFO_H

#pragma once
#include <types.hpp>

class DllImport PVWPolygonColourInfo {
public:
    PVWPolygonColourInfo(void);
    class PVWPolygonColourInfo& operator=(class PVWPolygonColourInfo const&);
    void animate(float*, class Colour&);
    void read(class RandomAccessStream&);
    void write(class RandomAccessStream&);

    char _00[0x20]; // _00
};

#endif
