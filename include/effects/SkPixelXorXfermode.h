/*
 * Copyright 2007 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkPixelXorXfermode_DEFINED
#define SkPixelXorXfermode_DEFINED

#include "SkXfermode.h"

/** SkPixelXorXfermode implements a simple pixel xor (op ^ src ^ dst).
    This transformation does not follow premultiplied conventions, therefore
    this proc *always* returns an opaque color (alpha == 255). Thus it is
    not really usefull for operating on blended colors.
*/
class SK_API SkPixelXorXfermode : public SkXfermode {
public:
    static SkPixelXorXfermode* Create(SkColor opColor) {
        return SkNEW_ARGS(SkPixelXorXfermode, (opColor));
    }

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkPixelXorXfermode)

protected:
    explicit SkPixelXorXfermode(SkColor opColor) : fOpColor(opColor) {}
    void flatten(SkWriteBuffer&) const override;

    // override from SkXfermode
    SkPMColor xferColor(SkPMColor src, SkPMColor dst) const override;

private:
    SkColor fOpColor;

    typedef SkXfermode INHERITED;
};

#endif
