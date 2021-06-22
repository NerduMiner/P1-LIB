#ifndef _PVWTEXANIMINFO_H
#define _PVWTEXANIMINFO_H

#pragma once
#include <types.hpp>

class DllImport PVWTexAnimInfo {
public:
    class PVWTexAnimInfo& operator=(class PVWTexAnimInfo const&);
    void extract(float, class Vector3f&);
};

#endif
