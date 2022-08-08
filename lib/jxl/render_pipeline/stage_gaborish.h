// Copyright (c) the JPEG XL Project Authors.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

#ifndef LIB_JXL_RENDER_PIPELINE_STAGE_GABORISH_H_
#define LIB_JXL_RENDER_PIPELINE_STAGE_GABORISH_H_
#include <math.h>
#include <stdint.h>
#include <stdio.h>

#include <algorithm>
#include <utility>
#include <vector>

#include "lib/jxl/loop_filter.h"
#include "lib/jxl/render_pipeline/render_pipeline_stage.h"

namespace jxl {

// Applies decoder-side Gaborish with the given settings. `lf.gab` must be 1.
std::unique_ptr<RenderPipelineStage> GetGaborishStage(const LoopFilter& lf);
}  // namespace jxl

#endif  // LIB_JXL_RENDER_PIPELINE_STAGE_GABORISH_H_
