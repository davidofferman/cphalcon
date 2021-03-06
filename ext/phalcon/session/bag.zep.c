
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Session\Bag
 *
 * This component helps to separate session data into "namespaces". Working by
 * this way you can easily create groups of session variables into the
 * application
 *
 * <code>
 * $user = new \Phalcon\Session\Bag("user");
 *
 * $user->name = "Kimbra Johnson";
 * $user->age  = 22;
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Session_Bag) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Session, Bag, phalcon, session_bag, phalcon_collection_ce, phalcon_session_bag_method_entry, 0);

	zend_declare_property_null(phalcon_session_bag_ce, SL("container"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalcon_session_bag_ce, SL("name"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalcon_session_bag_ce, SL("session"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(phalcon_session_bag_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Session\Bag constructor
 */
PHP_METHOD(Phalcon_Session_Bag, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL, *_8 = NULL;
	zval *name_param = NULL, container, data, session, _0, _1$$3, _7$$3, _3$$5, _4$$5, _6$$5;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&session);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_update_property_zval(this_ptr, SL("name"), &name);
	zephir_read_property(&_0, this_ptr, SL("session"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&session, &_0);
	if (Z_TYPE_P(&session) != IS_OBJECT) {
		zephir_read_property(&_1$$3, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&container, &_1$$3);
		if (Z_TYPE_P(&container) != IS_OBJECT) {
			ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_ce, "getdefault", &_2, 0);
			zephir_check_call_status();
			if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
				ZEPHIR_INIT_VAR(&_3$$5);
				object_init_ex(&_3$$5, phalcon_session_exception_ce);
				ZEPHIR_INIT_VAR(&_6$$5);
				ZVAL_STRING(&_6$$5, "the 'session' service");
				ZEPHIR_CALL_CE_STATIC(&_4$$5, phalcon_session_exception_ce, "containerservicenotfound", &_5, 0, &_6$$5);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 1, &_4$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_3$$5, "phalcon/Session/Bag.zep", 60 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_INIT_VAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "session");
		ZEPHIR_CALL_METHOD(&session, &container, "getshared", NULL, 0, &_7$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("session"), &session);
	}
	zephir_read_property(&_0, this_ptr, SL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&data, &session, "get", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&data) != IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&data);
		array_init(&data);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_session_bag_ce, getThis(), "__construct", &_8, 0, &data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Destroys the session bag
 */
PHP_METHOD(Phalcon_Session_Bag, clear) {

	zval _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, phalcon_session_bag_ce, getThis(), "clear", &_0, 0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("session"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, SL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "remove", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the DependencyInjector container
 */
PHP_METHOD(Phalcon_Session_Bag, getDI) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "container");

}

/**
 * Removes a property from the internal bag
 */
PHP_METHOD(Phalcon_Session_Bag, init) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *data_param = NULL;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);

	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);
	}


	ZEPHIR_CALL_PARENT(NULL, phalcon_session_bag_ce, getThis(), "init", &_0, 0, &data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Removes a property from the internal bag
 */
PHP_METHOD(Phalcon_Session_Bag, remove) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_bool insensitive;
	zval *element_param = NULL, *insensitive_param = NULL, _1, _2, _3, _4;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &element_param, &insensitive_param);

	if (UNEXPECTED(Z_TYPE_P(element_param) != IS_STRING && Z_TYPE_P(element_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'element' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(element_param) == IS_STRING)) {
		zephir_get_strval(&element, element_param);
	} else {
		ZEPHIR_INIT_VAR(&element);
		ZVAL_EMPTY_STRING(&element);
	}
	if (!insensitive_param) {
		insensitive = 1;
	} else {
		insensitive = zephir_get_boolval(insensitive_param);
	}


	if (insensitive) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_session_bag_ce, getThis(), "remove", &_0, 0, &element, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("session"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, SL("name"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_2, "set", NULL, 0, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a value in the session bag
 */
PHP_METHOD(Phalcon_Session_Bag, set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *element_param = NULL, *value, value_sub, _1, _2, _3;
	zval element;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &element_param, &value);

	if (UNEXPECTED(Z_TYPE_P(element_param) != IS_STRING && Z_TYPE_P(element_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'element' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(element_param) == IS_STRING)) {
		zephir_get_strval(&element, element_param);
	} else {
		ZEPHIR_INIT_VAR(&element);
		ZVAL_EMPTY_STRING(&element);
	}


	ZEPHIR_CALL_PARENT(NULL, phalcon_session_bag_ce, getThis(), "set", &_0, 0, &element, value);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("session"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, SL("name"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "set", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the DependencyInjector container
 */
PHP_METHOD(Phalcon_Session_Bag, setDI) {

	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	zephir_fetch_params(0, 1, 0, &container);



	zephir_update_property_zval(this_ptr, SL("container"), container);

}

