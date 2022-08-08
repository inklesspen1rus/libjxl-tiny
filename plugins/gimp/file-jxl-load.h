// Copyright (c) the JPEG XL Project Authors.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

#ifndef PLUGINS_GIMP_FILE_JXL_LOAD_H_
#define PLUGINS_GIMP_FILE_JXL_LOAD_H_

#include "jxl/decode.h"
#include "jxl/decode_cxx.h"
#include "plugins/gimp/common.h"

namespace jxl {

bool LoadJpegXlImage(const gchar* filename, gint32* image_id);

}  // namespace jxl

#endif  // PLUGINS_GIMP_FILE_JXL_LOAD_H_
