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

#ifndef BND_OPERATIONS_TRANSACTIONS_TYPES_ASSETS_H
#define BND_OPERATIONS_TRANSACTIONS_TYPES_ASSETS_H

#include "transactions/types/transfer.h"
#include "transactions/types/vote.h"
#include "transactions/types/multi_signature.h"
#include "transactions/types/ipfs.h"
#include "transactions/types/htlc_lock.h"
#include "transactions/types/htlc_claim.h"
#include "transactions/types/htlc_refund.h"

#include "transactions/types/stake_create.h"
#include "transactions/types/stake_redeem.h"
#include "transactions/types/stake_cancel.h"
#include "transactions/types/stake_extend.h"

#include "platform.h"

////////////////////////////////////////////////////////////////////////////////
typedef union tx_asset_t {
    // TypeGroup 1: Core
    Transfer                    transfer;               // Type 0
/*  SecondSignatureRegistration secondSignature;        // Type 1 */
/*  Delegate Registration                               // Type 2 */
    Vote                        vote;                   // Type 3
#if defined(SUPPORTS_MULTISIGNATURE)
    MultiSignature              multiSignature;         // Type 4 */
#endif  // SUPPORTS_MULTISIGNATURE
    Ipfs                        ipfs;                   // Type 5
/*  MultiPayment                                        // Type 6 */
/*  Delegate Resignation                                // Type 7 */
    HtlcLock                    htlcLock;               // Type 8
    HtlcClaim                   htlcClaim;              // Type 9
    HtlcRefund                  htlcRefund;             // Type 10

    StakeCreate                 stakeCreate;            // Group 100, Type 0
    StakeRedeem                 stakeRedeem;            // Group 100, Type 1
    StakeCancel                 stakeCancel;            // Group 100, Type 2
    StakeExtend                 stakeExtend;            // Group 100, Type 3
} tx_asset_t;

#endif  // BND_OPERATIONS_TRANSACTIONS_TYPES_ASSETS_H
