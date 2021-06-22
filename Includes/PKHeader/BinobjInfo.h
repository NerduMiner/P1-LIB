#ifndef _BINOBJINFO_H
#define _BINOBJINFO_H

#pragma once
#include <PKHeader/GfxobjInfo.h>
#include <types.hpp>

class DllImport BinobjInfo : public GfxobjInfo {
public:
    BinobjInfo(class BinobjInfo const&);
    BinobjInfo(void);
    class BinobjInfo& operator=(class BinobjInfo const&);

    u32 m_dword20; // _20
};

#endif
