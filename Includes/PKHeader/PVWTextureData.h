#ifndef _PVWTEXTUREDATA_H
#define _PVWTEXTUREDATA_H

#pragma once
#include <types.hpp>

class DllImport PVWTextureData {
public:
    PVWTextureData(void);
    class PVWTextureData& operator=(class PVWTextureData const&);
    void animate(float*, class Matrix4f&);
    void read(class RandomAccessStream&);
    void write(class RandomAccessStream&);
};

#endif
