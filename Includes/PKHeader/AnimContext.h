#ifndef _ANIMCONTEXT_H
#define _ANIMCONTEXT_H

#pragma once
#include <types.hpp>
#include <PKHeader/AnimData.h>

class DllImport AnimContext {
public:
    AnimContext(class AnimContext const&);
    AnimContext(class AnimData*);
    AnimContext(void);
    class AnimContext& operator=(class AnimContext const&);
    void setState(class AnimData*, float);

    virtual void animate(float);

    AnimData* m_animData0; // _00
    AnimData* m_state;     // _04
    f32 m_frame;           // _08 defaults to 30
};

#endif
