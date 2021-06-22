#ifndef _MATOBJINFO_H
#define _MATOBJINFO_H

#pragma once
#include <PKHeader/GfxobjInfo.h>
#include <PKHeader/Material.h>
#include <types.hpp>

class DllImport MatobjInfo : public GfxobjInfo {
public:
    MatobjInfo(class MatobjInfo const&);
    MatobjInfo(void);
    class MatobjInfo& operator=(class MatobjInfo const&);
    virtual void attach(void);
    virtual void detach(void);

    Material* m_obj; // _20
};

#endif
