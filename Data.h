#ifndef GK8_DATA_H
#define GK8_DATA_H
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

using Satoshi = uint64_t;
using Address = uint64_t;
//The amount of money created every block and given to the block's miner
#define MONEY_CREATED_FOR_THE_MINER_EACH_BLOCK 1000
#define MAX_ENTRIES_IN_BLOCK 10
#define SIG_LENGTH 32

struct Transaction
{
//creator of transaction and sender of funds
    Address from;
//transaction destination
    Address to;
//amount of money to send to the destination
    Satoshi amount;
//amount of fee is offered by the creator to the miner to add this transaction to the blockchain
    Satoshi fee;
//creation time, written by the transaction creator
    time_t creationTime;
//signing {from,amount,to,fee,creation time}
    uint8_t signature[SIG_LENGTH];
};

struct Block
{
//holds up to 10 transactions
    std::vector<Transaction> trans;
//the miner that added the block to the blockchain
    Address miner;
// the next block at the blockchain (is nullptr for the last block)
    Block * next;
};

#endif //GK8_DATA_H
