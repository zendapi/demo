<?php
if (!defined("\hellozapi\DEVEL_TEAM") || \hellozapi\DEVEL_TEAM != "qcoreteam") {
    goto error;
}
if (!defined("\hellozapi\RELEASE_ADDRESS") || \hellozapi\RELEASE_ADDRESS != "beijing") {
    goto error;
}

if (function_exists("\hellozapi\print_project_name")) {
    ob_start();
    \hellozapi\print_project_name("hello,");
    $content = trim(ob_get_clean());
    if ($content != "hello, hellozapi") {
        goto error;
    }
} else {
    goto error;
}

if (function_exists("\hellozapi\print_develop_team")) {
    ob_start();
    \hellozapi\print_develop_team();
    $content = trim(ob_get_clean());
    if ($content != "qcoreteam") {
        goto error;
    }
} else {
    goto error;
}

if (function_exists("\hellozapi\get_version")) {
    $content = \hellozapi\get_version();
    if ($content != "v1.0.2") {
        goto error;
    }
} else {
    goto error;
}

if (function_exists("\hellozapi\add_two_num")) {
    $content = \hellozapi\add_two_num(1, 3);
    if ($content != 4) {
        goto error;
    }
} else {
    goto error;
}

if (!defined("\hellozapi\kernel\KERNEL_VERSION") || \hellozapi\kernel\KERNEL_VERSION != "v0.0.1") {
    goto error;
}

if (function_exists("\hellozapi\kernel\print_develop_team")) {
    ob_start();
    \hellozapi\kernel\print_develop_team();
    $content = trim(ob_get_clean());
    if ($content != "qcoreteam") {
        goto error;
    }
} else {
    goto error;
}

success:
exit(0);
error:
exit(1);
