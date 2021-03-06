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

#ifndef AVPP_DICTIONARY_H
#define AVPP_DICTIONARY_H

#include "avpp_global.h"

namespace avpp {

class AVPP_EXPORT DictionaryPrivate;
class AVPP_EXPORT Dictionary
{
public:

    enum {
        MatchCase,
        IgnoreSuffix,
        DontOverwrite,
        Append
    };

    /**
     * @brief Create an empty dictionary
     */
    Dictionary();

    /**
     * @brief Copy constructor
     */
    Dictionary(const Dictionary &rhs);

    /**
     * @brief Destroy the dictionary
     */
    ~Dictionary();

    /**
     * @brief Retrieve the number of items in the dictionary
     */
    int count() const;

    /**
     * @brief Set the specified key to the specified value
     */
    void set(const char *key, const char *value, int flags = 0);

private:

    DictionaryPrivate *const d;

    friend class FormatContext;
};

}

#endif // AVPP_DICTIONARY_H
