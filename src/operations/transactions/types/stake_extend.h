/*******************************************************************************
 * This file is part of the Compendia Ledger App.
 *
 * Copyright (c) nOS Limited <contact@nos.io>
 *
 * The MIT License (MIT)
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
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

#ifndef BND_OPERATIONS_TRANSACTIONS_TYPES_STAKE_EXTEND_H
#define BND_OPERATIONS_TRANSACTIONS_TYPES_STAKE_EXTEND_H

#include <stddef.h>
#include <stdint.h>

#include "constants.h"

////////////////////////////////////////////////////////////////////////////////
static const size_t TRANSACTION_TYPE_STAKE_EXTEND_SIZE = 73ULL;

////////////////////////////////////////////////////////////////////////////////
typedef struct stake_extend_asset_t {
    uint8_t  id[HASH_64_LEN];
    uint64_t duration;
} StakeExtend;

////////////////////////////////////////////////////////////////////////////////
size_t deserializeStakeExtend(StakeExtend *extend, const uint8_t *buffer, size_t size);

#endif  // BND_OPERATIONS_TRANSACTIONS_TYPES_STAKE_EXTEND_H
