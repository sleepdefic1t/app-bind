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

#ifndef BND_OPERATIONS_TRANSACTIONS_ASSETS_TYPES_H
#define BND_OPERATIONS_TRANSACTIONS_ASSETS_TYPES_H

////////////////////////////////////////////////////////////////////////////////
// Compendia Transaction Types
enum TransactionTypes {
    TRANSFER_TYPE                   = 0,
/*  SECOND_SIGNATURE_TYPE           = 1, */
/*  DELEGATE_REGISTRATION_TYPE      = 2, */
    VOTE_TYPE                       = 3,
    MULTI_SIG_REGISTRATION_TYPE     = 4,
    IPFS_TYPE                       = 5,
/*  MULTI_PAYMENT_TYPE              = 6, */
/*  DELEGATE_RESIGNATION_TYPE       = 7, */
    HTLC_LOCK_TYPE                  = 8,
    HTLC_CLAIM_TYPE                 = 9,
    HTLC_REFUND_TYPE                = 10
};

////////////////////////////////////////////////////////////////////////////////
// Compendia Stake Transaction Types
enum StakeTransactionTypes {
    STAKE_CREATE                    = 0,
    STAKE_REDEEM                    = 1,
    STAKE_CANCEL                    = 2,
    STAKE_EXTEND                    = 3,
};

#endif  // BND_OPERATIONS_TRANSACTIONS_ASSETS_TYPES_H
