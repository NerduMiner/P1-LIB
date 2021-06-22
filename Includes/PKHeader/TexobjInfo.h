#ifndef _TEXOBJINFO_H
#define _TEXOBJINFO_H

#pragma once
#include <PKHeader/GfxobjInfo.h>
#include <PKHeader/Texture.h>
#include <types.hpp>

class DllImport TexobjInfo : public GfxobjInfo {
public:
    TexobjInfo(class TexobjInfo const&);
    TexobjInfo(void);
    class TexobjInfo& operator=(class TexobjInfo const&);
    virtual void attach(void);
    virtual void detach(void);

    Texture* m_obj; // _20
};

#endif
