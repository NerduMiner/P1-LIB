#ifndef _FNTOBJINFO_H
#define _FNTOBJINFO_H

#pragma once
#include <types.hpp>
#include <PKHeader/Font.h>
#include <PKHeader/GfxobjInfo.h>

class DllImport FntobjInfo : public GfxobjInfo {
public:
    FntobjInfo(class FntobjInfo const&);
    FntobjInfo(void);
    class FntobjInfo& operator=(class FntobjInfo const&);

    Font* m_obj; // _20
};

#endif
