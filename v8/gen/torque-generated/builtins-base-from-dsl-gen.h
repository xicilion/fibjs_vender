#ifndef V8_TORQUE_BASE_FROM_DSL_BASE_H__
#define V8_TORQUE_BASE_FROM_DSL_BASE_H__

#include "src/compiler/code-assembler.h"

namespace v8 {
namespace internal {

class BaseBuiltinsFromDSLAssembler {
 public:
  explicit BaseBuiltinsFromDSLAssembler(compiler::CodeAssemblerState* state) : state_(state), ca_(state) { USE(state_, ca_); }
  struct _ThisStructHeapObject {
    compiler::TNode<Object> map_untyped;

    std::tuple<compiler::TNode<Object>> Flatten() const {
      return std::tuple_cat(std::make_tuple(map_untyped));
    }
  };
  compiler::TNode<Object> LoadHeapObjectMapUntyped(compiler::TNode<HeapObject> p_o);
  void StoreHeapObjectMapUntyped(compiler::TNode<HeapObject> p_o, compiler::TNode<Object> p_v);
  struct _ThisStructJSReceiver {
    BaseBuiltinsFromDSLAssembler::_ThisStructHeapObject _super;
    compiler::TNode<Object> properties_or_hash;

    std::tuple<compiler::TNode<Object>, compiler::TNode<Object>> Flatten() const {
      return std::tuple_cat(_super.Flatten(), std::make_tuple(properties_or_hash));
    }
  };
  compiler::TNode<Object> LoadJSReceiverPropertiesOrHash(compiler::TNode<JSReceiver> p_o);
  void StoreJSReceiverPropertiesOrHash(compiler::TNode<JSReceiver> p_o, compiler::TNode<Object> p_v);
  struct _ThisStructJSObject {
    BaseBuiltinsFromDSLAssembler::_ThisStructJSReceiver _super;
    compiler::TNode<FixedArrayBase> elements;

    std::tuple<compiler::TNode<Object>, compiler::TNode<Object>, compiler::TNode<FixedArrayBase>> Flatten() const {
      return std::tuple_cat(_super.Flatten(), std::make_tuple(elements));
    }
  };
  compiler::TNode<FixedArrayBase> LoadJSObjectElements(compiler::TNode<JSObject> p_o);
  void StoreJSObjectElements(compiler::TNode<JSObject> p_o, compiler::TNode<FixedArrayBase> p_v);
  struct _ThisStructJSArgumentsObjectWithLength {
    BaseBuiltinsFromDSLAssembler::_ThisStructJSObject _super;
    compiler::TNode<Object> length;

    std::tuple<compiler::TNode<Object>, compiler::TNode<Object>, compiler::TNode<FixedArrayBase>, compiler::TNode<Object>> Flatten() const {
      return std::tuple_cat(_super.Flatten(), std::make_tuple(length));
    }
  };
  compiler::TNode<Object> LoadJSArgumentsObjectWithLengthLength(compiler::TNode<JSArgumentsObjectWithLength> p_o);
  void StoreJSArgumentsObjectWithLengthLength(compiler::TNode<JSArgumentsObjectWithLength> p_o, compiler::TNode<Object> p_v);
  struct _ThisStructJSArray {
    BaseBuiltinsFromDSLAssembler::_ThisStructJSObject _super;
    compiler::TNode<Number> length;

    std::tuple<compiler::TNode<Object>, compiler::TNode<Object>, compiler::TNode<FixedArrayBase>, compiler::TNode<Number>> Flatten() const {
      return std::tuple_cat(_super.Flatten(), std::make_tuple(length));
    }
  };
  compiler::TNode<BoolT> _method_JSArray_IsEmpty(compiler::TNode<JSArray> p_this);
  compiler::TNode<Number> LoadJSArrayLength(compiler::TNode<JSArray> p_o);
  void StoreJSArrayLength(compiler::TNode<JSArray> p_o, compiler::TNode<Number> p_v);
  struct _ThisStructJSFunction {
    BaseBuiltinsFromDSLAssembler::_ThisStructJSObject _super;
    compiler::TNode<SharedFunctionInfo> shared_function_info;
    compiler::TNode<Context> context;
    compiler::TNode<Smi> feedback_cell;
    compiler::TNode<Code> code;
    compiler::TNode<HeapObject> prototype_or_initial_map;

    std::tuple<compiler::TNode<Object>, compiler::TNode<Object>, compiler::TNode<FixedArrayBase>, compiler::TNode<SharedFunctionInfo>, compiler::TNode<Context>, compiler::TNode<Smi>, compiler::TNode<Code>, compiler::TNode<HeapObject>> Flatten() const {
      return std::tuple_cat(_super.Flatten(), std::make_tuple(shared_function_info), std::make_tuple(context), std::make_tuple(feedback_cell), std::make_tuple(code), std::make_tuple(prototype_or_initial_map));
    }
  };
  compiler::TNode<SharedFunctionInfo> LoadJSFunctionSharedFunctionInfo(compiler::TNode<JSFunction> p_o);
  void StoreJSFunctionSharedFunctionInfo(compiler::TNode<JSFunction> p_o, compiler::TNode<SharedFunctionInfo> p_v);
  compiler::TNode<Context> LoadJSFunctionContext(compiler::TNode<JSFunction> p_o);
  void StoreJSFunctionContext(compiler::TNode<JSFunction> p_o, compiler::TNode<Context> p_v);
  compiler::TNode<Smi> LoadJSFunctionFeedbackCell(compiler::TNode<JSFunction> p_o);
  void StoreJSFunctionFeedbackCell(compiler::TNode<JSFunction> p_o, compiler::TNode<Smi> p_v);
  compiler::TNode<Code> LoadJSFunctionCode(compiler::TNode<JSFunction> p_o);
  void StoreJSFunctionCode(compiler::TNode<JSFunction> p_o, compiler::TNode<Code> p_v);
  compiler::TNode<HeapObject> LoadJSFunctionPrototypeOrInitialMap(compiler::TNode<JSFunction> p_o);
  void StoreJSFunctionPrototypeOrInitialMap(compiler::TNode<JSFunction> p_o, compiler::TNode<HeapObject> p_v);
  struct _ThisStructJSBoundFunction {
    BaseBuiltinsFromDSLAssembler::_ThisStructJSObject _super;
    compiler::TNode<JSReceiver> bound_target_function;
    compiler::TNode<Object> bound_this;
    compiler::TNode<FixedArray> bound_arguments;

    std::tuple<compiler::TNode<Object>, compiler::TNode<Object>, compiler::TNode<FixedArrayBase>, compiler::TNode<JSReceiver>, compiler::TNode<Object>, compiler::TNode<FixedArray>> Flatten() const {
      return std::tuple_cat(_super.Flatten(), std::make_tuple(bound_target_function), std::make_tuple(bound_this), std::make_tuple(bound_arguments));
    }
  };
  compiler::TNode<JSReceiver> LoadJSBoundFunctionBoundTargetFunction(compiler::TNode<JSBoundFunction> p_o);
  void StoreJSBoundFunctionBoundTargetFunction(compiler::TNode<JSBoundFunction> p_o, compiler::TNode<JSReceiver> p_v);
  compiler::TNode<Object> LoadJSBoundFunctionBoundThis(compiler::TNode<JSBoundFunction> p_o);
  void StoreJSBoundFunctionBoundThis(compiler::TNode<JSBoundFunction> p_o, compiler::TNode<Object> p_v);
  compiler::TNode<FixedArray> LoadJSBoundFunctionBoundArguments(compiler::TNode<JSBoundFunction> p_o);
  void StoreJSBoundFunctionBoundArguments(compiler::TNode<JSBoundFunction> p_o, compiler::TNode<FixedArray> p_v);
  compiler::TNode<Oddball> Hole();
  compiler::TNode<Oddball> Null();
  compiler::TNode<Oddball> Undefined();
  compiler::TNode<Oddball> True();
  compiler::TNode<Oddball> False();
  compiler::TNode<String> kEmptyString();
  compiler::TNode<String> kLengthString();
  compiler::TNode<BoolT> ElementsKindNotEqual(compiler::TNode<Int32T> p_k1, compiler::TNode<Int32T> p_k2);
  compiler::TNode<BoolT> IsNumberEqual(compiler::TNode<Number> p_a, compiler::TNode<Number> p_b);
  compiler::TNode<Number> Min(compiler::TNode<Number> p_x, compiler::TNode<Number> p_y);
  compiler::TNode<Number> Max(compiler::TNode<Number> p_x, compiler::TNode<Number> p_y);
  compiler::TNode<HeapObject> CastHeapObject10HeapObject(compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<FixedArray> CastHeapObject12ATFixedArray(compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<FixedDoubleArray> CastHeapObject18ATFixedDoubleArray(compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<FixedArray> CastHeapObject25ATSloppyArgumentsElements(compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<JSDataView> CastHeapObject12ATJSDataView(compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<JSTypedArray> CastHeapObject14ATJSTypedArray(compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<JSReceiver> CastHeapObject41UT9ATJSProxy15JSBoundFunction10JSFunction(compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<JSArray> CastHeapObject7JSArray(compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<Context> CastHeapObject9ATContext(compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<JSObject> CastHeapObject8JSObject(compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<NumberDictionary> CastHeapObject18ATNumberDictionary(compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<FixedTypedArrayBase> CastHeapObject21ATFixedTypedArrayBase(compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<String> CastHeapObject8ATString(compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<JSReceiver> CastHeapObject13ATConstructor(compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<HeapNumber> CastHeapObject12ATHeapNumber(compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<Map> CastHeapObject5ATMap(compiler::TNode<Context> p_context, compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<JSArgumentsObjectWithLength> CastHeapObject27JSArgumentsObjectWithLength(compiler::TNode<Context> p_context, compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<JSArray> CastHeapObject13ATFastJSArray(compiler::TNode<Context> p_context, compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  struct FastJSArrayWitness {
    compiler::TNode<HeapObject> array;
    compiler::TNode<Map> map;

    std::tuple<compiler::TNode<HeapObject>, compiler::TNode<Map>> Flatten() const {
      return std::tuple_cat(std::make_tuple(array), std::make_tuple(map));
    }
  };
  BaseBuiltinsFromDSLAssembler::FastJSArrayWitness MakeWitness(compiler::TNode<JSArray> p_array);
  compiler::TNode<JSArray> Testify(BaseBuiltinsFromDSLAssembler::FastJSArrayWitness p_witness, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<JSArray> CastHeapObject20ATFastJSArrayForCopy(compiler::TNode<Context> p_context, compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<JSArray> CastHeapObject34ATFastJSArrayWithNoCustomIteration(compiler::TNode<Context> p_context, compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<JSReceiver> CastHeapObject10JSReceiver(compiler::TNode<Context> p_context, compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<JSFunction> CastHeapObject10JSFunction(compiler::TNode<Context> p_context, compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<Smi> Cast5ATSmi(compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<Smi> Cast13ATPositiveSmi(compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<Number> Cast22UT12ATHeapNumber5ATSmi(compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<Int32T> FromConstexpr7ATint3117ATconstexpr_int31(int31_t p_i);
  compiler::TNode<Int32T> FromConstexpr7ATint3217ATconstexpr_int31(int31_t p_i);
  compiler::TNode<Int32T> FromConstexpr7ATint3217ATconstexpr_int32(int32_t p_i);
  compiler::TNode<IntPtrT> FromConstexpr8ATintptr17ATconstexpr_int31(int31_t p_i);
  compiler::TNode<IntPtrT> FromConstexpr8ATintptr17ATconstexpr_int32(int32_t p_i);
  compiler::TNode<IntPtrT> FromConstexpr8ATintptr18ATconstexpr_intptr(intptr_t p_i);
  compiler::TNode<UintPtrT> FromConstexpr9ATuintptr19ATconstexpr_uintptr(uintptr_t p_i);
  compiler::TNode<Smi> FromConstexpr5ATSmi17ATconstexpr_int31(int31_t p_i);
  compiler::TNode<String> FromConstexpr8ATString18ATconstexpr_string(const char* p_s);
  compiler::TNode<Number> FromConstexpr22UT12ATHeapNumber5ATSmi18ATconstexpr_uint32(uint32_t p_i);
  compiler::TNode<Number> FromConstexpr22UT12ATHeapNumber5ATSmi17ATconstexpr_int32(int32_t p_i);
  compiler::TNode<Number> FromConstexpr22UT12ATHeapNumber5ATSmi19ATconstexpr_float64(double p_f);
  compiler::TNode<Number> FromConstexpr22UT12ATHeapNumber5ATSmi17ATconstexpr_int31(int31_t p_i);
  compiler::TNode<Number> FromConstexpr22UT12ATHeapNumber5ATSmi15ATconstexpr_Smi(Smi p_s);
  compiler::TNode<Smi> FromConstexpr5ATSmi15ATconstexpr_Smi(Smi p_s);
  compiler::TNode<Uint32T> FromConstexpr8ATuint3217ATconstexpr_int31(int31_t p_i);
  compiler::TNode<UintPtrT> FromConstexpr9ATuintptr17ATconstexpr_int31(int31_t p_i);
  compiler::TNode<Float64T> FromConstexpr9ATfloat6417ATconstexpr_int31(int31_t p_i);
  compiler::TNode<BoolT> FromConstexpr6ATbool16ATconstexpr_bool(bool p_b);
  compiler::TNode<Smi> FromConstexpr14ATLanguageMode24ATconstexpr_LanguageMode(LanguageMode p_m);
  compiler::TNode<Int32T> FromConstexpr14ATElementsKind24ATconstexpr_ElementsKind(ElementsKind p_e);
  compiler::TNode<Object> FromConstexpr20UT5ATSmi10HeapObject18ATconstexpr_string(const char* p_s);
  compiler::TNode<IntPtrT> FromConstexpr19ATNativeContextSlot29ATconstexpr_NativeContextSlot(int32_t p_c);
  compiler::TNode<Int32T> Convert7ATint3214ATElementsKind(compiler::TNode<Int32T> p_elementsKind);
  compiler::TNode<Number> Convert22UT12ATHeapNumber5ATSmi7ATint32(compiler::TNode<Int32T> p_i);
  compiler::TNode<IntPtrT> Convert8ATintptr7ATint32(compiler::TNode<Int32T> p_i);
  compiler::TNode<Smi> Convert5ATSmi7ATint32(compiler::TNode<Int32T> p_i);
  compiler::TNode<Number> Convert22UT12ATHeapNumber5ATSmi8ATuint32(compiler::TNode<Uint32T> p_ui);
  compiler::TNode<Smi> Convert5ATSmi8ATuint32(compiler::TNode<Uint32T> p_ui);
  compiler::TNode<UintPtrT> Convert9ATuintptr8ATuint32(compiler::TNode<Uint32T> p_ui);
  compiler::TNode<Int32T> Convert7ATint328ATintptr(compiler::TNode<IntPtrT> p_i);
  compiler::TNode<Smi> Convert5ATSmi8ATintptr(compiler::TNode<IntPtrT> p_i);
  compiler::TNode<Uint32T> Convert8ATuint329ATuintptr(compiler::TNode<UintPtrT> p_ui);
  compiler::TNode<IntPtrT> Convert8ATintptr5ATSmi(compiler::TNode<Smi> p_s);
  compiler::TNode<Int32T> Convert7ATint325ATSmi(compiler::TNode<Smi> p_s);
  compiler::TNode<Float64T> Convert9ATfloat6412ATHeapNumber(compiler::TNode<HeapNumber> p_h);
  compiler::TNode<Float64T> Convert9ATfloat6422UT12ATHeapNumber5ATSmi(compiler::TNode<Number> p_n);
  compiler::TNode<UintPtrT> Convert9ATuintptr22UT12ATHeapNumber5ATSmi(compiler::TNode<Number> p_n);
  compiler::TNode<Float64T> Convert9ATfloat649ATfloat32(compiler::TNode<Float32T> p_f);
  compiler::TNode<Number> Convert22UT12ATHeapNumber5ATSmi9ATfloat64(compiler::TNode<Float64T> p_d);
  compiler::TNode<Float64T> Convert9ATfloat649ATuintptr(compiler::TNode<UintPtrT> p_ui);
  compiler::TNode<Number> Convert22UT12ATHeapNumber5ATSmi9ATuintptr(compiler::TNode<UintPtrT> p_ui);
  compiler::TNode<UintPtrT> Convert9ATuintptr9ATfloat64(compiler::TNode<Float64T> p_d);
  compiler::TNode<UintPtrT> Convert9ATuintptr8ATintptr(compiler::TNode<IntPtrT> p_i);
  compiler::TNode<UintPtrT> Convert9ATuintptr8ATRawPtr(compiler::TNode<RawPtrT> p_r);
  compiler::TNode<IntPtrT> Convert8ATintptr8ATRawPtr(compiler::TNode<RawPtrT> p_r);
  compiler::TNode<BInt> Convert6ATbint7ATint32(compiler::TNode<Int32T> p_v);
  compiler::TNode<BInt> Convert6ATbint8ATintptr(compiler::TNode<IntPtrT> p_v);
  compiler::TNode<BInt> Convert6ATbint5ATSmi(compiler::TNode<Smi> p_v);
  compiler::TNode<Object> UnsafeCast20UT5ATSmi10HeapObject(compiler::TNode<Object> p_o);
  compiler::TNode<Map> kCOWMap();
  compiler::TNode<FixedArrayBase> kEmptyFixedArray();
  void StoreFixedDoubleArrayNumber(compiler::TNode<FixedDoubleArray> p_a, compiler::TNode<Smi> p_index, compiler::TNode<Number> p_value);
  void StoreFixedDoubleArrayElementWithSmiIndex(compiler::TNode<FixedDoubleArray> p_array, compiler::TNode<Smi> p_index, compiler::TNode<Float64T> p_value);
  compiler::TNode<Int32T> AllowDoubleElements(compiler::TNode<Int32T> p_kind);
  compiler::TNode<Int32T> AllowNonNumberElements(compiler::TNode<Int32T> p_kind);
  compiler::TNode<JSFunction> GetObjectFunction(compiler::TNode<Context> p_context);
  compiler::TNode<JSFunction> GetArrayBufferFunction(compiler::TNode<Context> p_context);
  compiler::TNode<Map> GetFastPackedSmiElementsJSArrayMap(compiler::TNode<Context> p_context);
  void TorqueMoveElements(compiler::TNode<FixedArray> p_elements, compiler::TNode<IntPtrT> p_dstIndex, compiler::TNode<IntPtrT> p_srcIndex, compiler::TNode<IntPtrT> p_count);
  void TorqueMoveElements(compiler::TNode<FixedDoubleArray> p_elements, compiler::TNode<IntPtrT> p_dstIndex, compiler::TNode<IntPtrT> p_srcIndex, compiler::TNode<IntPtrT> p_count);
  void TorqueCopyElements(compiler::TNode<FixedArray> p_dstElements, compiler::TNode<IntPtrT> p_dstIndex, compiler::TNode<FixedArray> p_srcElements, compiler::TNode<IntPtrT> p_srcIndex, compiler::TNode<IntPtrT> p_count);
  void TorqueCopyElements(compiler::TNode<FixedDoubleArray> p_dstElements, compiler::TNode<IntPtrT> p_dstIndex, compiler::TNode<FixedDoubleArray> p_srcElements, compiler::TNode<IntPtrT> p_srcIndex, compiler::TNode<IntPtrT> p_count);
  compiler::TNode<Object> LoadElementNoHole12ATFixedArray(compiler::TNode<Context> p_context, compiler::TNode<JSArray> p_a, compiler::TNode<Smi> p_index, compiler::CodeAssemblerLabel* label_IfHole);
  compiler::TNode<Object> LoadElementNoHole18ATFixedDoubleArray(compiler::TNode<Context> p_context, compiler::TNode<JSArray> p_a, compiler::TNode<Smi> p_index, compiler::CodeAssemblerLabel* label_IfHole);
  compiler::TNode<BoolT> NumberIsNaN(compiler::TNode<Number> p_number);
  compiler::TNode<BoolT> ToBoolean(compiler::TNode<Object> p_obj);
  compiler::TNode<Number> ToIndex(compiler::TNode<Object> p_input, compiler::TNode<Context> p_context, compiler::CodeAssemblerLabel* label_RangeError);
  compiler::TNode<Number> GetLengthProperty(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  struct KeyValuePair {
    compiler::TNode<Object> key;
    compiler::TNode<Object> value;

    std::tuple<compiler::TNode<Object>, compiler::TNode<Object>> Flatten() const {
      return std::tuple_cat(std::make_tuple(key), std::make_tuple(value));
    }
  };
  compiler::TNode<BoolT> IsFastJSArray(compiler::TNode<Object> p_o, compiler::TNode<Context> p_context);
  void BranchIfFastJSArray(compiler::TNode<Object> p_o, compiler::TNode<Context> p_context, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);
  void BranchIfNotFastJSArray(compiler::TNode<Object> p_o, compiler::TNode<Context> p_context, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);
  void BranchIfFastJSArrayForCopy(compiler::TNode<Object> p_o, compiler::TNode<Context> p_context, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);
  compiler::TNode<BoolT> IsFastJSArrayWithNoCustomIteration(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<Smi> FromConstexpr11ATFrameType21ATconstexpr_FrameType(StackFrame::Type p_t);
  compiler::TNode<Smi> Cast11ATFrameType(compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<Object> LoadObjectFromFrame(compiler::TNode<RawPtrT> p_f, int32_t p_o);
  compiler::TNode<RawPtrT> LoadPointerFromFrame(compiler::TNode<RawPtrT> p_f, int32_t p_o);
  compiler::TNode<Smi> LoadSmiFromFrame(compiler::TNode<RawPtrT> p_f, int32_t p_o);
  compiler::TNode<JSFunction> LoadFunctionFromFrame(compiler::TNode<RawPtrT> p_f);
  compiler::TNode<RawPtrT> LoadCallerFromFrame(compiler::TNode<RawPtrT> p_f);
  compiler::TNode<Object> Cast25UT9ATContext11ATFrameType(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<Object> LoadContextOrFrameTypeFromFrame(compiler::TNode<Context> p_context, compiler::TNode<RawPtrT> p_f);
  compiler::TNode<Smi> LoadLengthFromAdapterFrame(compiler::TNode<Context> p_context, compiler::TNode<RawPtrT> p_f);
  compiler::TNode<BoolT> FrameTypeEquals(compiler::TNode<Smi> p_f1, compiler::TNode<Smi> p_f2);
  compiler::TNode<RawPtrT> Cast15ATStandardFrame(compiler::TNode<Context> p_context, compiler::TNode<RawPtrT> p_f, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<RawPtrT> Cast23ATArgumentsAdaptorFrame(compiler::TNode<Context> p_context, compiler::TNode<RawPtrT> p_f, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<JSFunction> LoadTargetFromFrame();
  compiler::TNode<JSArray> Cast13ATFastJSArray(compiler::TNode<Context> p_context, compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<JSFunction> UnsafeCast10JSFunction(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<Map> UnsafeCast5ATMap(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<FixedArray> Cast12ATFixedArray(compiler::TNode<Context> p_context, compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<FixedDoubleArray> Cast18ATFixedDoubleArray(compiler::TNode<Context> p_context, compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<JSArray> Cast7JSArray(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<JSArgumentsObjectWithLength> Cast27JSArgumentsObjectWithLength(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<BoolT> Is13ATFastJSArray20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  void BranchIf13ATFastJSArray20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);
  void BranchIfNot13ATFastJSArray20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);
  void BranchIf20ATFastJSArrayForCopy20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);
  compiler::TNode<BoolT> Is34ATFastJSArrayWithNoCustomIteration20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<Context> Cast9ATContext(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<Object> UnsafeCast25UT9ATContext11ATFrameType(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<HeapObject> Cast10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<IntPtrT> Convert8ATintptr17ATconstexpr_int31(int31_t p_i);
  compiler::TNode<JSReceiver> Cast10JSReceiver(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<JSReceiver> Cast41UT9ATJSProxy15JSBoundFunction10JSFunction(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<JSArray> UnsafeCast7JSArray(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<NumberDictionary> UnsafeCast18ATNumberDictionary(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<FixedArray> UnsafeCast12ATFixedArray(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<Smi> UnsafeCast5ATSmi(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<FixedDoubleArray> UnsafeCast18ATFixedDoubleArray(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<JSTypedArray> UnsafeCast14ATJSTypedArray(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<String> Cast8ATString(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<JSArray> Cast7JSArray(compiler::TNode<Context> p_context, compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<HeapObject> UnsafeCast10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<JSReceiver> Cast13ATConstructor(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<JSArray> Cast13ATFastJSArray(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<FixedArray> Cast25ATSloppyArgumentsElements(compiler::TNode<Context> p_context, compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<FixedArray> Cast12ATFixedArray(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<Context> UnsafeCast9ATContext(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<JSArray> Cast20ATFastJSArrayForCopy(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<Smi> Convert5ATSmi17ATconstexpr_int31(int31_t p_i);
  compiler::TNode<JSDataView> Cast12ATJSDataView(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<Map> Cast5ATMap(compiler::TNode<Context> p_context, compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<JSArray> Cast34ATFastJSArrayWithNoCustomIteration(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<BoolT> Is10JSReceiver20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<Map> Cast5ATMap(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<JSTypedArray> Cast14ATJSTypedArray(compiler::TNode<Context> p_context, compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<JSReceiver> Cast10JSReceiver(compiler::TNode<Context> p_context, compiler::TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<HeapNumber> UnsafeCast12ATHeapNumber(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<JSReceiver> UnsafeCast41UT9ATJSProxy15JSBoundFunction10JSFunction(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<JSReceiver> UnsafeCast10JSReceiver(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<JSObject> UnsafeCast8JSObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<Number> UnsafeCast22UT12ATHeapNumber5ATSmi(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<BoolT> Is10JSFunction20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<BoolT> Is5ATMap20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  void BranchIf34ATFastJSArrayWithNoCustomIteration20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);
  compiler::TNode<BoolT> Is25UT9ATContext11ATFrameType20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<BoolT> Is7JSArray20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<BoolT> Is18ATNumberDictionary20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<BoolT> Is12ATFixedArray20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<BoolT> Is5ATSmi20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<BoolT> Is18ATFixedDoubleArray20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<BoolT> Is14ATJSTypedArray20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<BoolT> Is10HeapObject20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<BoolT> Is13ATFastJSArray7JSArray(compiler::TNode<Context> p_context, compiler::TNode<JSArray> p_o);
  compiler::TNode<BoolT> Is9ATContext20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  void BranchIf10JSReceiver20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);
  compiler::TNode<FixedTypedArrayBase> UnsafeCast21ATFixedTypedArrayBase(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<BoolT> Is12ATHeapNumber20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<BoolT> Is41UT9ATJSProxy15JSBoundFunction10JSFunction20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<BoolT> Is8JSObject20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  compiler::TNode<BoolT> Is22UT12ATHeapNumber5ATSmi20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  void BranchIf10JSFunction20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);
  void BranchIf5ATMap20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);
  void BranchIf25UT9ATContext11ATFrameType20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);
  void BranchIf7JSArray20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);
  void BranchIf18ATNumberDictionary20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);
  void BranchIf12ATFixedArray20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);
  void BranchIf5ATSmi20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);
  void BranchIf18ATFixedDoubleArray20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);
  void BranchIf14ATJSTypedArray20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);
  void BranchIf10HeapObject20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);
  void BranchIf13ATFastJSArray7JSArray(compiler::TNode<Context> p_context, compiler::TNode<JSArray> p_o, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);
  void BranchIf9ATContext20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);
  compiler::TNode<BoolT> Is21ATFixedTypedArrayBase20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o);
  void BranchIf12ATHeapNumber20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);
  void BranchIf41UT9ATJSProxy15JSBoundFunction10JSFunction20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);
  void BranchIf8JSObject20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);
  void BranchIf22UT12ATHeapNumber5ATSmi20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);
  compiler::TNode<JSFunction> Cast10JSFunction(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<NumberDictionary> Cast18ATNumberDictionary(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<FixedDoubleArray> Cast18ATFixedDoubleArray(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<JSTypedArray> Cast14ATJSTypedArray(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
  void BranchIf21ATFixedTypedArrayBase20UT5ATSmi10HeapObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_True, compiler::CodeAssemblerLabel* label_False);
  compiler::TNode<HeapNumber> Cast12ATHeapNumber(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<JSObject> Cast8JSObject(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
  compiler::TNode<FixedTypedArrayBase> Cast21ATFixedTypedArrayBase(compiler::TNode<Context> p_context, compiler::TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
 private:
  compiler::CodeAssemblerState* const state_;
  compiler::CodeAssembler ca_;}; 

}  // namespace internal
}  // namespace v8

#endif  // V8_TORQUE_BASE_FROM_DSL_BASE_H__
