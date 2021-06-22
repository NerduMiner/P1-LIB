#ifndef _SYSTEM_H
#define _SYSTEM_H

#pragma once
#include <PKHeader/AtxDirectRouter.h>
#include <PKHeader/AtxFileStream.h>
#include <PKHeader/BufferedStream.h>
#include <PKHeader/ControllerMgr.h>
#include <PKHeader/StdSystem.h>
#include <types.hpp>

template <typename T, typename B>
class IDelegate2 {
};

class DllImport System : public StdSystem {
public:
    System(class System const&);
    System(void);
    ~System(void);
    class System& operator=(class System const&);
    void beginRender(void);
    void buildModeList(void);
    class UIWindow* createDebugStream(class UIWindow*);
    class RandomAccessStream* createFile(char*, bool);
    void doneRender(void);
    class BaseApp* firstApp(void);
    void genAge(class AgeServer&);
    class AtxRouter* getAtxRouter(void);
    __int32 getFrameCount(void);
    float getFrameRate(void);
    float getFrameTime(void);
    float getTime(void);
    static void halt(char*, int, char*);
    void hardReset(void);
    int run(class BaseApp*);
    void searchFiles(char*, char*, class IDelegate2<char*, unsigned __int32>*, bool);
    void setAtxRouter(class AtxRouter*);
    int setStreamType(int);
    bool setVideoMode(bool, int, int, int);
    void sleep(float);
    void updateSysClock(void);
    void waitRetrace(void);

    virtual class RandomAccessStream* openFile(char*, bool, bool);
    virtual void sndPlaySe(unsigned __int32);

    struct DisplayMode {
        s16 m_dmPelsWidth;      // _00
        s16 m_dmPelsHeight;     // _02
        s16 m_dmPelsBitsPerPel; // _04
    };

    DisplayMode* m_displayMode;         // _244
    s32 m_dispModeCount;                // _248 display modes
    u8 m_byte24C;                       // _24C
    u8 m_byte24D;                       // _24D
    u8 m_byte24E;                       // _24E
    u8 m_dword250;                      // _250
    u32 m_videoMode;                    // _254
    u32 m_dword258;                     // _258
    void* m_sysHeapMem;                 // _25C
    s32 m_sysHeapSize;                  // _260 0x5000000
    AtxFileStream m_fileStream264;      // _264
    BufferedStream m_bufferedStream284; // _284
    u32 m_streamType;                   // _2B0
    ControllerMgr m_controllerMgr;      // _2B4
    u8 m_hostName[0x80];                // _3B8
    AtxDirectRouter* m_router;          // _438
    u32 m_dword43C;                     // _43C
    u32 m_dword440;                     // _440
    u32 m_dword444;                     // _444
    u32 m_dword448;                     // _448
    u32 m_dword44C;                     // _44C
    u32 m_dword450;                     // _450
    u32 m_dword454;                     // _454
    f32 m_frameTime;                    // _458
    f32 m_frameRate;                    // _45C
    u32 m_dword460;                     // _460
    u32 m_dword464;                     // _464
    u32 m_frameCount;                   // _468
};

extern DllImport System* gsys;
System UNUSED_SYSTEM_INSTANCE; // USED TO INITIALISE GSYS

#endif
