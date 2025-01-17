// Copyright 2023 The IREE Authors
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#ifndef IREE_COMPILER_GLOBALOPTIMIZATION_UTILS_H_
#define IREE_COMPILER_GLOBALOPTIMIZATION_UTILS_H_

#include <optional>

namespace mlir {
class Type;
class Value;
class CastOpInterface;

namespace iree_compiler {
namespace GlobalOptimization {

// If the producer is a CastOpInterface, or a linalg::GenericOp that performs
// only a CastOpInterface on its input, return the CastOpInterface op.
// Otherwise, return std::nullopt.
//
// **Note: If the CastOpInterface has been generalized, the return Operation
//         is the body CastOpInterface op, not the linalg::GenericOp.
std::optional<CastOpInterface> getDefiningCastOp(Value input);

// Returns the source element type of the defining CastOpInterface of `input`,
// if there is one. Otherwise return std::nullopt.
std::optional<Type> getCastElemType(Value input);

} // namespace GlobalOptimization
} // namespace iree_compiler
} // namespace mlir

#endif // IREE_COMPILER_GLOBALOPTIMIZATION_UTILS_H_
