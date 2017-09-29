<?php

if (function_exists("print_project_name")) {
    ob_start();
    print_project_name("hello,");
    $content = trim(ob_get_clean());
    if ($content != "hello, hellozapi") {
        goto error;
    }
} else {
    goto error;
}

if (function_exists("print_develop_team")) {
    ob_start();
    print_develop_team();
    $content = trim(ob_get_clean());
    if ($content != "qcoreteam") {
        goto error;
    }
} else {
    goto error;
}

if (function_exists("get_version")) {
    $content = get_version();
    if ($content != "v1.0.2") {
        goto error;
    }
} else {
    goto error;
}

if (function_exists("add_two_num")) {
    $content = add_two_num(1, 3);
    if ($content != 4) {
        goto error;
    }
} else {
    goto error;
}

success:
exit(0);
error:
exit(1);
