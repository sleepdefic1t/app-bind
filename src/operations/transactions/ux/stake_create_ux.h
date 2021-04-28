/*******************************************************************************
 * This file is part of the Compendia Ledger App.
 *
 * Copyright (c) ARK Ecosystem <info@ark.io>
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

#ifndef BND_OPERATIONS_TRANSACTIONS_UX_STAKE_CREATE_UX_H
#define BND_OPERATIONS_TRANSACTIONS_UX_STAKE_CREATE_UX_H

#include <stddef.h>

#include "operations/transactions/transaction.h"

////////////////////////////////////////////////////////////////////////////////
static const char *const UX_STAKE_CREATE_LABEL  = "Create Stake";
static const char *const UX_LABEL_TIMESTAMP     = "Timestamp";

static const size_t UX_STAKE_CREATE_STEPS       = 5U;

////////////////////////////////////////////////////////////////////////////////
void SetUxStakeCreate(const Transaction *transaction);

#endif  // #define BND_OPERATIONS_TRANSACTIONS_UX_STAKE_CREATE_UX_H