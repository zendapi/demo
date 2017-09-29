<?php

if (class_exists("\Person")) {
    $person = new Person("xiaoming", 22, "beijing");
    if (method_exists($person, "getName")) {
        if ($person->getName() != "xiaoming") {
            goto error;
        }
    } else {
        goto error;
    }
    if (method_exists($person, "getAge")) {
        if ($person->getAge() != 22) {
            goto error;
        }
    } else {
        goto error;
    }
    if (method_exists($person, "getAddress")) {
        if ($person->getAddress() != "beijing") {
            goto error;
        }
    } else {
        goto error;
    }
    
    if (method_exists($person, "setName")) {
        $person->setName("xiaohong");
        if ($person->getName() != "xiaohong") {
            goto error;
        }
    } else {
        goto error;
    }
    if (method_exists($person, "setAge")) {
        $person->setAge(30);
        if ($person->getAge() != 30) {
            goto error;
        }
    } else {
        goto error;
    }
    if (method_exists($person, "setAddress")) {
        $person->setAddress("shanghai");
        if ($person->getAddress() != "shanghai") {
            goto error;
        }
    } else {
        goto error;
    }
} else {
    goto error;
}
success:
exit(0);
error:
exit(1);
