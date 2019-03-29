// Copyright (c) 2014 The Bitcoin Core developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers 
// Copyright (c) 2015-2017 The ALQO developers
// Copyright (c) 2017-2018 The cobrax developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "primitives/transaction.h"
#include "main.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(main_tests)

CAmount nMoneySupplyPoWEnd = 41769651 * COIN;

BOOST_AUTO_TEST_CASE(subsidy_limit_test)
{
    CAmount nSum = 0;
    for (int nHeight = 0; nHeight < 1; nHeight += 1) {
        /* premine in block 1 */
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 315000 * COIN);
        nSum += nSubsidy;
    }
    for (int nHeight = 1; nHeight < 3600; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 2 * COIN);
        nSum += nSubsidy;
    }
    for (int nHeight = 3600; nHeight < 15000; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 20 * COIN);
        nSum += nSubsidy;
    }
    for (int nHeight = 15000; nHeight < 262800; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 20 * COIN);
        nSum += nSubsidy;
    }
	for (int nHeight = 262800; nHeight < 525601; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 10 * COIN);
        nSum += nSubsidy;
    }
	for (int nHeight = 525601; nHeight < 788401; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 5 * COIN);
        nSum += nSubsidy;
    }
	for (int nHeight = 788401; nHeight < 1051201; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 2.5 * COIN);
        nSum += nSubsidy;
    }
	for (int nHeight = 1051201; nHeight < 1314001; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 1.25 * COIN);
        nSum += nSubsidy;
    }
	for (int nHeight = 1314001; nHeight < 1576800; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 0.625 * COIN);
        nSum += nSubsidy;
    }
    for (int nHeight = 1576800; nHeight < 1839600; nHeight += 1) {
        CAmount nSubsidy = GetBlockValue(nHeight);
        BOOST_CHECK(nSubsidy <= 0.3125 * COIN);
        nSum += nSubsidy;
    }
	
	BOOST_CHECK(nSum > 0 && nSum <= nMoneySupplyPoWEnd);
}

BOOST_AUTO_TEST_SUITE_END()
