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

#include "transactions/ux/stake_create_ux.h"

#include "constants.h"

#include "operations/transactions/transaction.h"

#include "utils/base58.h"
#include "utils/print.h"
#include "utils/str.h"

#include "display/context.h"

////////////////////////////////////////////////////////////////////////////////
void SetUxStakeCreate(const Transaction *transaction) {
    SPRINTF(displayCtx.operation, "%s", UX_STAKE_CREATE_LABEL);
    SPRINTF(displayCtx.title[0], "%s:", UX_LABEL_RECIPIENT);
    SPRINTF(displayCtx.title[1], "%s:", UX_LABEL_AMOUNT);
    SPRINTF(displayCtx.title[2], "%s:", UX_LABEL_STAKE_DUR);
    SPRINTF(displayCtx.title[3], "%s:", UX_LABEL_TIMESTAMP);
    SPRINTF(displayCtx.title[4], "%s:", UX_LABEL_FEE);

    // Stake Recipient
    Base58CheckEncode(transaction->asset.stakeCreate.recipientId,
                      ADDRESS_HASH_LEN,
                      displayCtx.text[0], sizeof(displayCtx.text[0]));

    // Amount
    TokenAmountToString(TOKEN_NAME, TOKEN_NAME_LEN, TOKEN_DECIMALS,
                        transaction->asset.stakeCreate.amount,
                        displayCtx.text[1], sizeof(displayCtx.text[1]));

    // Duration
    UintToString(transaction->asset.stakeCreate.duration,
                 displayCtx.text[2], sizeof(displayCtx.text[2]));

    // Timestamp
    UintToString(transaction->asset.stakeCreate.timestamp,
                 displayCtx.text[3], sizeof(displayCtx.text[3]));

    // Fee
    TokenAmountToString(TOKEN_NAME, TOKEN_NAME_LEN, TOKEN_DECIMALS,
                        transaction->fee,
                        displayCtx.text[4], sizeof(displayCtx.text[4]));
}
