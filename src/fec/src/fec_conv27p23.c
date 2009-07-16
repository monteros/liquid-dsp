/*
 * Copyright (c) 2007, 2009 Joseph Gaeddert
 * Copyright (c) 2007, 2009 Virginia Polytechnic Institute & State University
 *
 * This file is part of liquid.
 *
 * liquid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * liquid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with liquid.  If not, see <http://www.gnu.org/licenses/>.
 */

//
// 2/3-rate K=7 punctured convolutional code
//

#include "liquid.internal.h"

#define FEC_CONV(name)      LIQUID_CONCAT(fec_conv27p23,name)
#define create_viterbi      create_viterbi27
#define init_viterbi        init_viterbi27
#define update_viterbi_blk  update_viterbi27_blk
#define chainback_viterbi   chainback_viterbi27
#define delete_viterbi      delete_viterbi27

#define fec_conv27p23_R     (2)
#define fec_conv27p23_K     (7)
#define fec_conv27p23_mode  FEC_CONV_V27P23
#define fec_conv27p23_P     (2)

#if HAVE_FEC_H  // (config.h)
#  include "fec.h"
#else
#  define V27POLYA  (0x00)
#  define V27POLYB  (0x00)
#endif  // HAVE_FEC_H (config.h)

const int FEC_CONV(_poly)[FEC_CONV(_R)] = {V27POLYA,
                                           V27POLYB};

// puncturing matrix : 
const int FEC_CONV(_puncturing_matrix)[FEC_CONV(_P)][FEC_CONV(_R)] = {
    {1, 1},
    {1, 0}
};

#include "fec_conv.punctured.macro.c"

