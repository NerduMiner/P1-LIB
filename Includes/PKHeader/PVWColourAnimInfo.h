#ifndef _PVWCOLOURANIMINFO_H
#define _PVWCOLOURANIMINFO_H

#pragma once
#include <types.hpp>

class DllImport PVWColourAnimInfo {
public:
    class PVWColourAnimInfo& operator=(class PVWColourAnimInfo const&);
    void extract(float, class Colour&);
};

#endif
