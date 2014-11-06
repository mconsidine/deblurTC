/* $Id$
 *
 *  (C) 2003-2007, Friedrich Woeger <woeger@kis.uni-freiburg.de>,
 *  Kiepenheuer-Institut f??r Sonnenphysik, Freiburg (Breisgau), Germany
 *  All rights reserved.
 *  
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 *  
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of the Kiepenheuer-Institut nor the
 *     names of its contributors may be used to endorse or promote
 *     products derived from this software without specific prior
 *     written permission.
 *  
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */


/*	=====================================================================
**
**	core speckle routines
**
**	=====================================================================
**
**	uses:		fftw3 library:
**			http://www.fftw.org
**
**			Library for fast fourier transform
**
**	=====================================================================
**
**	Author:		F. Woeger
**			Kiepenheuer-Institut fuer Sonnenphysik
**			Freiburg, Germany
**
**	Written 17. 06. 2003
**
**	=====================================================================
*/

#ifndef KISIP_SPECKLE_CORE_H
#define KISIP_SPECKLE_CORE_H

#include <fftw3.h>
#include <stdlib.h>
#include <math.h>
#include "inlines.h"
#include "speckle_math.h"
#include "speckle_admin.h"

#ifndef MEMCHUNK
#define MEMCHUNK 10000
#endif

float chkphase(slaveinfo l, float *phs);

void init_shift(int nxh, int nyh, int len, int *maxk, int **shifts);

void phs_init(float *p1, float *p2, float *pc, slaveinfo l, int maxk,
	      int *shifts, float *origin);
long *bs_init(long *bs_cnt, slaveinfo l);
float *bs_ave(float *images, float *win, slaveinfo l, long *index,
	      long bs_cnt, float *bsc, float *wc, float *amp, int maxk,
	      int *shifts);
void bs_snrt(float *wc, long bs_cnt, slaveinfo * l);
void bs_red(long *index, long bs_cnt, slaveinfo l, float *bsc, float *wc,
	    float **bs, float **w);
void iwlspr(float *p1, float *p2, float *pc, float *bsc, float *wc,
	    long *index, long bs_cnt, slaveinfo l, int maxk);
void rpr(float *p1, float *p2, float *pc, long *index, long bs_cnt,
	 float *bsc, float *wc, slaveinfo l);

void assemble(int nx, int ny, float *amp, float *phs, float *rec, maininfo info);

#endif				/*      KISIP_SPECKLE_CORE      */
