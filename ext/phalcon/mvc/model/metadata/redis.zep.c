
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\MetaData\Redis
 *
 * Stores model meta-data in the Redis.
 *
 * By default meta-data is stored for 48 hours (172800 seconds)
 *
 *<code>
 * use Phalcon\Mvc\Model\MetaData\Redis;
 *
 * $metaData = new Redis(
 *     [
 *         "host"       => "127.0.0.1",
 *         "port"       => 6379,
 *         "persistent" => 0,
 *         "lifetime"   => 172800,
 *         "index"      => 2,
 *     ]
 * );
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Redis) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\MetaData, Redis, phalcon, mvc_model_metadata_redis, phalcon_mvc_model_metadata_ce, phalcon_mvc_model_metadata_redis_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_metadata_redis_ce, SL("metaData"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_mvc_model_metadata_redis_ce->create_object = zephir_init_properties_Phalcon_Mvc_Model_MetaData_Redis;
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\MetaData\Redis constructor
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Redis, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *factory, factory_sub, *options_param = NULL, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &factory, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "ph-mm-reds-");
	zephir_array_update_string(&options, SL("prefix"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, 172800);
	zephir_array_update_string(&options, SL("lifetime"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "redis");
	ZEPHIR_CALL_METHOD(&_2, factory, "newinstance", NULL, 0, &_3, &options);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("adapter"), &_2);
	ZEPHIR_MM_RESTORE();

}

/**
 * Flush Redis data and resets internal meta-data in order to regenerate it
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Redis, reset) {

	zval _0;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("adapter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "clear", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_metadata_redis_ce, getThis(), "reset", &_1, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Phalcon_Mvc_Model_MetaData_Redis(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("metaData"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("metaData"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

