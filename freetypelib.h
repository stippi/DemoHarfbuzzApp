/* 
 * The MIT License (MIT)
 * 
 * Copyright 2017, Deepanshu Goyal
 * Copyright 2016, tangrams
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H

#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

typedef struct {
	unsigned char* buffer;
	unsigned int width;
	unsigned int height;
	float bearing_x;
	float bearing_y;
} Glyph;

class FreeTypeLib {
public:
	FreeTypeLib();
	~FreeTypeLib();

	FT_Face* loadFace(const string& fontName, int ptSize, int deviceHDPI, int deviceVDPI);
	void freeFace(FT_Face* face);
	Glyph* rasterize(FT_Face* face, uint32_t glyphIndex) const;
	void freeGlyph(Glyph* glyph);

private:
	FT_Library lib;
	int force_ucs2_charmap(FT_Face ftf);
};
