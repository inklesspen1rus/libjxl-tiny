// Copyright (c) the JPEG XL Project Authors.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

#ifndef LIB_EXTRAS_ENC_PNM_H_
#define LIB_EXTRAS_ENC_PNM_H_

// Encodes/decodes PBM/PGM/PPM/PFM pixels in memory.

// TODO(janwas): workaround for incorrect Win64 codegen (cause unknown)
#include <hwy/highway.h>
#include <memory>

#include "lib/extras/enc/encode.h"

namespace jxl {
namespace extras {

std::unique_ptr<Encoder> GetPAMEncoder();
std::unique_ptr<Encoder> GetPGMEncoder();
std::unique_ptr<Encoder> GetPPMEncoder();
std::unique_ptr<Encoder> GetPFMEncoder();

}  // namespace extras
}  // namespace jxl

#endif  // LIB_EXTRAS_ENC_PNM_H_
