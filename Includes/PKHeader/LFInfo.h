#ifndef _LFINFO_H
#define _LFINFO_H

#pragma once
#include <types.hpp>

class DllImport LFInfo {
public:
    LFInfo(class LFInfo const&);
    LFInfo(void);
    class LFInfo& operator=(class LFInfo const&);

    char _00[0x2C];
};

#endif
