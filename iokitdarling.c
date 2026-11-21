/*
 * Copyright (C) 2026 Lubos Dolezel
 *
 * Client side of the requests in iokitdarling.defs, for the architecture
 * being built.
 */
#if __LP64__
#   define mig_external __private_extern__
#   include "iokitdarling64.c"
#else
#   include "iokitdarling32.c"
#endif
