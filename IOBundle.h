#include <CoreFoundation/CFString.h>

#define CF_DEFINECONSTANTSTRING(name, val) const CFStringRef name = CFSTR(val)

