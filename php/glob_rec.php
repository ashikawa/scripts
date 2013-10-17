<?php
$dir   = $argv[1];

/**
 * glob recursion
 */
function glob_rec($pattern, $dir, $flags = 0)
{
    $results = array();

    foreach (glob($dir . "/*", GLOB_ONLYDIR) as $subdir) {
        $results = array_merge(
            $results,
            call_user_func_array(__FUNCTION__, array($pattern, $subdir, $flags))
        );
    }
    return array_merge($results, glob($dir . "/" . $pattern, $flags));
}

$files = glob_rec("*.php", $dir, GLOB_BRACE);
var_dump($files);
