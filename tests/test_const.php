<?php
try {
    $isOk = true;
    if (!defined("HELLO_ZAPI_VERSION") || \HELLO_ZAPI_VERSION != 0x010002) {
        $isOk = false;
    }
    if (!defined("HELLO_ZAPI_NAME") || \HELLO_ZAPI_NAME != "Hello zendAPI!") {
        $isOk = false;
    }
    if (!defined("HELLO_DEBUG_MODE") || \HELLO_DEBUG_MODE != true) {
        $isOk = false;
    }
    if (!defined("HELLO_ZAPI_PI") || \HELLO_ZAPI_PI != 3.14) {
        $isOk = false;
    }
    if (!$isOk) {
        throw new \Exception("error");
    }
    exit(0);
} catch (\Exception $ex) {
    exit(1);
}
