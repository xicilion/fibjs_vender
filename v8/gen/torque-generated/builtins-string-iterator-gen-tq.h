#ifndef V8_GEN_TORQUE_GENERATED_STRING_ITERATOR_NAMESPACE_TQ_H_
#define V8_GEN_TORQUE_GENERATED_STRING_ITERATOR_NAMESPACE_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

compiler::TNode<JSStringIterator> NewJSStringIterator_286(compiler::CodeAssemblerState* state_, compiler::TNode<Context> p_context, compiler::TNode<String> p_string, compiler::TNode<Smi> p_nextIndex);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_STRING_ITERATOR_NAMESPACE_V8_H_
