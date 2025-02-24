/**
 * @file mlpack_main.hpp
 * @author Ryan Curtin
 *
 * Define the macros used when compiling a Markdown binding.  This file should
 * not be included directly; instead, mlpack/core/util/mlpack_main.hpp should be
 * included with the right setting of BINDING_TYPE.
 */
#ifndef MLPACK_BINDINGS_MARKDOWN_MLPACK_MAIN_HPP
#define MLPACK_BINDINGS_MARKDOWN_MLPACK_MAIN_HPP

#ifndef BINDING_TYPE
  #error "BINDING_TYPE not defined!  Don't include this file directly!"
#endif
#if BINDING_TYPE != BINDING_TYPE_MARKDOWN
  #error "BINDING_TYPE is not set to BINDING_TYPE_MARKDOWN!"
#endif

// This value doesn't actually matter, but it needs to be defined as something.
#define BINDING_MATRIX_TRANSPOSED true

#include <mlpack/bindings/markdown/md_option.hpp>
#include <mlpack/bindings/markdown/print_doc_functions.hpp>

/**
 * PRINT_PARAM_STRING() returns a string that contains the correct
 * language-specific representation of a parameter's name.
 */
#define PRINT_PARAM_STRING(x) mlpack::bindings::markdown::ParamString( \
    STRINGIFY(BINDING_NAME), x)

/**
 * PRINT_PARAM_VALUE() returns a string that contains a correct
 * language-specific representation of a parameter's value.
 */
#define PRINT_PARAM_VALUE mlpack::bindings::markdown::PrintValue

/**
 * PRINT_DATASET() returns a string that contains a correct language-specific
 * representation of a dataset name.
 */
#define PRINT_DATASET mlpack::bindings::markdown::PrintDataset

/**
 * PRINT_MODEL() returns a string that contains a correct language-specific
 * representation of an mlpack model name.
 */
#define PRINT_MODEL mlpack::bindings::markdown::PrintModel

/**
 * PRINT_CALL() returns a string that contains the full language-specific
 * representation of a call to an mlpack binding.  The first argument should be
 * the name of the binding, and all other arguments should be names of
 * parameters followed by values (in the case where the preceding parameter is
 * not a flag).
 */
#define PRINT_CALL mlpack::bindings::markdown::ProgramCall

/**
 * BINDING_IGNORE_CHECK() is an internally-used macro to determine whether or
 * not a specific parameter check should be ignored.
 */
#define BINDING_IGNORE_CHECK(x) mlpack::bindings::markdown::IgnoreCheck( \
    STRINGIFY(BINDING_NAME), x)

// This doesn't actually matter for this binding type.
#define BINDING_MATRIX_TRANSPOSED true

// This doesn't actually matter for this binding type.
#define BINDING_MIN_LABEL 0

namespace mlpack {
namespace util {

template<typename T>
using Option = mlpack::bindings::markdown::MDOption<T>;

}
}

#include <mlpack/core/util/param.hpp>

// This parameter is available for all languages.
PARAM_GLOBAL(bool, "verbose", "Display informational messages and the full "
    "list of parameters and timers at the end of execution.", "v", "bool",
    false, true, false, false);

// CLI-specific parameters.
PARAM_GLOBAL(bool, "help", "Default help info.", "h", "bool", false, true,
    false, false);
PARAM_GLOBAL(std::string, "info", "Print help on a specific option.", "",
    "std::string", false, true, false, "");
PARAM_GLOBAL(bool, "version", "Display the version of mlpack.", "V", "bool",
    false, true, false, false);

// Python-specific parameters.
PARAM_GLOBAL(bool, "copy_all_inputs", "If specified, all input parameters will "
    "be deep copied before the method is run.  This is useful for debugging "
    "problems where the input parameters are being modified by the algorithm, "
    "but can slow down the code.", "", "bool", false, true, false, false);
PARAM_GLOBAL(bool, "check_input_matrices", "If specified, the input matrix "
    "is checked for NaN and inf values; an exception is thrown if any are "
    "found.", "", "bool", false, true, false, false);

#endif
