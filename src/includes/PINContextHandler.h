#ifndef PINCONTEXTHANDLER_H
#define PINCONTEXTHANDLER_H

#include <cstdint>

#include "pin.H"

#include "ContextHandler.h"
#include "Registers.h"


class PINContextHandler: public ContextHandler {
  public:
    PINContextHandler(CONTEXT *ctx, THREADID threadId);

    __uint128_t getMemValue(uint64_t mem, uint32_t readSize) const;
    __uint128_t getSSERegisterValue(uint64_t regID) const;
    uint32_t    getThreadID(void) const;
    uint64_t    getFlagValue(uint64_t TritFlagID) const;
    uint64_t    getRegisterValue(uint64_t regID) const;
    void        *getCtx(void) const;
    void        setMemValue(uint64_t mem, uint32_t readSize, __uint128_t value) const;
    void        setRegisterValue(uint64_t TritRegID, uint64_t value) const;
    void        setSSERegisterValue(uint64_t TritRegID, __uint128_t value) const;

  private:
    CONTEXT   *_ctx;
    THREADID  _threadId;
};

#endif // PINCONTEXTHANDLER_H
