// Copyright 2017 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "src/builtins/builtins-utils-inl.h"
#include "src/builtins/builtins.h"
#include "src/conversions.h"
#include "src/counters.h"
#include "src/objects-inl.h"
#ifdef V8_INTL_SUPPORT
#include "src/objects/intl-objects.h"
#endif

namespace v8 {
namespace internal {

BUILTIN(BigIntConstructor) {
  HandleScope scope(isolate);
  if (!args.new_target()->IsUndefined(isolate)) {  // [[Construct]]
    THROW_NEW_ERROR_RETURN_FAILURE(
        isolate, NewTypeError(MessageTemplate::kNotConstructor,
                              isolate->factory()->BigInt_string()));
  }
  // [[Call]]
  Handle<Object> value = args.atOrUndefined(isolate, 1);

  if (value->IsJSReceiver()) {
    ASSIGN_RETURN_FAILURE_ON_EXCEPTION(
        isolate, value,
        JSReceiver::ToPrimitive(Handle<JSReceiver>::cast(value),
                                ToPrimitiveHint::kNumber));
  }

  if (value->IsNumber()) {
    RETURN_RESULT_OR_FAILURE(isolate, BigInt::FromNumber(isolate, value));
  } else {
    RETURN_RESULT_OR_FAILURE(isolate, BigInt::FromObject(isolate, value));
  }
}

BUILTIN(BigIntAsUintN) {
  HandleScope scope(isolate);
  Handle<Object> bits_obj = args.atOrUndefined(isolate, 1);
  Handle<Object> bigint_obj = args.atOrUndefined(isolate, 2);

  Handle<Object> bits;
  ASSIGN_RETURN_FAILURE_ON_EXCEPTION(
      isolate, bits,
      Object::ToIndex(isolate, bits_obj, MessageTemplate::kInvalidIndex));

  Handle<BigInt> bigint;
  ASSIGN_RETURN_FAILURE_ON_EXCEPTION(isolate, bigint,
                                     BigInt::FromObject(isolate, bigint_obj));

  RETURN_RESULT_OR_FAILURE(isolate,
                           BigInt::AsUintN(isolate, bits->Number(), bigint));
}

BUILTIN(BigIntAsIntN) {
  HandleScope scope(isolate);
  Handle<Object> bits_obj = args.atOrUndefined(isolate, 1);
  Handle<Object> bigint_obj = args.atOrUndefined(isolate, 2);

  Handle<Object> bits;
  ASSIGN_RETURN_FAILURE_ON_EXCEPTION(
      isolate, bits,
      Object::ToIndex(isolate, bits_obj, MessageTemplate::kInvalidIndex));

  Handle<BigInt> bigint;
  ASSIGN_RETURN_FAILURE_ON_EXCEPTION(isolate, bigint,
                                     BigInt::FromObject(isolate, bigint_obj));

  return *BigInt::AsIntN(isolate, bits->Number(), bigint);
}

namespace {

MaybeHandle<BigInt> ThisBigIntValue(Isolate* isolate, Handle<Object> value,
                                    const char* caller) {
  // 1. If Type(value) is BigInt, return value.
  if (value->IsBigInt()) return Handle<BigInt>::cast(value);
  // 2. If Type(value) is Object and value has a [[BigIntData]] internal slot:
  if (value->IsJSValue()) {
    // 2a. Assert: value.[[BigIntData]] is a BigInt value.
    // 2b. Return value.[[BigIntData]].
    Object data = JSValue::cast(*value)->value();
    if (data->IsBigInt()) return handle(BigInt::cast(data), isolate);
  }
  // 3. Throw a TypeError exception.
  THROW_NEW_ERROR(
      isolate,
      NewTypeError(MessageTemplate::kNotGeneric,
                   isolate->factory()->NewStringFromAsciiChecked(caller),
                   isolate->factory()->NewStringFromStaticChars("BigInt")),
      BigInt);
}

Object BigIntToStringImpl(Handle<Object> receiver, Handle<Object> radix,
                          Isolate* isolate, const char* builtin_name) {
  // 1. Let x be ? thisBigIntValue(this value).
  Handle<BigInt> x;
  ASSIGN_RETURN_FAILURE_ON_EXCEPTION(
      isolate, x, ThisBigIntValue(isolate, receiver, builtin_name));
  // 2. If radix is not present, let radixNumber be 10.
  // 3. Else if radix is undefined, let radixNumber be 10.
  int radix_number = 10;
  if (!radix->IsUndefined(isolate)) {
    // 4. Else, let radixNumber be ? ToInteger(radix).
    ASSIGN_RETURN_FAILURE_ON_EXCEPTION(isolate, radix,
                                       Object::ToInteger(isolate, radix));
    double radix_double = radix->Number();
    // 5. If radixNumber < 2 or radixNumber > 36, throw a RangeError exception.
    if (radix_double < 2 || radix_double > 36) {
      THROW_NEW_ERROR_RETURN_FAILURE(
          isolate, NewRangeError(MessageTemplate::kToRadixFormatRange));
    }
    radix_number = static_cast<int>(radix_double);
  }
  // Return the String representation of this Number value using the radix
  // specified by radixNumber.
  RETURN_RESULT_OR_FAILURE(isolate, BigInt::ToString(isolate, x, radix_number));
}

}  // namespace

BUILTIN(BigIntPrototypeToLocaleString) {
  HandleScope scope(isolate);
#ifdef V8_INTL_SUPPORT
  if (FLAG_harmony_intl_bigint) {
    RETURN_RESULT_OR_FAILURE(
        isolate, Intl::NumberToLocaleString(isolate, args.receiver(),
                                            args.atOrUndefined(isolate, 1),
                                            args.atOrUndefined(isolate, 2)));
  }
  // Fallbacks to old toString implemention if flag is off or no
  // V8_INTL_SUPPORT
#endif  // V8_INTL_SUPPORT
  Handle<Object> radix = isolate->factory()->undefined_value();
  return BigIntToStringImpl(args.receiver(), radix, isolate,
                            "BigInt.prototype.toLocaleString");
}

BUILTIN(BigIntPrototypeToString) {
  HandleScope scope(isolate);
  Handle<Object> radix = args.atOrUndefined(isolate, 1);
  return BigIntToStringImpl(args.receiver(), radix, isolate,
                            "BigInt.prototype.toString");
}

BUILTIN(BigIntPrototypeValueOf) {
  HandleScope scope(isolate);
  RETURN_RESULT_OR_FAILURE(
      isolate,
      ThisBigIntValue(isolate, args.receiver(), "BigInt.prototype.valueOf"));
}

}  // namespace internal
}  // namespace v8
