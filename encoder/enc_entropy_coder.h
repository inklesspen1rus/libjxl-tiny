// Copyright (c) the JPEG XL Project Authors.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

#ifndef ENCODER_ENC_ENTROPY_CODER_H_
#define ENCODER_ENC_ENTROPY_CODER_H_

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include <memory>
#include <utility>
#include <vector>

#include "encoder/enc_ans.h"
#include "lib/jxl/ac_context.h"  // BlockCtxMap
#include "lib/jxl/ac_strategy.h"
#include "lib/jxl/field_encodings.h"
#include "lib/jxl/frame_header.h"  // YCbCrChromaSubsampling
#include "lib/jxl/image.h"

// Entropy coding and context modeling of DC and AC coefficients, as well as AC
// strategy and quantization field.

namespace jxl {

// Generate DCT NxN quantized AC values tokens.
// Only the subset "rect" [in units of blocks] within all images.
// See also DecodeACVarBlock.
void TokenizeCoefficients(const coeff_order_t* JXL_RESTRICT orders,
                          const Rect& rect,
                          const int32_t* JXL_RESTRICT* JXL_RESTRICT ac_rows,
                          const AcStrategyImage& ac_strategy,
                          YCbCrChromaSubsampling cs,
                          Image3I* JXL_RESTRICT tmp_num_nzeroes,
                          std::vector<Token>* JXL_RESTRICT output);

}  // namespace jxl

#endif  // ENCODER_ENC_ENTROPY_CODER_H_
