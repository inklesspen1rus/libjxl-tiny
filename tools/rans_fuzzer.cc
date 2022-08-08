// Copyright (c) the JPEG XL Project Authors.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

#include "lib/jxl/dec_ans.h"
#include "lib/jxl/entropy_coder.h"

namespace jxl {

int TestOneInput(const uint8_t* data, size_t size) {
  if (size < 2) return 0;
  size_t numContexts = data[0] * 256 * data[1] + 1;
  data += 2;
  size -= 2;

  std::vector<uint8_t> context_map;
  Status ret = true;
  {
    BitReader br(Span<const uint8_t>(data, size));
    BitReaderScopedCloser br_closer(&br, &ret);
    ANSCode code;
    JXL_RETURN_IF_ERROR(
        DecodeHistograms(&br, numContexts, &code, &context_map));
    ANSSymbolReader ansreader(&code, &br);

    // Limit the maximum amount of reads to avoid (valid) infinite loops.
    const size_t maxreads = size * 8;
    size_t numreads = 0;
    int context = 0;
    while (DivCeil(br.TotalBitsConsumed(), kBitsPerByte) < size &&
           numreads <= maxreads) {
      int code = ansreader.ReadHybridUint(context, &br, context_map);
      context = code % numContexts;
      numreads++;
    }
  }

  return 0;
}

}  // namespace jxl

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
  return jxl::TestOneInput(data, size);
}
