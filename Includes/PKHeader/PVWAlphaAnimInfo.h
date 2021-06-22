#ifndef _PVWALPHAANIMINFO_H
#define _PVWALPHAANIMINFO_H

#pragma once
#include <types.hpp>

class DllImport PVWAlphaAnimInfo {
public:
    class PVWAlphaAnimInfo& operator=(class PVWAlphaAnimInfo const&);
    void extract(float, class Colour&);
};

#endif
