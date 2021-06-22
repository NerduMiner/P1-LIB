#ifndef _PVWALPHASHORTANIMINFO_H
#define _PVWALPHASHORTANIMINFO_H

#pragma once
#include <types.hpp>

class DllImport PVWAlphaShortAnimInfo {
public:
    class PVWAlphaShortAnimInfo& operator=(class PVWAlphaShortAnimInfo const&);
    void extract(float, class ShortColour&);
};

#endif
