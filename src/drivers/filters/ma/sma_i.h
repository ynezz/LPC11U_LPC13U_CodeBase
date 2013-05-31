/**************************************************************************/
/*!
    @file     ringbuffer.h
    @author   Nguyen Quang Huy, Nguyen Thien Tin

    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2013, K. Townsend (microBuilder.eu)
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holders nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/**************************************************************************/
#ifndef __SMA_I_H__
#define __SMA_I_H__

#ifdef __cplusplus
extern "C" {
#endif

#define CFG_USE_REFERENCE     /**< Configuration for using ringbuffer_ref() function                  */

#include "projectconfig.h"
#include "drivers/filters/ringbuffer.h"

typedef struct sma_i_s
{
  uint32_t      k;            /**< Total number of samples that have been run through the filter      */
  uint16_t      size;         /**< Window size (number of samples to average)                         */
  bool          isPowerOf2;   /**< True if the filter uses ^2 window size                             */
  int16_t       power_num;    /**< The exponential number in the case isPowerOf2 true                 */
  int32_t       avg;          /**< Current average                                                    */
  ringbuffer_t* rBuffer;      /**< Pointer to the circular buffer (size=window)                       */
  int64_t       total;        /**< Total value of current window (use int64 for overflow prevention)  */
} sma_i_t;

error_t sma_i_init ( sma_i_t *sma );
void    sma_i_add  ( sma_i_t *sma, int32_t x );

#ifdef __cplusplus
}
#endif

#endif /* __SMA_I_H__ */
