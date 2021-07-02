#ifndef V8_GEN_TORQUE_GENERATED_TYPED_ARRAY_SLICE_NAMESPACE_TQ_H_
#define V8_GEN_TORQUE_GENERATED_TYPED_ARRAY_SLICE_NAMESPACE_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

  const char* kBuiltinName_312(compiler::CodeAssemblerState* state_);
void FastCopy_313(compiler::CodeAssemblerState* state_, compiler::TNode<JSTypedArray> p_src, compiler::TNode<JSTypedArray> p_dest, compiler::TNode<IntPtrT> p_k, compiler::TNode<Smi> p_count, compiler::CodeAssemblerLabel* label_IfSlow);
void SlowCopy_314(compiler::CodeAssemblerState* state_, compiler::TNode<Context> p_context, compiler::TNode<JSTypedArray> p_src, compiler::TNode<JSTypedArray> p_dest, compiler::TNode<IntPtrT> p_k, compiler::TNode<IntPtrT> p_final);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_TYPED_ARRAY_SLICE_NAMESPACE_V8_H_
