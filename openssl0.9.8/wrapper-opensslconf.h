#if defined(__sparcv9)
#ifndef OPENSSL_SYSNAME_ULTRASPARC                 
# define OPENSSL_SYSNAME_ULTRASPARC                
#endif   
#endif

#if defined(__sparcv9) || defined(__x86_64)
# include <openssl/opensslconf.64.h>
#else
# include <openssl/opensslconf.32.h>
#endif
