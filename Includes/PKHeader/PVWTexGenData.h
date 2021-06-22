#ifndef _PVWTEXGENDATA_H
#define _PVWTEXGENDATA_H

#pragma once
#include <types.hpp>

class DllImport PVWTexGenData {
public:
    class PVWTexGenData& operator=(class PVWTexGenData const&);
    void read(class RandomAccessStream&);
    void write(class RandomAccessStream&);

    u32 m_dword0; // _00
};

#endif
