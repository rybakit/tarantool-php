#ifndef PHP_MSGPACK_H
#define PHP_MSGPACK_H

#define PHP_TARANTOOL_DEBUG

#include <ext/standard/php_smart_str.h>

#define PHP_MP_SERIALIZABLE_PP(v) (Z_TYPE_PP(v) == IS_NULL  || \
				  Z_TYPE_PP(v) == IS_LONG   || \
				  Z_TYPE_PP(v) == IS_DOUBLE || \
				  Z_TYPE_PP(v) == IS_BOOL   || \
				  Z_TYPE_PP(v) == IS_ARRAY  || \
				  Z_TYPE_PP(v) == IS_STRING)

size_t php_mp_check   (const char *str,  size_t str_size);
void   php_mp_pack    (smart_str  *buf,  zval   *val    );
ssize_t php_mp_unpack (zval      **oval, char   **str   );
size_t php_mp_sizeof  (zval *val);

void   php_mp_pack_package_size   (smart_str *str, size_t val);
size_t php_mp_unpack_package_size (char *buf);

int php_mp_is_hash(zval *val);

void php_mp_pack_nil(smart_str *str);
void php_mp_pack_long_pos(smart_str *str, long val);
void php_mp_pack_long_neg(smart_str *str, long val);
void php_mp_pack_long(smart_str *str, long val);
void php_mp_pack_double(smart_str *str, double val);
void php_mp_pack_bool(smart_str *str, unsigned char val);
void php_mp_pack_string(smart_str *str, char *c, size_t len);
void php_mp_pack_hash(smart_str *str, size_t len);
void php_mp_pack_array(smart_str *str, size_t len);
void php_mp_pack_array_recursively(smart_str *str, zval *val);
void php_mp_pack_hash_recursively(smart_str *str, zval *val);

size_t php_mp_sizeof_nil();
size_t php_mp_sizeof_long_pos(long val);
size_t php_mp_sizeof_long_neg(long val);
size_t php_mp_sizeof_long(long val);
size_t php_mp_sizeof_double(double val);
size_t php_mp_sizeof_bool(unsigned char val);
size_t php_mp_sizeof_string(size_t len);
size_t php_mp_sizeof_hash(size_t len);
size_t php_mp_sizeof_array(size_t len);
size_t php_mp_sizeof_array_recursively(zval *val);
size_t php_mp_sizeof_hash_recursively(zval *val);
#endif /* PHP_MSGPACK_H */
