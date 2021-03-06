/***************************************************************************
 *
 * Copyright (C) 2007 - 2012, Rogvall Invest AB, <tony@rogvall.se>
 *
 * This software is licensed as described in the file COPYRIGHT, which
 * you should have received as part of this distribution. The terms
 * are also available at http://www.rogvall.se/docs/copyright.txt.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYRIGHT file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/
#ifndef __EPX_DEBUG_H__
#define __EPX_DEBUG_H__

#include <stdarg.h>

extern void epx_emit_error(char* file, int line, ...);
extern void epx_debug(int mask);

extern int  epx_debug_mask;

#define EPX_DBG_ALL    0xFFFF
#define EPX_DBG_INFO   0x0001
#define EPX_DBG_WARN   0x0010  // emit warnings
#define EPX_DBG_MEM    0x4000  // detailed memory debug

#if defined(debug) || defined(DEBUG)
#define EPX_DBG_IS_SET(flags) ((epx_debug_mask & (flags)) == (flags))
#define EPX_DBGFMT_mask(mask,...)					\
    do {								\
	if (EPX_DBG_IS_SET((mask)))					\
	    epx_emit_error(__FILE__, __LINE__, __VA_ARGS__);		\
    } while(0)
#else
#define EPX_DBG_IS_SET(flags) 0
#define EPX_DBGFMT_mask(mask,...)
#endif

#define EPX_DBGFMT(...)      EPX_DBGFMT_mask(EPX_DBG_INFO,__VA_ARGS__)
#define EPX_DBGFMT_MEM(...)  EPX_DBGFMT_mask(EPX_DBG_MEM,__VA_ARGS__)
#define EPX_DBGFMT_WARN(...) EPX_DBGFMT_mask(EPX_DBG_WARN,__VA_ARGS__)

#endif

