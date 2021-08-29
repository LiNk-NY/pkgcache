
#include "pkgcache.h"

#include <R_ext/Rdynload.h>

#define REG(name, args) { #name, (DL_FUNC) name, args }

static const R_CallMethodDef callMethods[]  = {
  REG(pkgcache_read_raw,              1),
  REG(pkgcache_read_description,      1),
  REG(pkgcache_parse_description_raw, 1),
  REG(pkgcache_parse_packages_raw,    1),
  REG(pkgcache_merge_descriptions,    1),
  { NULL, NULL, 0 }
};

void R_init_pkgcache(DllInfo *dll) {
  R_registerRoutines(dll, NULL, callMethods, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE);
}
