#ifndef _PVWCOLOURSHORTANIMINFO_H
#define _PVWCOLOURSHORTANIMINFO_H

#pragma once
#include <types.hpp>

class DllImport PVWColourShortAnimInfo {
public:
    class PVWColourShortAnimInfo& operator=(class PVWColourShortAnimInfo const&);
    void extract(float, class ShortColour&);
};

#endif
