#ifndef _ANMOBJINFO_H
#define _ANMOBJINFO_H

#pragma once
#include <PKHeader/GfxobjInfo.h>
#include <types.hpp>

class DllImport AnmobjInfo : public GfxobjInfo {
public:
    AnmobjInfo(class AnmobjInfo const&);
    AnmobjInfo(void);
    class AnmobjInfo& operator=(class AnmobjInfo const&);
    virtual void detach(void);

    u32 m_dword20; // _20
};

EXPECT_SIZE(AnmobjInfo, 0x24);

#endif
