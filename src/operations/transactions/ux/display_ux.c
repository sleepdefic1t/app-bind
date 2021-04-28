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

#include "transactions/ux/display_ux.h"

#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#include "platform.h"

#include "transactions/transaction.h"

#include "transactions/types/types.h"

#include "transactions/ux/transfer_ux.h"
#include "transactions/ux/vote_ux.h"
#include "transactions/ux/multi_signature_ux.h"
#include "transactions/ux/ipfs_ux.h"
#include "transactions/ux/htlc_lock_ux.h"
#include "transactions/ux/htlc_claim_ux.h"
#include "transactions/ux/htlc_refund_ux.h"

#include "transactions/ux/stake_create_ux.h"
#include "transactions/ux/stake_redeem_ux.h"
#include "transactions/ux/stake_cancel_ux.h"
#include "transactions/ux/stake_extend_ux.h"

#include "transactions/ux/signatures_ux.h"

#include "display/context.h"
#include "display/display.h"

#include "utils/utils.h"

////////////////////////////////////////////////////////////////////////////////
extern void SetUxDisplay(size_t steps, size_t extendedStep);

////////////////////////////////////////////////////////////////////////////////
static void SetUxCore(const Transaction *transaction) {
    size_t steps = 0U;
    size_t extendedStep = 0U;
    const bool hasVendorField = transaction->vendorFieldLength > 0U;

    if (transaction->typeGroup == TRANSACTION_TYPEGROUP_100) {}
    switch (transaction->type) {
        case TRANSFER_TYPE:
            SetUxTransfer(transaction);
            steps = UX_TRANSFER_STEPS + hasVendorField;
            extendedStep = hasVendorField ? steps : 0U;
            break;

        case VOTE_TYPE:
            SetUxVote(transaction);
            steps = UX_VOTE_BASE_STEPS + transaction->asset.vote.count;
            break;

#if defined(SUPPORTS_MULTISIGNATURE)
        case MULTI_SIG_REGISTRATION_TYPE:
            steps = SetUxMultiSignature(transaction);
            break;
#endif  // SUPPORTS_MULTISIGNATURE

        case IPFS_TYPE:
            SetUxIpfs(transaction);
            steps = UX_IPFS_STEPS;
            extendedStep = steps;
            break;

        case HTLC_LOCK_TYPE:
            SetUxHtlcLock(transaction);
            steps = UX_HTLC_LOCK_STEPS + hasVendorField;
            extendedStep = hasVendorField ? steps : 0U;
            break;

        case HTLC_CLAIM_TYPE:
            SetUxHtlcClaim(transaction);
            steps = UX_HTLC_CLAIM_STEPS;
            break;

        case HTLC_REFUND_TYPE:
            SetUxHtlcRefund(transaction);
            steps = UX_HTLC_REFUND_STEPS;
            break;

        default: break;
    };

#if defined(SUPPORTS_MULTISIGNATURE)
    if (transaction->signatures.count > 0U) {
        steps += SetUxSignatures(transaction, steps);
    }
#endif  // SUPPORTS_MULTISIGNATURE

    SetUxDisplay(steps, extendedStep);
}

static void SetUxCompendiaStake(const Transaction *transaction) {
    size_t steps = 0U;
    const size_t extendedStep = 0U;

    switch (transaction->type) {
        case STAKE_CREATE:
            SetUxStakeCreate(transaction);
            steps = UX_STAKE_CREATE_STEPS;
            break;

        case STAKE_REDEEM:
            SetUxStakeRedeem(transaction);
            steps = UX_STAKE_REDEEM_STEPS;
            break;

        case STAKE_CANCEL:
            SetUxStakeCancel(transaction);
            steps = UX_STAKE_CANCEL_STEPS;
            break;

        case STAKE_EXTEND:
            SetUxStakeExtend(transaction);
            steps = UX_STAKE_EXTEND_STEPS;
            break;

        default: break;
    };

#if defined(SUPPORTS_MULTISIGNATURE)
    if (transaction->signatures.count > 0U) {
        steps += SetUxSignatures(transaction, steps);
    }
#endif  // SUPPORTS_MULTISIGNATURE

    SetUxDisplay(steps, extendedStep);
}

////////////////////////////////////////////////////////////////////////////////
void SetUx(const Transaction *transaction) {
    MEMSET_TYPE_BZERO(&displayCtx, DisplayContext);

    if (transaction->typeGroup == TRANSACTION_TYPEGROUP_100) {
        SetUxCompendiaStake(transaction);
    } else {
        SetUxCore(transaction);
    }
}
