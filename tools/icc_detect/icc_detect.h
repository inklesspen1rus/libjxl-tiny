// Copyright (c) the JPEG XL Project Authors.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

#ifndef TOOLS_ICC_DETECT_ICC_DETECT_H_
#define TOOLS_ICC_DETECT_ICC_DETECT_H_

#include <QByteArray>
#include <QWidget>

namespace jxl {

// Should be cached if possible.
QByteArray GetMonitorIccProfile(const QWidget* widget);

}  // namespace jxl

#endif  // TOOLS_ICC_DETECT_ICC_DETECT_H_
