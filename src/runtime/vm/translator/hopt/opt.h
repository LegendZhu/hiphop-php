/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010- Facebook, Inc. (http://www.facebook.com)         |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/
#ifndef incl_HHIR_OPT_H_
#define incl_HHIR_OPT_H_

namespace HPHP { namespace VM { namespace JIT {

class Trace;
class IRFactory;
class IRInstruction;

/*
 * These flags are used by eliminateDeadCode and optimizeMemoryAccesses(),
 * hence they're declared here.
 *
 * An IncRef is marked as REFCOUNT_CONSUMED[_OFF_TRACE], if it is consumed by
 * an instruction other than DecRefNZ that decrements the ref count.
 * REFCOUNT_CONSUMED: consumed by such an instruction in the main trace.
 * REFCOUNT_CONSUMED_OFF_TRACE: consumed by such an instruction only in exits.
 */
enum DceFlags {
  DEAD,
  LIVE,
  REFCOUNT_CONSUMED,
  REFCOUNT_CONSUMED_OFF_TRACE
};

/*
 * The main optimization passes, in the order they run.
 */
void optimizeMemoryAccesses(Trace*, IRFactory*);
void eliminateDeadCode(Trace*, IRFactory*);
void optimizeJumps(Trace*, IRFactory*);

/*
 * Run all the optimization passes.
 */
void optimizeTrace(Trace*, IRFactory*);

}}}

#endif
