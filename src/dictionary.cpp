/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Nathan Osman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include <avpp/dictionary.h>

#include "dictionary_p.h"

using namespace avpp;

DictionaryPrivate::DictionaryPrivate()
    : dictionary(nullptr)
{
}

DictionaryPrivate::~DictionaryPrivate()
{
    if (dictionary) {
        av_dict_free(&dictionary);
    }
}

Dictionary::Dictionary()
    : d(new DictionaryPrivate)
{
}

Dictionary::Dictionary(const Dictionary &rhs)
    : d(new DictionaryPrivate)
{
    av_dict_copy(&d->dictionary, rhs.d->dictionary, 0);
}

Dictionary::~Dictionary()
{
    delete d;
}

int Dictionary::count() const
{
    return av_dict_count(d->dictionary);
}

void Dictionary::set(const char *key, const char *value, int flags)
{
    int convertedFlags = 0;

    if (flags & MatchCase)     convertedFlags |= AV_DICT_MATCH_CASE;
    if (flags & IgnoreSuffix)  convertedFlags |= AV_DICT_IGNORE_SUFFIX;
    if (flags & DontOverwrite) convertedFlags |= AV_DICT_DONT_OVERWRITE;
    if (flags & Append)        convertedFlags |= AV_DICT_APPEND;

    av_dict_set(&d->dictionary, key, value, convertedFlags);
}
