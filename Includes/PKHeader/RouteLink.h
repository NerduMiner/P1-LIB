#ifndef _ROUTELINK_H
#define _ROUTELINK_H

#pragma once
#include <PKHeader/CoreNode.h>
#include <PKHeader/RoutePoint.h>
#include <types.hpp>

class DllImport RouteLink : public CoreNode {
public:
    RouteLink(class RouteLink const&);
    RouteLink(void);
    class RouteLink& operator=(class RouteLink const&);

    class RoutePoint* m_other; // _14
};

#endif
