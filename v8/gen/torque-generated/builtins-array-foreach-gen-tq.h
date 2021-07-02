#ifndef V8_GEN_TORQUE_GENERATED_ARRAY_FOREACH_NAMESPACE_TQ_H_
#define V8_GEN_TORQUE_GENERATED_ARRAY_FOREACH_NAMESPACE_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

compiler::TNode<Object> FastArrayForEach_7(compiler::CodeAssemblerState* state_, compiler::TNode<Context> p_context, compiler::TNode<JSReceiver> p_o, compiler::TNode<Number> p_len, compiler::TNode<JSReceiver> p_callbackfn, compiler::TNode<Object> p_thisArg, compiler::CodeAssemblerLabel* label_Bailout, compiler::TypedCodeAssemblerVariable<Smi>* label_Bailout_parameter_0);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_ARRAY_FOREACH_NAMESPACE_V8_H_
