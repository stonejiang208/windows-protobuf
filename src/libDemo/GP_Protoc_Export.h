
// -*- C++ -*-
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl GP_PROTOC
// ------------------------------
#ifndef GP_PROTOC_EXPORT_H
#define GP_PROTOC_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (GP_PROTOC_HAS_DLL)
#  define GP_PROTOC_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && GP_PROTOC_HAS_DLL */

#if !defined (GP_PROTOC_HAS_DLL)
#  define GP_PROTOC_HAS_DLL 1
#endif /* ! GP_PROTOC_HAS_DLL */

#if defined (GP_PROTOC_HAS_DLL) && (GP_PROTOC_HAS_DLL == 1)
#  if defined (GP_PROTOC_BUILD_DLL)
#    define GP_PROTOC_Export ACE_Proper_Export_Flag
#    define GP_PROTOC_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define GP_PROTOC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* GP_PROTOC_BUILD_DLL */
#    define GP_PROTOC_Export ACE_Proper_Import_Flag
#    define GP_PROTOC_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define GP_PROTOC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* GP_PROTOC_BUILD_DLL */
#else /* GP_PROTOC_HAS_DLL == 1 */
#  define GP_PROTOC_Export
#  define GP_PROTOC_SINGLETON_DECLARATION(T)
#  define GP_PROTOC_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* GP_PROTOC_HAS_DLL == 1 */

// Set GP_PROTOC_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (GP_PROTOC_NTRACE)
#  if (ACE_NTRACE == 1)
#    define GP_PROTOC_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define GP_PROTOC_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !GP_PROTOC_NTRACE */

#if (GP_PROTOC_NTRACE == 1)
#  define GP_PROTOC_TRACE(X)
#else /* (GP_PROTOC_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define GP_PROTOC_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (GP_PROTOC_NTRACE == 1) */

#endif /* GP_PROTOC_EXPORT_H */

// End of auto generated file.
