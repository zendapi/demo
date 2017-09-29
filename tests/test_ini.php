<?php
if (ini_get("cache_dir") != "/var/cache") {
    goto error;
}
if (ini_get("expire_seconds") != "123") {
    goto error;
}
if (ini_get("enable_log") != "On") {
    goto error;
}
success:
exit(0);
error:
exit(1);
