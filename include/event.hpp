#ifndef _H_EVENT_
#define _H_EVENT_
#include "event_type.hpp"
namespace {
    typedef struct{} event;
    typedef void (*event_handler)(event);
}
#endif