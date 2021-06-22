#ifndef _PVWTEVSTAGE_H
#define _PVWTEVSTAGE_H

#pragma once
#include <types.hpp>
#include <PKHeader/PVWCombiner.h>

class DllImport PVWTevStage {
public:
    class PVWTevStage& operator=(class PVWTevStage const&);
    void read(class RandomAccessStream&);
    void write(class RandomAccessStream&);

    u8 m_byte0;                  // _00
    u8 m_byte1;                  // _01
    u8 m_byte2;                  // _02
    u8 m_byte3;                  // _03
    u8 m_byte4;                  // _04
    u8 m_byte5;                  // _06
    PVWCombiner m_pvwCombiner6;  // _06
    PVWCombiner m_pvwCombiner12; // _12
};

#endif
